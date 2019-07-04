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

