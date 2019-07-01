struct ReturnData
{
  int maxD;
  int h;
};

int MaxDistance(const BTreeNode* pRoot)
{
  if (pRoot == nullptr)
  {
    return 0;
  }
  return SelectProcess(pRoot).maxD;
}

RetrunData SelectProcess(const BTreeNode* pRoot)
{
  if (pRoot == nullptr)
  {
    return ReturnData(0, 0);
  }
  ReturnData lInfo = SelectProcess(pRoot->pLeft);
  ReturnData rInfo = SelectProcess(pRoot->pRight);
  int includeItSelf = lInfo.h + rInfo.h + 1;
  int maxD = std::max(includeItSelf, std::max(lInfo.maxD,rInfo.maxD));
  return ReturnData(maxD, std::max(lInfo.h, rInfo.h) + 1);
}
