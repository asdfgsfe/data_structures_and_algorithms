struct ListNode
{
  int val;
  ListNode* next;
};

void PrintListFromTailToHead(const ListNode* pHead)
{
  if (pHead == nullptr)
  {
    return;
  }
  if (pHead->next == nullptr)
  {
    std::cout << pHead->val << std::endl;
    return;
  }
  PrintListFromTailToHead(pHead->next);
}

void PrintListFromTailToHead2(const ListNode* pHead)
{
  if (pHead)
  {
    if (pHead->next)
    {
      PrintListFromTailToHead2(pHead->next);
    }
    std::cout << pHead->val << std::endl;
  }
}
