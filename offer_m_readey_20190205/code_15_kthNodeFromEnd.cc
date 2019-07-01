struct ListNode
{
  int val;
  ListNode* next;
};

ListNode* KthNodeFromEnd(const ListNode* pHead, int k)
{
  if (!pHead || k < 1)
  {
    return nullptr;
  }
  ListNode* pkthNode = pHead;
  for (int i = 0; i < k; ++i)
  {
    if (!pKthNode)
    {
      return nullptr;
    }
    pKthNode = pKthNode->next;
  }
  while (pKthNode && pHead)
  {
    pKthNode = pKthNode->next;
    pHead = pHead->next;
  }
  return pHead;
}
