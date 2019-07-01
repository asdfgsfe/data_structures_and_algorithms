struct RetrunData
{
  int size;
  int min;
  int max;
  const BTreeNode* pHead;
};

int BiggestSubBST(const BTreeNode* pRoot)
{
  if (pRoot == nullptr)
  {
    return 0;
  }
  return TotalProcess(pRoot).size;
}

ReturnData TotalProcess(const BTreeNode* pRoot)
{
  if (pRoot == nullptr)
  {
    return ReturnData(0, 0x80000000, 0x7fffffff, nullptr);
  }
  RetrunData lInfo = TotalProcess(pRoot->pLeft);
  RetrunData rInfo = TotalProcess(pRoot->pRight);
  int includeItSelf = 0;
  if (lInfo.pHead == pRoot->pLeft 
      && rInfo.pHead == pRoot->pRight
      && pRoot->val > lInfo.max 
      && pRoot->val < rInfo.min)
  {
    includeItSelf = lInfo.size + 1 + rInfo.size;
  }
  const BTreeNode* pCurHead = lInfo.size > rInfo.size ? lInfo.pHead : rInfo.pHead;
  int maxSize = std::max(includeItSelf, std::max(lInfo.size, rInfo.size));
  if (maxSize == includeItSelf)
  {
    pCurHead = pRoot;
  }
  return ReturnData(maxSize, 
                    std::min(std::min(lInfo.min, rInfo.min), pRoot->val),
                    std::max(std::max(lInfo.max, rInfo.max), pRoot->val),
                    pCurHead);
}

BTreeNode* TotalProcessByTailOrder(const BTreeNode* pRoot, vector<int>& lrInfo)
{
  if (pRoot == nullptr)
  {
    lrInfo[0] = 0;
    lrInfo[1] = 0x80000000;
    lrInfo[2] = 0x7fffffff;
    return nullptr;
  }
  vector<int> lInfo;
  BTreeNode* pLHead = TotalProcessByTailOrder(pRoot->pLeft, lInfo);
  vector<int> rInfo;
  BTreeNode* pRHead = TotalProcessByTailOrder(pRoot->pRight, rInfo);
  int includeItSelf = 0;
  if (pLHead == pRoot->pLeft
      && pRHead = pRoot->pRight
      && lInfo[1] < pRoot->val
      && rInfo[1] > pRoot->val)
  {
    includeItSelf = lInfo[0] + 1 + rInfo[0];
  }
  BTreeNode* pMaxHead = lInfo[0] > rInfo[0] ? pLHead : pRHead;
  int maxSize = std::max(includeItSelf, std::max(lInfo[0], rInfo[0]));
  if (maxSize == includeItSelf)
  {
    pMaxHead = pRoot;
  }
  lrInfo[0] = maxSize;
  lrInfo[1] = std::max(pRoot->val, std::max(lInfo[1], rInfo[1]));
  lrInfo[2] = std::min(pRoot->val, std::min(lInfo[2], rInfo[2]));
  return pMaxHead;
}

int BiggestSubBST2(const BTreeNode* pRoot)
{
  if (pRoot == nullptr)
  {
    return 0;
  }
  vector<int> lrInfo; //0->size 1->max, 2->min
  return TotalProcessByTailOrder(pRoot, lrInfo);
}
