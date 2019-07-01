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

string Space(int num)
{
  string str;
  for (int i = 0; i < num; ++i)
  {
    str += " ";
  }
  return str;
}

void PrintInOrder(const TreeNode* pRoot, int height, string to, int len)
{
  if (pRoot == nullptr)
  {
    return;
  }
  PrintInOrder(pRoot->left, height + 1, "V", len);
  string val = to + std::to_string(pRoot->val) + to;
  int lenM = val.size();
  int lenL = (len - lenM) >> 2;
  int lenR = len - lenM - lenL;
  val = Space(lenL) + val + Space(lenR);
  std::cout << Space(len * height) << val << std::endl;
  PrintInOrder(pRoot->right, height + 1, "^", len);
}

void PrintTree(const TreeNode* pRoot)
{
  std::cout << "Binary Tree: " << std::endl;
  if (pRoot)
  {
    PrintInOrder(pRoot, 0, "H", 17);
  }
  std::cout << std::endl;
}

int main(void)
{
  TreeNode* head = new TreeNode(5);
  head->left = new TreeNode(3);
  head->right = new TreeNode(8);
  head->left->left = new TreeNode(2);
  head->left->right = new TreeNode(4);
  head->left->left->left = new TreeNode(1);
  head->right->left = new TreeNode(7);
  head->right->left->left = new TreeNode(6);
  head->right->right = new TreeNode(10);
  head->right->right->left = new TreeNode(9);
  head->right->right->right = new TreeNode(11);
  PrintTree(head);

  head = new TreeNode(1);
  head->left = new TreeNode(-222222222);
  head->right = new TreeNode(3);
  head->left->left = new TreeNode(0x80000000);
  head->right->left = new TreeNode(55555555);
  head->right->right = new TreeNode(66);
  head->left->left->right = new TreeNode(777);
  PrintTree(head);

  head = new TreeNode(1);
  head->left = new TreeNode(2);
  head->right = new TreeNode(3);
  head->left->left = new TreeNode(4);
  head->right->left = new TreeNode(5);
  head->right->right = new TreeNode(6);
  head->left->left->right = new TreeNode(7);
  PrintTree(head);

  head = new TreeNode(1);
  head->left = new TreeNode(1);
  head->right = new TreeNode(1);
  head->left->left = new TreeNode(1);
  head->right->left = new TreeNode(1);
  head->right->right = new TreeNode(1);
  head->left->left->right = new TreeNode(1);
  PrintTree(head);

  return 0;
}
