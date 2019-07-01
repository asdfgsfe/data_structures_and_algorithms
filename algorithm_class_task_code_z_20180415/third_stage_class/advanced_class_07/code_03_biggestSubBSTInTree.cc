#include <iostream>
#include <string>

using std::string;

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
  int size;
  int maxVal;
  int minVal;
  TreeNode* pHead;

  ReturnType(int s, int max, int min, TreeNode* pNode)
    : size(s), maxVal(max), minVal(min), pHead(pNode)
  {}
};

ReturnType Process(TreeNode* pNode)
{
  if (pNode == nullptr)
  {
    return ReturnType(0, 0x80000000, 0x7fffffff, nullptr);
  }
  ReturnType leftSubTreeInfo = Process(pNode->left);
  ReturnType rightSubTreeInfo = Process(pNode->right);
  int includeItSelf = 0;
  if (leftSubTreeInfo.pHead == pNode->left 
      && rightSubTreeInfo.pHead == pNode->right
      && pNode->val > leftSubTreeInfo.maxVal
      && pNode->val < rightSubTreeInfo.minVal)
  {
    includeItSelf = leftSubTreeInfo.size + 1 + rightSubTreeInfo.size;
  }
  int p1 = leftSubTreeInfo.size;
  int p2 = rightSubTreeInfo.size;
  int maxSize = std::max(std::max(p1, p2), includeItSelf);
  TreeNode* maxHead = p1 > p2 ? leftSubTreeInfo.pHead : rightSubTreeInfo.pHead;
  if (maxSize == includeItSelf)
  {
    maxHead = pNode;
  }
  return ReturnType(maxSize, 
        std::max(std::max(leftSubTreeInfo.maxVal, rightSubTreeInfo.maxVal), pNode->val),
        std::min(std::min(leftSubTreeInfo.minVal, rightSubTreeInfo.minVal), pNode->val),
        maxHead);
}

int BiggestSubBST1(TreeNode* pRoot)
{
  if (pRoot == nullptr)
  {
    return 0;
  }
  return Process(pRoot).size;
}

TreeNode* PosOrder(TreeNode* pNode, int* record)
{
  if (pNode == nullptr)
  {
    record[0] = 0;
    record[1] = 0x7fffffff;
    record[2] = 0x80000000;
    return nullptr;
  }
  TreeNode* lBST = PosOrder(pNode->left, record);
  int lsize = record[0];
  int lmin = record[1];
  int lmax = record[2];
  TreeNode* rBST = PosOrder(pNode->right, record);
  int rsize = record[0];
  int rmin = record[1];
  int rmax = record[2];
  record[1] = std::min(std::min(lmin, rmin), pNode->val);
  record[2] = std::max(std::max(lmax, rmax), pNode->val);
  if (lBST == pNode->left && rBST == pNode->right 
      && pNode->val > lmax && pNode->val < rmin)
  {
    record[0] = lsize + 1 + rsize;
    return pNode;
  }
  record[0] = std::max(lsize, rsize);
  return lsize > rsize ? lBST : rBST;
}

TreeNode* BiggestSubBST2(TreeNode* pRoot)
{
  if (pRoot == nullptr)
  {
    return 0;
  }
  int record[3]; //0->size 1->min, 2->max
  TreeNode* pNode = PosOrder(pRoot, record);
  std::cout << "BiggestSubBST2: " << record[0] << std::endl;
  return pNode;
}

string GetSpace(int num)
{
  string str;
  for (int i = 0; i < num; ++i)
  {
    str += " ";
  }
  return str;
}

void PrintInOrder(TreeNode* pNode, int height, string to, int len)
{
  if (pNode == nullptr)
  {
    return;
  }
  PrintInOrder(pNode->right, height + 1, "v", len);
  string val = to + std::to_string(pNode->val) + to;
  int lenM = val.length();
  int lenL = (len - lenM) / 2;
  int lenR = len - lenM - lenL;
  val = GetSpace(lenL) + val + GetSpace(lenR);
  std::cout << GetSpace(height * len) + val << std::endl;
  PrintInOrder(pNode->left, height + 1, "^", len);
}


void PrintTree(TreeNode* pNode)
{
  std::cout << "Binary Tree:" << std::endl;
  PrintInOrder(pNode, 0, "H", 17);
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

  std::cout << BiggestSubBST1(head) << std::endl;

  PrintTree(head);
  TreeNode* bst = BiggestSubBST2(head);
  PrintTree(bst);

  return 0;
}
