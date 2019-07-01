struct ComplexListNode
{
  int val;
  ComplexListNode* pNext;
  ComplexListNode* pSibling;
};


ComplexListNode* CloneNodes(ComplexListNode* pHead)
{
  if (!pHead)
  {
    return nullptr;
  }
  
  ComplextListNode* pNode = pHead;
  while (pNode)
  {
    ComplexListNode* pNext = pNode->pNext;  
    pNode->next = new ComplexListNode(pNode->val);
    assert(pNode->next);
    pNode->next->next = pNext;
    pNode = pNext;
  }
  return pHead;
}

void ConnectSiblingNodes(ComplexListNode* pHead)
{
  if (!pHead || !pHead->pNext)
  {
    return;
  }
  while (pHead)
  {
    ComplexListNode* pCloneNode = pHead->next;
    if (pHead->pSibling)
    {
      pCloneNode->pSibling = pHead->pSibling->next;
    }
    pHead = pCloneNode->pNext;
  }
}

ComplexListNode* ReconnectNodes(ComplexListNode* pHead)
{
  if (!pHead && !pHead->pNext)
  {
    return pHead;
  }
  ComplexListNode* pCloneHead = pHead->pNext;
  ComplexListNode* pNode = pCloneHead;
  while (pHead && pNode)
  {
    pHead->next = pNode->pNext;
    pHead = pNode;
    pNode = pNode->pNext;
  }
  return pCloneHead;
}

ComplexListNode* ComplexClone(ComplexListNode* pHead)
{
  ComplexListNode* pNode = CloneNodes(pHead);
  ConnectSiblingNodes(pNode);
  return ReconnectNodes(pNode);
}
