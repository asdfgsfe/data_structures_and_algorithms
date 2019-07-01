//答案的结果一定是一个返回值
struct ReturnData
{
  int maxDistance;
  int h;
};

ReturnData DistanceProcess(const BTreeNode* pRoot)
{
  if (pRoot == nullptr)
  {
    return ReturnData(0, 0);
  }
  ReturnData lInfo = DistanceProcess(pRoot->pLeft);
  ReturnData rInfo = DistanceProcess(pRoot->pRight);
  int includeItSelft = lInfo.h + 1 + rInfo.h;
  return ReturnData(std::max(includeItSelf, std::max(lInfo.maxDistance, rInfo.Distance)),
                    std::max(lInfo.h, rInfo.h) + 1);
}

int MaxDistance(const BTreeNode* pRoot)
{
  if (pRoot == nullptr)
  {
    return 0;
  }
  return DistanceProcess(pRoot).maxDistance;
}

int DistanceProcessTail(const BTreeNode* pRoot, int& depth)
{
  if (pRoot == nullptr)
  {
    depth = 0;
    return 0;
  }
  int lDepth = 0;
  int lMaxDistance = DistanceProcessTail(pRoot->pLeft, lDepth);
  int rDepth = 0;
  int rMaxDistance = DistanceProcessTail(pRoot->pRight, rDepth);
  depth = std::max(lDepth, rDepth) + 1;
  return std::max(lDepth + 1 + rDepth, std::max(lMaxDistance, rMaxDistance));
}

int MaxDistanceTail(const BTreeNode* pRoot)
{
  if (pRoot == nullptr)
  {
    return 0;
  }
  int depth = 0;
  return DistanceProcessTail(pRoot, depth);
}
