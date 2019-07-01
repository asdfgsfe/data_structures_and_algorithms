int BTreeDepth(const BTreeNode* pRoot)
{
  if (!pRoot)
  {
    return 0;
  }
  return std::max(BTreeDepth(pRoot->pLeft), BTreeDepth(pRoot->pRight)) + 1;
}

struct ReturnData
{
  bool isB;
  int h;

  ReturnData(bool isBalance, int height)
    : isB(isBalance), height(h)
  {}
};
bool IsBalanceBTree1(const BTreeNode* pRoot)
{
  if (!pRoot)
  {
    return ReturnData(true, 0);
  }
  ReturnData leftInfo = IsBalanceBTree(pRoot->pLeft);
  if (!leftInfo.isB)
  {
    return ReturnData(false, 0);
  }
  ReturnData rightInfo = IsBalanceBTree(pRoot->pRight);
  if (!rightInfo.isB)
  {
    return ReturnData(false, 0);
  }
  int diff = leftInfo.h - rightInfo.h;
  if (diff > 1 || diff < -1)
  {
    return ReturnData(false, 0);
  }
  return ReturnData(true, std::max(leftInfo.h, right.h) + 1);
}

bool IsBalanceBTree2(const BTreeNode* pRoot)
{
  int depth = 0;
  return Process(pRoot, &depth);
}

bool Process(const BTreeNode* pRoot, int* depth)
{
  if (!pRoot)
  {
    *depth = 0;
    return true;
  }
  int leftD = 0;
  int rightD = 0;
  if (Process(pRoot->pLeft, leftD) && Process(pRoot->pRight, rightD))
  {
    int diff = leftD - rightD;
    if (diff <= 1 || diff >= -1)
    {
      *depth = std::max(leftD, rightD) + 1;
      return true;
    }
  }
  return false;
}
