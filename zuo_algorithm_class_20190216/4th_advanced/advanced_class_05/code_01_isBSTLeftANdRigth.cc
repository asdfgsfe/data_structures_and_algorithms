struct ReturnData
{
  bool isBST;
  int max;
  int min;
  BTreeNode* pHead;
  RetrunData(bool is, int ma, int mi, BTreeNode* pNode)
    : isBST(is), max(ma), min(mi), pHead(pNode)
  {}
};

ReturnData IsProcess(const BTreeNode* pRoot)
{
  if (pRoot == nullptr)
  {
    return ReturnData(true, 0x80000000, 0x7fffffff, nullptr);
  }
  RetrunData lInfo = IsProcess(pRoot->pLeft);
  if (!lInfo.isBST)
  {
    return ReturnData(false, 0, 0, nullptr);
  }
  RetrunData rInfo = IsProcess(pRoot->pRight);
  if (!rInfo.isBST)
  {
    return ReturnData(false, 0, 0, nullptr);
  }
  if (lInfo.max < pRoot->val 
      && rInfo.min > pRoot->val
      && lInfo.pHead == pRoot->pLeft 
      && rInfo.pHead == pRoot->pRight)
  {
    return RetrunData(true, 
		      std::max(pRoot->val, std::max(lInfo.max, rInfo.max), 
		      std::min(pRoot->val, std::min(lnfo.min, rInfo.min)), 
		      pRoot);
  }
  return RetrunData(false, 0, 0, nullptr);
}

bool IsBST(const BTreeNode* pRoot)
{
  if (pRoot == nullptr)
  {
    return true;
  }
  return IsProcess(pRoot).isBST;
}
