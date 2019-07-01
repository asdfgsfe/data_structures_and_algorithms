ListNode* ReverseList(ListNode* pHead)
{
  if (pHead == nullptr || pHead->pNext == nullptr)
  {
    return pHead;
  }
  ListNode* pPreNode = nullptr;
  while (pHead)
  {
    ListNode* pNext = pHead->pNext;
    pHead->pNext = pPreNode;
    pPreNode = pHead;
    pHead = pNext;
  }
  return pPreNode;
}
