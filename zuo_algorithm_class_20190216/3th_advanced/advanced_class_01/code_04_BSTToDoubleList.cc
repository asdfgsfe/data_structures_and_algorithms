void ConvertProcess(BSTreeNode* pNode, BSTreeNode** pNewHead, BSTreeNode* pPre)
{
  if (pNode == nullptr)
  {
    return;
  }
  ConvertProcess(pNode->pLeft, pNewHead, pPre);
  if (pNode->pLeft == nullptr && (*pHead) == nullptr)
  {
    *pHead = pNode;
  }
  pNode->pLeft = (*pPre);
  if (*pPre)
  {
    *pPre->pRight = pNode;
  }
  *pPre = pNode;
  ConvertProcess(pNode->pRight, pNewHead, pPre);
}

BSTreeNode* BSTToDoubleList(BSTreeNode* pRoot)
{
  if (pRoot == nullptr)
  {
    return nullptr;
  }
  BSTreeNode* pNewHead = nullptr;
  BSTreeNode* pPre = nullptr;
  ConvertProcess(pRoot, &pNewHead, pPre);
  return pNewHead;
}

//×ó±ß¸ã¶¨ ÓÒ±ß¸ã¶¨
BSTreeNode* ConvertProcess2(BSTreeNode* pRoot)
{
  if (pRoot == nullptr)
  {
    return nullptr;
  }
  BSTreeNode* pLeftE = ConvertProcess2(pRoot->pLeft);
  BSTreeNode* pRightE = ConvertProcess2(pRoot->pRight);
  BSTreeNode* pLeftS = pLeftE ? pLeftE->pRight : nullptr;
  BSTreeNode* pRightS = pRightE ? pRightE->pRight : nullptr;
  if (pLeftE && pRightE)
  {
    pLeftE->pRigth = pRoot;
    pRoot->pLeft = pLeftE;
    pRoot->pRight = pRightS;
    pRightS->pLeft = pRoot;
    pRightE->pRight = pLeftS;
    return pRightE;
  }
  if (pLeftE)
  {
    pLeftE->pRight = pRoot;
    pRoot->pLeft = pLeftE;
    pRoot->pRight = pLeftS;
    return pRoot;
  }
  if (pRightE)
  {
    pRoot->pRight = pRightS;
    pRightS->pLeft = pRoot;
    pRightE->pRight = pRoot;
    return pRightE;
  }
  pRoot->pRight = pRoot;
  return pRoot;
}

BSTreeNode* Convert2(BSTreeNode* pRoot)
{
  if (pRoot == nullptr)
  {
    return nullptr;
  }
  BSTreeNode* pLast = ConvertProcess2(pRoot);
  pRoot = pLast->pRight;
  pLast->pRight = nullptr;
  return pRoot;
}
