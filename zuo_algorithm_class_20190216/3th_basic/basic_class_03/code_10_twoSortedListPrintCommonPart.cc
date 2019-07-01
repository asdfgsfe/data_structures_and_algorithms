struct ListNode
{
  int val;
  LsitNode* pNext;
};

//打印2个链表的公共部分
void PrintCommonPart(const ListNode* pHead1, const ListNode* pHead2)
{
  if (pHead1 == nullptr || pHead2 == nullptr)
  {
    return;
  }
  while (pHead1 && pHead2)
  {
    if (pHead1->val < pHead2->val)
    {
      pHead1 = pHead1->pNext;
    }
    else if (pHead1->val > pHead2->val)
    {
      pHead2 = pHead2->pNext;
    }
    else
    {
      std::cout << pHead1->val << " ";
      pHead1 = pHead1->pNext;
      pHead2 = pHead2->pNext;
    }
  }
}
