ListNode* FirstIntersetNode(const ListNode* pHead1, const ListNode* pHead2)
{
  if (pHead1 == nullptr || pHead2 == nullptr)
  {
    return nullptr;
  }
  int len1 = 0;
  int len2 = 0;
  ListNode* pNode = pHead1;
  while (pNode)
  {
    ++len1;
    pNode = pNode->pNext;
  }
  pNode = pHead2;
  while (pNode)
  {
    ++len2;
    pNode = pNode->pNext;
  }
  pNode = len1 > len2 ? pHead1 : pHead2;
  for (int i = 0; i < std::abs(len1 - len2); ++i)
  {
    pNode = pNode->pNext;
  }
  ListNode* pNode2 = len1 < len2 ? pHead1 : pHead2;
  while (pNode && pNode2)
  {
    if (pNode1 == pNode2)
    {
      return pNode1;
    }
    pNode = pNode->pNext;
    pNode2 =pNode2->pNext;
  }
  return nullptr;
}