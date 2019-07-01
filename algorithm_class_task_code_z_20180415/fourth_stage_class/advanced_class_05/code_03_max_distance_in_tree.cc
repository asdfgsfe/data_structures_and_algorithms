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
  int maxDistance;
  int h;

  ReturnData(int md, int height)
    : maxDistance(md), h(height)
  {}
};

ReturnData Process(const TreeNode* pNode)
{
  if (pNode == nullptr)
  {
    return ReturnData(0, 0);
  }
  ReturnData leftInfo = Process(pNode->left);
  ReturnData rightInfo = Process(pNode->right);
  int includeItDistance = leftInfo.h + rightInfo.h + 1;
  int maxDistance = std::max(std::max(leftInfo.maxDistance, rightInfo.maxDistance), includeItDistance);
  int currHeight = std::max(leftInfo.h, rightInfo.h) + 1;
  return ReturnData(maxDistance, currHeight);
}

int MaxDistance(const TreeNode* pRoot)
{
  if (pRoot == nullptr)
  {
    return 0;
  }
  return Process(pRoot).maxDistance;
}

int PosOrder(const TreeNode* pNode, int* height)
{
  if (pNode == nullptr)
  {
    *height = 0;
    return 0;
  }
  int lMax = PosOrder(pNode->left, height);
  int lH = *height;
  int rMax = PosOrder(pNode->right, height);
  int rH = *height;
  int includeItDistance = lH + rH + 1;
  *height = std::max(lH, rH) + 1;
  return std::max(std::max(rMax, rMax), includeItDistance);;
}

int MaxDistance2(const TreeNode* pRoot)
{
  if (pRoot == nullptr)
  {
    return 0;
  }
  int record = 0;
  return PosOrder(pRoot, &record);
}

int main(void)
{
  TreeNode* head1 = new TreeNode(1);
  head1->left = new TreeNode(2);
  head1->right = new TreeNode(3);
  head1->left->left = new TreeNode(4);
  head1->left->right = new TreeNode(5);
  head1->right->left = new TreeNode(6);
  head1->right->right = new TreeNode(7);
  head1->left->left->left = new TreeNode(8);
  head1->right->left->right = new TreeNode(9);
  std::cout << MaxDistance(head1) << std::endl;
  std::cout << MaxDistance2(head1) << std::endl;

  TreeNode* head2 = new TreeNode(1);
  head2->left = new TreeNode(2);
  head2->right = new TreeNode(3);
  head2->right->left = new TreeNode(4);
  head2->right->right = new TreeNode(5);
  head2->right->left->left = new TreeNode(6);
  head2->right->right->right = new TreeNode(7);
  head2->right->left->left->left = new TreeNode(8);
  head2->right->right->right->right = new TreeNode(9);
  std::cout << MaxDistance(head2) << std::endl;
  std::cout << MaxDistance2(head2) << std::endl;

  return 0;
}
