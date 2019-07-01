const ListNode* FirstCommonNodeInList(const ListNode* pHead1, const ListNode* pHead2)
{
  if (!pHead1 || !pHead2)
  {
    return nullptr;
  }
  int len1 = ListLength(pHead1);
  int len2 = ListLength(pHead2);
  int diff = len1 - len2;
  const ListNode* pLongNode = pHead1;
  const ListNode* pShortNode = pHead2;
  if (diff < 0)
  {
    pLongNode = pHead2;
    pShortNode = pHead1;
    diff = -diff;
  }
  for (int i = 0; i < diff; ++i)
  {
    assert(pLongNode);
    pLongNode = pLongNode->pNext;
  }
  while (pLongNode && pShortNode)
  {
    if (pLongNode == pShortNode)
    {
      return pLongNode;
    }
    pLongNode = pLongNode->pNext;
    pShortNode = pShortNode->pNext;
  }
  return nullptr;
}

int ListLength(const ListNode* pHead)
{
  int len = 0;
  while (pHead)
  {
    ++len;
    pHead = pHead->pNext;
  }
  return len;
}
