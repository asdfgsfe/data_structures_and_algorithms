#include <iostream>
#include <vector>
#include <string>

using std::vector;
using std::string;

struct TrieNode
{
  int path;
  int end;
  vector<TrieNode*> nexts;

  TrieNode()
    : path(0), end(0),nexts(vector<TrieNode*>(26, nullptr))
  {}
};

class TrieTree
{
public:
  TrieTree()
    : pRoot_(new TrieNode())
  {
  }

  void Insert(const string& word)
  {
    if (word.empty())
    {
      return;
    }
    TrieNode* pNode = pRoot_;
    for (char ch : word)
    {
      int id = ch - 'a';
      if (!pNode->nexts[id])
      {
        pNode->nexts[id] = new TrieNode();
      }
      pNode = pNode->nexts[id];
      ++pNode->path;
    }
    ++pNode->end;
  }

  int Search(const string& word)
  {
    if (word.empty())
    {
      return 0;
    }
    const TrieNode* pNode = pRoot_;
    for (char ch : word)
    {
      int id = ch - 'a';
      if (!pNode->nexts[id])
      {
        return 0;
      }
      pNode = pNode->nexts[id];
    }
    return pNode->end;
  }

  void Delete(const string& word)
  {
    if (word.empty())
    {
      return;
    }
    if (Search(word) != 0)
    {
      TrieNode* pNode = pRoot_;
      for (char ch : word)
      {
        int id = ch - 'a';
        if (--pNode->nexts[id]->path == 0)
        {
          delete pNode->nexts[id];
	  pNode->nexts[id] = nullptr;
          return;
        }
        pNode = pNode->nexts[id];
      }
      --pNode->end;
    }
  }

  int PrefixNumber(const string& pre)
  {
    if (pre.empty())
    {
      return 0;
    }
    const TrieNode* pNode = pRoot_;
    for (char ch : pre)
    {
      int id = ch - 'a';
      if (pNode->nexts[id]->path == 0)
      {
        return 0;
      }
      pNode = pNode->nexts[id];
    }
    return pNode->path;
  }

private:
  TrieNode* pRoot_;
};

int main(void)
{
  TrieTree* trie = new TrieTree();
  std::cout << trie->Search("zuo") << std::endl; //0
  trie->Insert("zuo");
  std::cout << trie->Search("zuo") << std::endl; //1
  trie->Delete("zuo");
  std::cout << trie->Search("zuo") << std::endl; //0
  trie->Insert("zuo");
  trie->Insert("zuo");
  trie->Delete("zuo");
  std::cout << trie->Search("zuo") << std::endl;//1
  trie->Delete("zuo");
  std::cout << trie->Search("zuo") << std::endl;//0
  trie->Insert("zuoa");
  trie->Insert("zuoac");
  trie->Insert("zuoab");
  trie->Insert("zuoad");
  trie->Delete("zuoa");
  std::cout << trie->Search("zuoa") << std::endl;//0
  std::cout << trie->PrefixNumber("zuo") << std::endl;//3

  return 0;
}
