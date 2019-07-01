#include <iostream>
#include <stack>

using std::stack;

struct List
{
  int val;
  List* next;
  List(int v) : val(v), next(nullptr){}
};

void PrintList(const List* pHead)
{
  while (pHead)
  {
    std::cout << pHead->val << "->";
    pHead = pHead->next;
  }
  std::cout << "null" << std::endl;
}

bool IsPalindromeList1(const List* pHead)
{
  stack<const List*> st;
  const List* pNode = pHead;
  while (pNode)
  {
    st.push(pNode);
    pNode = pNode->next;
  }
  while (!st.empty() && pHead)
  {
    if (st.top()->val != pHead->val)
    {
      return false;
    }
    st.pop();
    pHead = pHead->next;
  }
  return true;
}

bool IsPalindromeList2(const List* pHead)
{
  stack<const List*> st;
  const List* pQuick = pHead;
  const List* pSlow = pHead;
  while (pQuick && pQuick->next)
  {
    pSlow = pSlow->next;
    pQuick = pQuick->next;
    pQuick = pQuick ? pQuick->next : pQuick;
  }
  if (pSlow)
    //std::cout << pSlow->val << std::endl;
  pQuick = pSlow;
  while (pSlow)
  {
    st.push(pSlow);
    pSlow = pSlow->next;
  }
  while (!st.empty() && pHead != pQuick)
  {
    if (st.top()->val != pHead->val)
    {
      return false;
    }
    st.pop();
    pHead = pHead->next;
  }
  return true;
}

List* ReverseList(List* pHead)
{
  List* pPreNode = nullptr;
  while (pHead)
  {
    List* pNext = pHead->next;
    pHead->next = pPreNode;
    pPreNode = pHead;
    pHead = pNext;
  }
  return pPreNode;
}

bool IsPalindromeList3(List* pHead)
{
  List* pQuick = pHead;
  List* pSlow = pHead;
  while (pQuick && pQuick->next)
  {
    pSlow = pSlow->next;
    pQuick = pQuick->next;
    pQuick = pQuick ? pQuick->next : pQuick;
  }
  if (pSlow)
    //std::cout << pSlow->val << std::endl;
  pQuick = nullptr;
  while (pSlow)
  {
    List* pNext = pSlow->next;
    pSlow->next = pQuick;
    pQuick = pSlow;
    pSlow = pNext;
  }
  pSlow = pQuick;
  while (pQuick && pHead)
  {
    if (pQuick->val != pHead->val)
    {
     return false;
    }
    pQuick = pQuick->next;
    pHead = pHead->next;
  }
  pQuick = nullptr;
  while (pSlow)
  {
    List* pNext = pSlow->next;
    pSlow->next = pQuick;
    pQuick = pSlow;
    pSlow = pNext;
  }
  return true;
}

int main(void)
{
  List* head = nullptr;
  PrintList(head);
  std::cout << IsPalindromeList1(head) << " | ";
  std::cout << IsPalindromeList2(head) << " | ";
  std::cout << IsPalindromeList3(head) << " | " << std::endl;
  PrintList(head);
  std::cout << "=========================" << std::endl;

  head = new List(1);
  PrintList(head);
  std::cout << IsPalindromeList1(head) << " | ";
  std::cout << IsPalindromeList2(head) << " | ";
  std::cout << IsPalindromeList3(head) << " | " << std::endl;
  PrintList(head);
  std::cout << "=========================" << std::endl;

  head = new List(1);
  head->next = new List(2);
  PrintList(head);
  std::cout << IsPalindromeList1(head) << " | ";
  std::cout << IsPalindromeList2(head) << " | ";
  std::cout << IsPalindromeList3(head) << " | " << std::endl;
  PrintList(head);
  std::cout << "=========================" << std::endl;

  head = new List(1);
  head->next = new List(1);
  PrintList(head);
  std::cout << IsPalindromeList1(head) << " | ";
  std::cout << IsPalindromeList2(head) << " | ";
  std::cout << IsPalindromeList3(head) << " | " << std::endl;
  PrintList(head);
  std::cout << "=========================" << std::endl;

  head = new List(1);
  head->next = new List(2);
  head->next->next = new List(3);
  PrintList(head);
  std::cout << IsPalindromeList1(head) << " | ";
  std::cout << IsPalindromeList2(head) << " | ";
  std::cout << IsPalindromeList3(head) << " | " << std::endl;
  PrintList(head);
  std::cout << "=========================" << std::endl;

  head = new List(1);
  head->next = new List(2);
  head->next->next = new List(1);
  PrintList(head);
  std::cout << IsPalindromeList1(head) << " | ";
  std::cout << IsPalindromeList2(head) << " | ";
  std::cout << IsPalindromeList3(head) << " | " << std::endl;
  PrintList(head);
  std::cout << "=========================" << std::endl;

  head = new List(1);
  head->next = new List(2);
  head->next->next = new List(3);
  head->next->next->next = new List(1);
  PrintList(head);
  std::cout << IsPalindromeList1(head) << " | ";
  std::cout << IsPalindromeList2(head) << " | ";
  std::cout << IsPalindromeList3(head) << " | " << std::endl;
  PrintList(head);
  std::cout << "=========================" << std::endl;

  head = new List(1);
  head->next = new List(2);
  head->next->next = new List(2);
  head->next->next->next = new List(1);
  PrintList(head);
  std::cout << IsPalindromeList1(head) << " | ";
  std::cout << IsPalindromeList2(head) << " | ";
  std::cout << IsPalindromeList3(head) << " | " << std::endl;
  PrintList(head);
  std::cout << "=========================" << std::endl;

  head = new List(1);
  head->next = new List(2);
  head->next->next = new List(3);
  head->next->next->next = new List(2);
  head->next->next->next->next = new List(1);
  PrintList(head);
  std::cout << IsPalindromeList1(head) << " | ";
  std::cout << IsPalindromeList2(head) << " | ";
  std::cout << IsPalindromeList3(head) << " | " << std::endl;
  PrintList(head);
  std::cout << "=========================" << std::endl;
  return 0;
}
