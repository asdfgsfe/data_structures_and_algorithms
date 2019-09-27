bool IsBST(BTreeNode* pRoot)
{
  if (pRoot == nullptr)
  {
    return true;
  }
  BTreeNode* pPre = nullptr;
  bool isB = true;
  while (pRoot)
  {
    BTreeNode* pCurLeft = pRoot->pLeft;
    if (pCurLeft)
    {
      while (pCurLeft->pRight && pCurLeft->pRight != pRoot)
      {
        pCurLeft = pCurLeft->pRight;
      }
      if (pCurLeft->pRight == nullptr)
      {
        pCurLeft->pRight = pRoot;
        pRoot = pRoot->pLeft;
        continue;
      }
      if (pCurLeft->pRight == pRoot)
      {
        pCurLeft->pRight = nullptr;
      }
    }
    if (pPre && pPre->val > pRoot->val)
    {
		//return false; //不能直接返回 因为树的结构改变了
		isB = false;
    }
    pPre = pRoot;
    pRoot = pRoot->pRight;
  }
  return isB;
}
