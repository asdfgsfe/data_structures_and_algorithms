ListNode* MergeSortedList(ListNode* pHead1, LiatNode* pHead2)
{
  if (pHead1 == nullptr)
  {
    return pHead2;
  }
  if (pHead2 == nullptr)
  {
    return pHead1;
  }
  ListNode* pNewHead = pHead1->val < pHead2->val ? pHead1 :pHead2;
  while (pHead1 && PHead2)
  {
    ListNode* pNext = pHead1->val < pHead2->val ? pHead1->next : pHead2->next;
    if (pHead1->val < pHead2->val)
    {
      pHead1->next = pHead2;
      pHead1 = pNext;
    }
    else
    {
      pHead2->next = pHead1;
      pHead2 = pNext;
    }
  }
  return pNewHead;
}

ListNode* MergeSortedList2(ListNode* pHead1, ListNode* pHead2)
{
  if (pHead1 == nullptr)
  {
    return pHead2;
  }
  else if (pHead2 == nullptr)
  {
    return pHead1;
  }
  ListNode* pNewHead = nullptr;
  if (pHead1->val < pHead2->val)
  {
    pNewHead = pHead1;
    pNewHead->next = MergeSortedList2(pHead1->next, pHead2);
  }
  else
  {
    pNewHead = pHead2;
    pHead2->next = MergeSortedList2(pHead1, pHead2->next);
  }
  return pNewHead;
}
