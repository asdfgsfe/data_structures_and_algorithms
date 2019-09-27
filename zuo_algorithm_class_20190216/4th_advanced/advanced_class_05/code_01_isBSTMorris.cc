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
		//return false; //����ֱ�ӷ��� ��Ϊ���Ľṹ�ı���
		isB = false;
    }
    pPre = pRoot;
    pRoot = pRoot->pRight;
  }
  return isB;
}
