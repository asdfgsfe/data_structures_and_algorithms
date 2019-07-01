ListNode* CopyListWithRandom(ListNode* pHead)
{
  if (pHead == nullptr || pHead->pNext == nullptr)
  {
    return pHead;
  }
  ListNode* pNode = pHead;
  while (pNode)
  {
    ListNode* pNext = pNode->pNext;
    pNode->pNext = new ListNode(pNode->val);
    pNode->pNext->pNext = pNext;
    pNode = pNext;
  }
  pNode = pHead;
  while (pNode && pNode->pNext)
  {
    if (pNode->pRandom)
    {
		pNode->pNext-pRandom = pNode->pRandom->pNext;
    }
    pNode = pNode->pNext->pNext; 
  }
  ListNode* pNewHead = pHead->pNext;
  pNode = pNewHead;
  while (pHead && pNode)
  {
    ListNode* pNext = pNode->pNext;
    pHead->pNext = pNext;
    pNode->pNext = pNext->pNext;//这个地方有问题 如果pNext == nullptr就core了 实际上不会 因为节点一定是偶数个 
    pHead = pNext;
    pNode = pNext->pNext;
  }
  return pNewHead;
}
