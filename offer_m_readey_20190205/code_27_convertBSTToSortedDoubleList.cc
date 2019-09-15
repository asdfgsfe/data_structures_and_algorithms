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

//由于pLastNodeInList是一个全局的点 全局的上一个点 所以这里要用指针的指针
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
