#include <iostream>

struct ListNode
{
  int val;
  ListNode* pNext;
  ListNode(int v)
    : val(v), pNext(nullptr)
  {}
};

void PrintList(const ListNode* pHead)
{
  while (pHead)
  {
    std::cout << pHead->val << " ";
  }
  std::cout << std::endl;
}

ListNode* ReverseList(ListNode* pHead)
{
  if (pHead == nullptr || pHead->pNext == nullptr)
  {
    return pHead;
  }
  ListNode* pPreNode = nullptr;
  while (pHead)
  {
    ListNode* pNode = pHead->pNext;
    pHead->pNext = pPreNode;
    pPreNode = pHead;
    pHead = pNode;
  }
  return pPreNode;
}

bool IsPalindromeList(ListNode* pHead)
{
  if (pHead == nullptr || pHead->pNext == nullptr)
  {
    return true;
  }
  ListNode* pQuickNode = pHead;
  ListNode* pSlowNode = pHead;
  while (pQuickNode && pQuickNode->pNext)
  {
    pSlowNode = pSlowNode->pNext;
    pQuickNode = pQuickNode->pNext;
    //if (pQuickNode) 
    {
      pQuickNode = pQuickNode->pNext;
    }
  }
  pSlowNode = ReverseList(pSlowNode);
  ListNode* pReverseHead = pSlowNode;
  pQuickNode = pHead;
  bool isPalindrome = true;
  while (pQuickNode && pSlowNode)
  {
    if (pQuickNode->val != pSlowNode->val)
    {
      isPalindrome = false;
      break;
    }
    pQuickNode = pQuickNode->pNext;
    pSlowNode = pSlowNode->pNext;
  }
  ReverseList(pReverseHead);
  return isPalindrome;
}

int main(void)
{
  ListNode* head = new ListNode(1);
  head->pNext = new ListNode(2);
  head->pNext->pNext = new ListNode(3);
  std::cout << IsPalindromeList(head) << std::endl;

  return 0;
}
