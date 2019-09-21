ListNode* ListPartition(LsitNode* pHead, int pivot)
{
  if (pHead == nullptr)
  {
    return nullptr;
  }
  ListNode* sH = nullptr;
  ListNode* sT = nullptr;
  ListNode* eH = nullptr;
  ListNode* eT = nullptr;
  ListNode* bH = nullptr;
  ListNode* bT = nullptr;
  while (pHead)
  {
    ListNode* pNext = pHead->pNext;
    pHead->pNext = nullptr;
    if (pHead->val < pivot)
    {
      if (sH == nullptr)
      {
        sH = pHead;
        sT = pHead;
      }
      else
      {
        sH->pNext = pHead;
        sT = pHead;
      }
    }
    else if (pHead->val == pivot)
    {
      if (eH == nullptr)
      {
        eH = pHead;
        eT = pHead;
      }
      else
      {
        eH = pHead->pNext;
        eT = pHead;
      }
    }
    else
    {
      if (bH == nullptr)
      {
        bH = pHead;
        bT = pHead;
      }
      else
      {
        bH->pNext = pHead;
        bT = pHead;
      }
    }
    pHead = pNext;
  }
  if (sT)
  {
    sT->pNext = eH;
      eT = eT == nullptr ? sT : eT; //这里很重要 如果没有中间部分 就拿开始部分和结尾部分连接起来
  }
  if (eT)
  {
    eT->pNext = bH;
  }
  return sH ? sH : eH ? eH : bH;
}

