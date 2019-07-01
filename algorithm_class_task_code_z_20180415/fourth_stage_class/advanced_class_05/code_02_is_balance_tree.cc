#include <iostream>

struct TreeNode
{
  int val;
  TreeNode* left;
  TreeNode* right;

  TreeNode(int v)
    : val(v), left(nullptr), right(nullptr)
  {}
};

struct ReturnData
{
  bool isB;
  int h;

  ReturnData(bool balance, int height)
    : isB(balance), h(height)
  {}
};

ReturnData Process(const TreeNode* pRoot)
{
  if (pRoot == nullptr)
  {
    return ReturnData(true, 0);
  }
  ReturnData leftInfo = Process(pRoot->left);
  if (!leftInfo.isB)
  {
    return ReturnData(false, 0);
  }
  ReturnData rightInfo = Process(pRoot->right);
  if (!rightInfo.isB)
  {
    return ReturnData(false, 0);
  }
  if (::abs(leftInfo.h - rightInfo.h) > 1)
  {
    return ReturnData(false, 0);
  }
  return ReturnData(true, std::max(leftInfo.h, rightInfo.h) + 1);
}

bool IsBalanceTree(const TreeNode* pRoot)
{
  if (pRoot == nullptr)
  {
    return true;
  }
  return Process(pRoot).isB;
}

int Height(const TreeNode* pRoot, int level, bool* isB)
{
  if (pRoot == nullptr)
  {
    return level;
  }
  int lH = Height(pRoot->left, level + 1, isB);
  if (!(*isB))
  {
    return level;
  }
  int rH = Height(pRoot->right, level + 1, isB);
  if (!(*isB))
  {
    return level;
  }
  if (::abs(lH - rH) > 1)
  {
    *isB = false;
  }
  return std::max(lH, rH) + 1;
}

int IsBalanceTree2(const TreeNode* pRoot)
{
  bool isB = true;
  Height(pRoot, 1, &isB);
  return isB;
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
  std::cout << IsBalanceTree(head) << std::endl;
  std::cout << IsBalanceTree2(head) << std::endl;

  TreeNode* head2 = new TreeNode(1);
  head2->left = new TreeNode(2);                  
  head2->right = new TreeNode(3);                    
  head2->right->left = new TreeNode(4);             
  head2->right->right = new TreeNode(5);             
  head2->right->left->left = new TreeNode(6);        
  head2->right->right->right = new TreeNode(7);      
  head2->right->left->left->left = new TreeNode(8);  
  head2->right->right->right->right = new TreeNode(9);
  std::cout << IsBalanceTree(head2) << std::endl;
  std::cout << IsBalanceTree2(head2) << std::endl;

  return 0;
}
