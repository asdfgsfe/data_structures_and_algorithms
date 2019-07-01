#include <iostream>

struct DoubleList
{
  int val;
  DoubleList* pNext;
  DoubleList* pPre;
  DoubleList(int v)
    : val(v), pNext(nullptr), pPre(nullptr)
    {}
};

DoubleList* ReverseList(DoubleList* pHead)
{
  if (pHead == nullptr || pHead->pNext == nullptr)
  {
    return pHead;
  }
  DoubleList* pPre = nullptr;
  while (pHead)
  {
    DoubleList* pNext = pHead->pNext;
    pHead->pNext = pPre;
    pHead->pPre = pNext;
    pPre = pHead;
    pHead = pNext;
  }
  return pPre;
}

void PrintList(const DoubleList* pHead)
{
  const DoubleList* pNode = pHead;
  while (pHead)
  {
    std::cout << pHead->val << " ";
    if (pHead->pNext)
    {
      pNode = pHead->pNext;
    }
    pHead = pHead->pNext;
  }
  std::cout << std::endl;
  while (pNode)
  {
    std::cout << pNode->val << " ";
    pNode = pNode->pPre;
  }
  std::cout << std::endl;
}

int main(void)
{
  DoubleList* pHead = new DoubleList(1);
  DoubleList* pNode = new DoubleList(2);
  pHead->pNext = pNode;
  pNode->pPre = pHead;
  
  pNode = new DoubleList(3);
  pHead->pNext->pNext = pNode;
  pNode->pPre = pHead->pNext;

  pNode = new DoubleList(4);
  pHead->pNext->pNext->pNext = pNode;
  pNode->pPre = pHead->pNext->pNext;

  pNode = new DoubleList(5);
  pHead->pNext->pNext->pNext->pNext = pNode;
  pNode->pPre = pHead->pNext->pNext->pNext;

  PrintList(pHead);
  std::cout << std::endl;
  pNode = ReverseList(pHead);
  PrintList(pNode);  

  return 0;
}
