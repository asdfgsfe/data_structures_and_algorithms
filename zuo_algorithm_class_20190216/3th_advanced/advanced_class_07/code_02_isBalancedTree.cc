struct RetuenData
{
  bool isB;
  int h;
  ReturnData(bool isBalance, int height)
    : isB(isBalance), height(h)
  {}
};

ReturnData IsProcess(const BTreeNode* pRoot)
{
  if (pRoot == nullptr)
  {
    return ReturnData(true, 0);
  }
  ReturnData lInfo = IsProcess(pRoot->pLeft);
  if (!lInfo.isB)
  {
    return ReturnData(false, 0);
  }
  ReturnData rInfo = IsProcess(pRoot->pRight);
  if (!rInfo.isB)
  {
    return ReturnData(false, 0);
  }
  if (std::abs(lInfo.h - rInfo.h) > 1)
  {
    return ReturnData(false, 0);
  }
  return ReturnData(true, std::max(lInfo.h, rInfo.h) + 1);
}

bool IsBalancedBTree(const BTreeNode* pRoot)
{
  if (pRoot == nullptr)
  {
    return true;
  }
  return IsProcess(pRoot).isB;
}

bool IsProcess2(const BTreeNode* pRoot, int& depth)
{
  if (pRoot == nullptr)
  {
    depth = 0;
    return true;
  }
  int lh = 0;
  int rh = 0;
  if (IsProcess2(pRoot->pLeft, lh) && IsProcess2(pRoot->pRight, rh) && std::abs(lh - rh) < 2)
  {
    depth = std::max(lh, rh) + 1;
    return true;
  }
  return false;
}

bool IsBalanceBTree2(const BTreeNode* pRoot)
{
  if (pRoot == nullptr)
  {
    return true;
  }
  int depath = 0;
  return IsProcess2(pRoot, depth);
}
