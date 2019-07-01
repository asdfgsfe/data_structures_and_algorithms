#include <cmath>
#include <iostream>

struct TreeNode
{
  int val;
  TreeNode* left;
  TreeNode* right;

  TreeNode(int value) 
    : val(value), left(nullptr), right(nullptr)
  {}
};

struct ReturnType
{
  int level;
  bool isBalanced;

  ReturnType(int l, bool isB)
    : level(l), isBalanced(isB)
  {}
};

ReturnType Process(TreeNode* pNode, int level)
{
  if (pNode == nullptr)
  {
    return ReturnType(level, true);
  }
  ReturnType leftSubTreeInfo = Process(pNode->left, level + 1);
  if (!leftSubTreeInfo.isBalanced)
  {
    return ReturnType(level, false);
  }
  ReturnType rightSubTreeInfo = Process(pNode->right, level + 1);
  if (!rightSubTreeInfo.isBalanced)
  {
    return ReturnType(level, false);
  }
  if (::abs(leftSubTreeInfo.level - rightSubTreeInfo.level) > 1)
  {
    return ReturnType(level, false);
  }
  return ReturnType(std::max(leftSubTreeInfo.level, rightSubTreeInfo.level), true);
}

bool IsBalancedTree1(TreeNode* pRoot)
{
  if (pRoot == nullptr)
  {
    return true;
  }
  return Process(pRoot, 1).isBalanced;
}

int TreeHeight(TreeNode* pNode, int level, bool* res)
{
  if (pNode == nullptr)
  {
    return level;
  }
  int lh = TreeHeight(pNode->left, level + 1, res);
  if (!(*res))
  {
    return level;
  }
  int rh = TreeHeight(pNode->right, level + 1, res);
  if (!(*res))
  {
    return level;
  }
  if (::abs(lh - rh) > 1)
  {
    *res = false;
  }
  return std::max(lh, rh);
}

bool IsBalancedTree2(TreeNode* pRoot)
{
  if (pRoot == nullptr)
  {
    return true;
  }
  bool res = true;
  TreeHeight(pRoot, 1, &res);
  return res;
}

int main(void)
{
  TreeNode* head = new TreeNode(1);
  head->left = new TreeNode(2);
  head->right = new TreeNode(3);
  head->left->left = new TreeNode(4);
  head->left->right = new TreeNode(5);
  head->right->left = new TreeNode(6);
  head->right->right = new TreeNode(7);
  std::cout << IsBalancedTree1(head) << std::endl;
  std::cout << IsBalancedTree2(head) << std::endl;

  return 0;
}
