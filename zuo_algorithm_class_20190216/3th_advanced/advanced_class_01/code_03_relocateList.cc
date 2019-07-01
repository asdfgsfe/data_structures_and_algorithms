#include <iostream>
    
struct ListNode
{
  int val;
  ListNode* pNext;
  ListNode(int v)
    : val(v), pNext(nullptr)
  {}
};

ListNode* RelocateList1(ListNode* pHead)
{
  if (pHead == nullptr || pHead->pNext == nullptr || pHead->pNext->pNext == nullptr)
  {
    return pHead;
  }
  ListNode* pQuickNode = pHead;
  ListNode* pSlowNode = pHead;
  while (pSlowNode && pQuickNode && pQuickNode->pNext)
  {
    pSlowNode = pSlowNode->pNext;
    pQuickNode = pQuickNode->pNext;
    pQuickNode = pQuickNode->pNext;
  }
  pQuickNode = pSlowNode;
  pSlowNode = pHead;
  while (pQuickNode && pQuickNode->pNext)
  {
    ListNode* pSlowNext = pSlowNode->pNext;
    pSlowNode->pNext = pQuickNode;
    ListNode* pQuickNext = pQuickNode->pNext;
    if (pQuickNext && pQuickNext->pNext)
    {
      pQuickNode->pNext = pSlowNext;
    }
    pQuickNode = pQuickNext;
    pSlowNode = pSlowNext;
  }
  return pHead;
}

ListNode* RelocateList2(ListNode* pHead)
{
  if (pHead == nullptr || pHead->pNext == nullptr || pHead->pNext->pNext == nullptr)
  {
    return pHead;
  }
  ListNode* pQuickNode = pHead->pNext->pNext;
  ListNode* pSlowNode = pHead;
  while (pSlowNode && pQuickNode && pQuickNode->pNext)
  {
    pSlowNode = pSlowNode->pNext;
    pQuickNode = pQuickNode->pNext;
    pQuickNode = pQuickNode->pNext;
  }
  pQuickNode = pSlowNode->pNext;
  pSlowNode->pNext = nullptr;
  pSlowNode = pHead;
  while (pSlowNode && pQuickNode)
  {
    ListNode* pSlowNext = pSlowNode->pNext;
    pSlowNode->pNext = pQuickNode;
    ListNode* pQuickNext = pQuickNode->pNext;
    if (pSlowNext)
    {
      pQuickNode->pNext = pSlowNext;
    }
    pSlowNode = pSlowNext;
    pQuickNode = pQuickNext;
  }
  return pHead;
}

ListNode* Relacete3(ListNode* pHead)
{
  if (pHead == nullptr || pHead->pNext == nullptr || pHead->pNext->pNext)
  {
    return pHead;
  }
  ListNode* pQuick = pHead->pNext->pNext;
  ListNode* pSlow = pHead;
  while (pSlow && pQuick && pQuick->pNext)
  {
    pSlow = pSlow->pNext;
    pQuick = pQuick->pNext;
    pQuick = pQuick->pNext;
  }
  pQuick = pSlow->pNext;
  pSlow->pNext = nullptr;
  pSlow = pHead;
  while (pSLow && pSLow->pNext)
  {
    ListNode* pQuickNext = pQuick->pNext;
    pQuick->pNext = pSlow->pNext;
    pSlow->pNext = pQuick;
    pSlow = pQuick->pNext;
    pQuick = pQuickNext;
  }
  pSlow->pNext = pQuick;
  return pHead;
}

void PrintList(const ListNode* pHead)
{
  while (pHead)
  {
    std::cout << pHead->val << " ";
    pHead = pHead->pNext;
  }
  std::cout << std::endl;
}

int main(void)
{
  ListNode* head = new ListNode(1);
  head->pNext = new ListNode(2);
  head->pNext->pNext = new ListNode(3);
  head->pNext->pNext->pNext = new ListNode(4);
  head->pNext->pNext->pNext->pNext = new ListNode(5);
  head->pNext->pNext->pNext->pNext->pNext = new ListNode(6);
  head->pNext->pNext->pNext->pNext->pNext->pNext = new ListNode(7);
  PrintList(head);
  //PrintList(RelocateList1(head));
  //PrintList(RelocateList2(head));

  return 0;
}
