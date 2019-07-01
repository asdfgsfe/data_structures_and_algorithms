void DeleteDuplicateNode(ListNode* pHead)
{
  if (!pHead)
  {
    return;
  }
  ListNode* pRreNode = nullptr;
  ListNode* pNewHead = nullptr;
  while (pHead)
  {
    ListNode* pNext = pHead->pNext;
    bool needDel = false;
    if (pNext && pHead->val == pNext->val)
    {
      needDel = true;
    }
    if (!needDel)
    {
      pPreNode = pHead;
      if (pNewHead == nullptr)
      {
        pNewHead = pHead;
      }
      pHead = pNext;
      continue;
    }
    int delVal = pHead->val;
    while (pHead && pHead->val == delVal)
    {
      pNext = pHead->pNext;
      delete pHead;
      pHead = pNext;
    }
    if (pPreNode == nullptr)
    {
      pPreNode = pHead;
    }
    else
    {
      pPreNode->pNext = pHead;
    }
    if (pNewHead == nullptr)
    {
      pNewHead = pHead;  
    }
    pHead = pNext;
  }
  return pNewHead;
}
