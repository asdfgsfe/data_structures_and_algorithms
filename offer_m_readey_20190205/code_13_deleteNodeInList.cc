void DeleteNodeInList(ListNode* pHead, ListNode* pToDelNode)
{
  if (!pHead || !pToDelNode)
  {
    return;
  }
  if (pToDelNode->next)
  {
    ListNode* pNode = pToDelNode->next;
    pToDelNode->val = pNode->val;
    pToDelNode->next = pNode->next;
    delete pNode;
    pNode = nullptr;
  }
  else if (pHead == pToDelNode)
  {
    delete pToDelNode;
    pToDelNode = nullptr;
    pHead = nullptr;
  }
  else
  {
    ListNode* pNode = pToDelNode;
    pToDelNode = nullptr;
    delete pNode;
  }
}

void DeleteNodeInList(ListNode* pHead, ListNode* pToDelNode)
{
  if (!pHead || !pToDelNode)
  {
    return;
  }
  if (pToDelNode->next)
  {
    ListNode* pNode = pToDelNode->next;
    pToDelNode->val = pNode->val;
    pToDelNode->next = pNode->next;
    delete pNode;
    pNode = nullptr;
  }
  else if (pHead == pToDelNode)
  {
    delete pToDelNode;
    pToDelNode = nullptr;
    pHead = nullptr;
  }
  else
  {
    while (pHead && pHead->next != pToDelNode)
    {
      pHead = pHead->next;
    }
    if (pHead)
    {
      pHead->next = nullptr;
    }
    delete pToDelNode;
    pToDelNode = nullptr;
  }
}

