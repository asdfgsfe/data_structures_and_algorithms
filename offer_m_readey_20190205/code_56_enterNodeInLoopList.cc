const ListNode* enterNodeInLoopList(const ListNode* pHead)
{
  if (pHead == nullptr)
  {
    return nullptr;
  }
  const ListNode* pLoopNode = LoopNode(pHead);
  if (pLoopNode == nullptr)
  {
    return nullptr;
  }
  int loopNum = LoopNodeNumber(pLoopNode);
  const ListNode* pNode = pHead;
  for (int i = 0; i < loopNum; ++i)
  {
    pNode = pNode->pNext;
  }
  while (pNode != pHead)
  {
    pNode = pNode->pNext;
    pHead = pHead->pNext;
  }
  return pNode;
}

const ListNode* LoopNode(const ListNode* pHead)
{
  const ListNode* pNode = pHead;
  while (pHead && pNode && pNode != pHead)
  {
    pHead = pHead->pNext;
    pNode = pNode->pNext;
    if (pNode)
    {
      pNode = pNode->pNext;
    }
  }
  if (pNode && pHead && pNode == pHead)
  {
    return pNode;
  }
  return nullptr;
}

int LoopNodeNumber(const ListNode* pNode)
{
  assert(pNode);
  const ListNode* pLoopNode = pNode->pNext;
  int k = 1;
  while (pLoopNode != pNode)
  {
    ++k;
    assert(pLoopNode);
    pLoopNode = pLoopNode->pNext;
  }
  return k;
}

