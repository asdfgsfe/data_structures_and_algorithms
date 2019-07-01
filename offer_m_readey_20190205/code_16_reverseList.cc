ListNode* ReverseList(ListNode* pHead)
{
  if (pHead == nullptr || pHead->next == nullptr)
  {
    return pHead;
  }
  ListNode* pPreNode = nullptr;
  while (pHead)
  {
    ListNode* pNext = pHead->next;
    pHead->next = pPreNode;
    pPreNode = pHead;
    pHead = pNext;
  }
  return pPreNode;
}
