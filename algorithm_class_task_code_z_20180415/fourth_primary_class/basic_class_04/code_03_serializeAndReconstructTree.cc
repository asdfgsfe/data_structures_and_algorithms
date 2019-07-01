#include <iostream>
#include <string>

using std::string;

struct TreeNode
{
  int val;
  TreeNode* left;
  TreeNode* right;
  TreeNode(int v)
    : val(v), left(nullptr), right(nullptr)
  {}
};

string PreSerializeTree(const TreeNode* pRoot)
{
  if (!pRoot)
  {
    return "#!"
  }
  string val = std::string(pRoot->val) + "!";
  val += PreSerializeTree(pRoot->left);
  val += PreSerializeTree(pRoot->right);
  return val;
}

TreeNode* PreReconstructTree(const string& str)
{
  for (char ch : str)
  {
    if (ch == '#')
    {
      return nullptr;
    }
    if (ch == '!')
    {
      continue;
    }
    TreeNode* pNode = new TreeNode(::atoi());
  }
}

