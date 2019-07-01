BSTNode* ConvertBSTToDoubleSortedList(BSTNode* pRoot)
{
  if (!pRoot)
  {
    return nullptr;
  }
  BSTNode* pHead = nullptr;
  BSTNode* pLastNodeInList = nullptr;
  ConvertPrecess(pRoot, &pHead, &pLastNodeInList);
  return pHead;
}

void ConvertProcess(BSTNode* pNode, BSTNode** pHead, BSTNode** pLastNodeInList)
{
  if (!pNode)
  {
    return;
  }
  if (pNode->pLeft)
  {
    ConvertProcess(pNode->pLeft, pHead, pLastNodeInList);
  }
  if (!pNode->pLeft && !(*pHead))
  {
    *pHead = pNode;
  }
  pNode->pLeft = (*pLastNodeInList);
  if (*pLastNodeInList)
  {
    *pLastNodeInList->pRight = pNode;
  }
  *pLastNodeInList = pNode;
  if (pNode->pRight)
  {
    ConvertProcess(pNode->pRight, pHead, pLastNodeInList);
  }
}
