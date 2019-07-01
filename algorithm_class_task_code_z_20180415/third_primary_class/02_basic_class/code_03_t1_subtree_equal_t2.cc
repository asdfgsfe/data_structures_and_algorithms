#include <iostream>
#include <string>
#include <vector>

using std::vector;
using std::string;

struct Tree
{
  int val;
  Tree* left;
  Tree* right;
  Tree(int v) : val(v), left(nullptr), right(nullptr)
  {}
};

string SerializeByPre(const Tree* pRoot)
{
  if (pRoot == nullptr)
  {
    return string("#!");  
  }
  string str = std::to_string(pRoot->val) + "!";
  str += SerializeByPre(pRoot->left);
  str += SerializeByPre(pRoot->right);
  return str;
}

vector<int> GetNextArray(const string& str)
{
  if (str.empty() || str.size() == 1)
  {
    return vector<int>(1, -1);
  }
  vector<int> next(str.size());
  next[0] = -1;
  next[1] = 0;
  int pos = 2;
  int cn = 0;
  while (pos < next.size())
  {
    if (str[pos-1] == str[cn])
    {
      next[pos++] = ++cn;
    }
    else if (cn > 0)
    {
      cn = next[cn];
    }
    else
    {
      next[pos++] = 0;
    }
  }
  return next;
}

int GetIndexOf(const string& str, const string& match)
{
  if (str.empty() || match.empty())
  {
    return -1;
  }
  vector<int> next = GetNextArray(match);
  int i = 0;
  int j = 0;
  while (i < str.size() && j < match.size())
  {
    if (str[i] == match[j])
    {
      ++i;
      ++j;
    }
    else if (next[j] == -1)
    {
      ++i;
    }
    else
    {
      j = next[j];
    }
  }
  return j == match.size() ? i - j : -1;
}

bool IsSubTree(const Tree* pRoot1, const Tree* pRoot2)
{
  if (pRoot1 == nullptr && pRoot2 != nullptr)
  {
    return false;
  }
  if (pRoot1 == nullptr || pRoot2 == nullptr)
  {
    return true;
  }
  string s1 = SerializeByPre(pRoot1);
  string s2 = SerializeByPre(pRoot2);
  return GetIndexOf(s1, s2) != -1;
}

int main(void)
{
  Tree* t1 = new Tree(1);
  t1->left = new Tree(2);
  t1->right = new Tree(3);
  t1->left->left = new Tree(4);
  t1->left->right = new Tree(5);
  t1->right->left = new Tree(6);
  t1->right->right = new Tree(7);
  t1->left->left->right = new Tree(8);
  t1->left->right->left = new Tree(9);

  Tree* t2 = new Tree(2);
  t2->left = new Tree(4);
  t2->left->right = new Tree(8);
  t2->right = new Tree(5);
  t2->right->left = new Tree(9);

  std::cout << IsSubTree(t1, t2) << std::endl;

  return 0;
}
