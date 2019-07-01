#include <iostream>

struct List
{
  int val;
  List* next;
  List (int v) 
    : val(v), next(nullptr)
  {}
};

void PrintCommonPart(const List* pHead1, const List* pHead2)
{
  while (pHead1 != nullptr && pHead2 != nullptr)
  {
    if (pHead1->val < pHead2->val)
    {
      pHead1 = pHead1->next;
    }
    else if (pHead2->val < pHead1->val)
    {
      pHead2 = pHead2->next;
    }
    else
    {
      std::cout << pHead1->val << " ";
      pHead1 = pHead1->next;
      pHead2 = pHead2->next;
    }
  }
  std::cout << std::endl;
}

void PrintList(const List* pHead)
{
  while (pHead != nullptr)
  {
    std::cout << pHead->val << " ";
    pHead = pHead->next;
  }
  std::cout << std::endl;
}

int main(void)
{
  List* node1 = new List(2);
  node1->next = new List(3);
  node1->next->next = new List(5);
  node1->next->next->next = new List(6);

  List* node2 = new List(1);
  node2->next = new List(2);
  node2->next->next = new List(5);
  node2->next->next->next = new List(7);
  node2->next->next->next->next = new List(8);
  PrintList(node1);
  PrintList(node2);
  PrintCommonPart(node1, node2);

  return 0;
}
