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

struct ReturnData
{
  const TreeNode* head;
  int max;
  int min;
  int size;

  ReturnData(const TreeNode* p, int maxVal, int minVal, int s)
    : head(p), max(maxVal), min(minVal), size(s)
  {}
};

ReturnData Process(const TreeNode* pNode)
{
  if (pNode == nullptr)
  {
    return ReturnData(nullptr, 0x80000000, 0x7fffffff, 0);
  }
  ReturnData leftSubTreeInfo = Process(pNode->left);
  ReturnData rightSubTreeInfo = Process(pNode->right);
  int includeItSelf = 0;
  if (leftSubTreeInfo.head == pNode->left
      && rightSubTreeInfo.head == pNode->right
      && leftSubTreeInfo.max < pNode->val
      && rightSubTreeInfo.min > pNode->val)
  {
    includeItSelf = leftSubTreeInfo.size + rightSubTreeInfo.size + 1;
  }
  int maxSize = std::max(std::max(leftSubTreeInfo.size, rightSubTreeInfo.size), includeItSelf);
  const TreeNode* maxHead = leftSubTreeInfo.size > rightSubTreeInfo.size ? leftSubTreeInfo.head : rightSubTreeInfo.head;
  if (maxSize == includeItSelf)
  {
    maxHead = pNode;
  }
  return ReturnData(maxHead, 
                    std::max(std::max(leftSubTreeInfo.max, rightSubTreeInfo.max), pNode->val), 
                    std::min(std::min(leftSubTreeInfo.min, rightSubTreeInfo.min), pNode->val), 
                    maxSize);
}

const TreeNode* BiggestSubBST(const TreeNode* pRoot)
{
  if (pRoot == nullptr)
  {
    return nullptr;
  }
  return Process(pRoot).head;
}

string GetSpace(int num)
{
  string space;
  for (int i = 0; i < num; ++i)
  {
    space.append(" ");
  }
  return space;
}

void PrintTreeInOrder(const TreeNode* pRoot, int height, string to, int len)
{
  if (pRoot == nullptr)
  {
    return;
  }
  PrintTreeInOrder(pRoot->right, height + 1, "v", len);
  string val = to + std::to_string(pRoot->val) + to;
  int lenM = val.size();
  int lenL = (len - lenM) / 2;
  int lenR = len - lenM -lenL;
  val = GetSpace(lenL) + val + GetSpace(lenR);
  std::cout << GetSpace(height * len) << val << std::endl;
  PrintTreeInOrder(pRoot->left, height + 1, "^", len);
}

void PrintTree(const TreeNode* head) 
{
  std::cout <<"Binary Tree:" << std::endl;
  PrintTreeInOrder(head, 0, "H", 17);
  std::cout << std::endl;
}

int main(void)
{
  TreeNode* head = new TreeNode(6);
  head->left = new TreeNode(1);
  head->left->left = new TreeNode(0);
  head->left->right = new TreeNode(3);
  head->right = new TreeNode(12);
  head->right->left = new TreeNode(10);
  head->right->left->left = new TreeNode(4);
  head->right->left->left->left = new TreeNode(2);
  head->right->left->left->right = new TreeNode(5);
  head->right->left->right = new TreeNode(14);
  head->right->left->right->left = new TreeNode(11);
  head->right->left->right->right = new TreeNode(15);
  head->right->right = new TreeNode(13);
  head->right->right->left = new TreeNode(20);
  head->right->right->right = new TreeNode(16);

  PrintTree(head);
  const TreeNode* pNode = BiggestSubBST(head);
  PrintTree(pNode);

  return 0;
}
