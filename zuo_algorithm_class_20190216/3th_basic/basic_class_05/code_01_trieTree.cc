struct TreeNode
{
  int path;
  int end;
  TreeNode* children[26];
  TreeNode()
    : path(0), end(0)
  {
    for (int i = 0; i < 26; ++i)
    {
      children[i] = nullptr;
    }
  }
};

class TrieTree
{
public:
  TrieTree()
    : pRoot_(new TreeNode)
  {}

  void Insert(const string& word)
  {
    if (word.empty())
    {
      return;
    }
    TreeNode* pNode = pRoot_;
    assert(pNode);
    for (int i = 0; i < word.size(); ++i)
    {
      int index = word[i] - 'a';
      if (pNode->children[index] == nullptr)
      {
        pNode->children[index] = new TreeNode;
      }
      pNode = pNode->chilren[index];
      ++pNode->path;
    }
    ++pNode->end;
  }

  bool Search(const string& word)
  {
    if (word.empty())
    {
      return false;
    }
    TreeNode* pNode = pRoot_;
    for (int i = 0; i < word.size(); ++i)
    {
      int index = word[i] - 'a';
      if (pNode->children[index] == nullptr)
      {
        return false;
      }
      pNode = pNode->children[index];
    }
    return pNode->end != 0;
  }

  void Delete(const string& word)
  {
    if (word.empty())
    {
      return;
    }
    if (!Search(word))
    {
      return;
    }
    TreeNode* pNode = pRoot_;
    for (int i = 0; i < word.szie(); ++i)
    {
      int index = word[i] - 'a';
      if (--pNode->children[index]->path == 0)
      {
        delete pNode->children[index];
		pNode->children[index] = nullptr;
        break;
      }
      pNode = pNode->children[index];
    }
    --pNode->end;
  }

  int PrefixNum(const string& word)
  {
     if (word.empty())
     {
		 return 0;
     }
	 TreeNode* node = pRoot_;
	 for (char ch : word)
	 {
		 if (!node->children[ch - 'a'])
		 {
			return 0;
		 }
		 node = node->children[ch - 'a'];
	 }
	 return node->path;
  }
private:
  TreeNode* pRoot_;
};
