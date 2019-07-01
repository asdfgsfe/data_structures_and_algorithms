#include <iostream>

struct List
{
  int val;
  List* next;

  List(int value)
    : val(value), next(nullptr)
  {}
};

void Relocate(List* pHead)
{
  if (pHead == nullptr || pHead->next == nullptr)
  {
    return;
  }
  List* pQuick = pHead;
  List* pSlow = pHead;
  while (pQuick != nullptr && pQuick->next != nullptr)
  {
    pSlow = pSlow->next;
    pQuick = pQuick->next;
    if (pQuick != nullptr)
    {
      pQuick = pQuick->next;
    }
  }
  if (pQuick == pSlow)
  {
    return;
  }
  List* pMidNode = pSlow;
  pQuick = pSlow;
  pSlow = pHead;
  while (pSlow != pMidNode && pQuick != nullptr)
  {
    List* pSlowNext = pSlow->next;
    pSlow->next = pQuick;
    List* pQuickNext = pQuick->next;
    if (pSlowNext != pMidNode)
    {
      pQuick->next = pSlowNext;
    }

    pSlow = pSlowNext;
    pQuick = pQuickNext;
  }
}

void PrintList(List* pHead)
{
  std::cout << "list:[";
  while (pHead != nullptr)
  {
    std::cout << pHead->val << "->";
    pHead = pHead->next;
  }
  std::cout << "null]" <<std::endl;
}

void MergeLR(List* pLeft, List* pRight)
{
  while (pLeft->next != nullptr)
  {
    List* pNext = pRight->next;
    pRight->next = pLeft->next;
    pLeft->next = pRight;
    pLeft = pRight->next;
    pRight = pNext;
  }
  pLeft->next = pRight;
}

void Relocate2(List* pHead)
{
  if (pHead == nullptr || pHead->next == nullptr)
  {
    return;
  }
  List* pSlow = pHead;
  List* pQuick = pHead->next;
  while (pQuick->next != nullptr && pQuick->next->next != nullptr)
  {
    pSlow = pSlow->next;
    pQuick = pQuick->next->next;
  }
  pQuick = pSlow->next;
  pSlow->next = nullptr;
  MergeLR(pHead, pQuick);
}

int main(void)
{
  List* head = nullptr;
  Relocate(head);
  PrintList(head);

  head = new List(1);
  Relocate(head);
  PrintList(head);

  head = new List(1);
  head->next = new List(2);
  Relocate(head);
  PrintList(head);

  head = new List(1);
  head->next = new List(2);
  head->next->next = new List(3);
  Relocate(head);
  PrintList(head);

  head = new List(1);
  head->next = new List(2);
  head->next->next = new List(3);
  head->next->next->next = new List(4);
  Relocate(head);
  PrintList(head);

  head = new List(1);
  head->next = new List(2);
  head->next->next = new List(3);
  head->next->next->next = new List(4);
  head->next->next->next->next = new List(5);
  Relocate(head);
  PrintList(head);

  head = new List(1);
  head->next = new List(2);
  head->next->next = new List(3);
  head->next->next->next = new List(4);
  head->next->next->next->next = new List(5);
  head->next->next->next->next->next = new List(6);
  Relocate(head);
  PrintList(head);

  head = new List(1);
  head->next = new List(2);
  head->next->next = new List(3);
  head->next->next->next = new List(4);
  head->next->next->next->next = new List(5);
  head->next->next->next->next->next = new List(6);
  head->next->next->next->next->next->next = new List(7);
  Relocate(head);
  PrintList(head);

  head = nullptr;
  Relocate2(head);
  PrintList(head);

  head = new List(1);
  Relocate2(head);
  PrintList(head);

  head = new List(1);
  head->next = new List(2);
  Relocate2(head);
  PrintList(head);

  head = new List(1);
  head->next = new List(2);
  head->next->next = new List(3);
  Relocate2(head);
  PrintList(head);

  head = new List(1);
  head->next = new List(2);
  head->next->next = new List(3);
  head->next->next->next = new List(4);
  Relocate2(head);
  PrintList(head);

  head = new List(1);
  head->next = new List(2);
  head->next->next = new List(3);
  head->next->next->next = new List(4);
  head->next->next->next->next = new List(5);
  Relocate2(head);
  PrintList(head);

  head = new List(1);
  head->next = new List(2);
  head->next->next = new List(3);
  head->next->next->next = new List(4);
  head->next->next->next->next = new List(5);
  head->next->next->next->next->next = new List(6);
  Relocate2(head);
  PrintList(head);

  head = new List(1);
  head->next = new List(2);
  head->next->next = new List(3);
  head->next->next->next = new List(4);
  head->next->next->next->next = new List(5);
  head->next->next->next->next->next = new List(6);
  head->next->next->next->next->next->next = new List(7);
  Relocate2(head);
  PrintList(head);

  return 0;
}





