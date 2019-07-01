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

struct ReturnType
{
  int maxDistance;
  int height;
  
  ReturnType(int m, int h)
    : maxDistance(m), height(h)
  {}
};

ReturnType Process(TreeNode* pNode)
{
  if (pNode == nullptr)
  {
    return ReturnType(0, 0);
  }
  ReturnType leftSubTreeInfo = Process(pNode->left);
  ReturnType rightSubTreeInfo = Process(pNode->right);
  int includeSelfDistance = leftSubTreeInfo.height + 1 + rightSubTreeInfo.height;
  int ld = leftSubTreeInfo.maxDistance;
  int rd = rightSubTreeInfo.maxDistance;
  int resultDistance = std::max(std::max(ld, rd), includeSelfDistance);
  int hitSelftHeight = std::max(leftSubTreeInfo.height, rightSubTreeInfo.height) + 1;
  return ReturnType(resultDistance, hitSelftHeight);
}

int MaxDistance1(TreeNode* pRoot)
{
  if (pRoot == nullptr)
  {
    return 0;
  }
  return Process(pRoot).maxDistance;
}

int PosOrder(TreeNode* pNode, int* record)
{
  if (pNode == nullptr)
  {
    *record = 0;
    return 0;
  }
  int ldm = PosOrder(pNode->left, record);
  int lh = *record;
  int rdm = PosOrder(pNode->right, record);
  int rh = *record;
  *record = std::max(lh, rh) + 1;
  return std::max(std::max(ldm, rdm), lh + 1 + rh);
}

int MaxDistance2(TreeNode* pRoot)
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
  std::cout << MaxDistance1(head1) << std::endl;
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
  std::cout << MaxDistance1(head2) << std::endl;
  std::cout << MaxDistance2(head2) << std::endl;


  return 0;
}
