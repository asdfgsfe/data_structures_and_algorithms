#include <iostream>

struct TreeNode
{
  int val;
  TreeNode* left;
  TreeNode* right;
  TreeNode* parent;
  TreeNode(int v)
    : val(v), left(nullptr), right(nullptr), parent(nullptr)
  {}
};

const TreeNode* SuccessorNode(const TreeNode* pNode)
{
  if (!pNode)
  {
    return nullptr;
  }
  if (pNode->right)
  {
    pNode = pNode->right;
    while (pNode && pNode->left)
    {
      pNode = pNode->left;
    }
    return pNode;
  }
  else
  {
    const TreeNode* pParent = pNode->parent;
    while (pParent && pParent->left != pNode)
    {
      pNode = pParent;
      pParent = pNode->parent;
    }
    return pParent;
  }
}

const TreeNode* PrecursorNode(const TreeNode* pNode)
{
  if (!pNode)
  {
    return nullptr;
  }
  if (pNode->left)
  {
    pNode = pNode->left;
    while (pNode && pNode->right)
    {
      pNode = pNode->right;
    }
    return pNode;
  }
  else
  {
    const TreeNode* pParent = pNode->parent;
    while (pParent && pParent->right != pNode)
    {
      pNode = pParent;
      pParent = pNode->parent;
    }
    return pParent;
  }
}

int main(void)
{
  TreeNode* head = new TreeNode(6);
  head->parent = nullptr;
  head->left = new TreeNode(3);
  head->left->parent = head;
  head->left->left = new TreeNode(1);
  head->left->left->parent = head->left;
  head->left->left->right = new TreeNode(2);
  head->left->left->right->parent = head->left->left;
  head->left->right = new TreeNode(4);
  head->left->right->parent = head->left;
  head->left->right->right = new TreeNode(5);
  head->left->right->right->parent = head->left->right;
  head->right = new TreeNode(9);
  head->right->parent = head;
  head->right->left = new TreeNode(8);
  head->right->left->parent = head->right;
  head->right->left->left = new TreeNode(7);
  head->right->left->left->parent = head->right->left;
  head->right->right = new TreeNode(10);
  head->right->right->parent = head->right;
  TreeNode* test = head->left->left;
  std::cout << test->val << " next: " <<  SuccessorNode(test)->val << std::endl;
  test = head->left->left->right;
  std::cout << test->val << " next: " << SuccessorNode(test)->val << std::endl;
  test = head->left;
  std::cout << test->val << " next: " << SuccessorNode(test)->val << std::endl;
  test = head->left->right;
  std::cout << test->val << " next: " << SuccessorNode(test)->val << std::endl;
  test = head->left->right->right;
  std::cout << test->val << " next: " << SuccessorNode(test)->val << std::endl;
  test = head;
  std::cout << test->val << " next: " << SuccessorNode(test)->val << std::endl;
  test = head->right->left->left;
  std::cout << test->val << " next: " << SuccessorNode(test)->val << std::endl;
  test = head->right->left;
  std::cout << test->val << " next: " << SuccessorNode(test)->val << std::endl;
  test = head->right;
  std::cout << test->val << " next: " << SuccessorNode(test)->val << std::endl;
  test = head->right->right; // 10's next is null
  //std::cout << test->val + " next: " + std::string(SuccessorNode(test)) << std::endl;

  return 0;
}
