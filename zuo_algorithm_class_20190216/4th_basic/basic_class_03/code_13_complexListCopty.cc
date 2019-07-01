#include <iostream>

struct ListNode 
{
	int value;
	ListNode* pNext;
	ListNode* pRandom;

	ListNode(int v)
		: value(v), pNext(nullptr), pRandom(nullptr)
	{}
}

ListNode* ComplexListCopy(ListNode* pHead)
{
	if (!pHead)
	{
		return nullptr;
	}
	ListNode* pCur = pHead;
	while (pCur)
	{
		ListNode* pNext = pHead->pNext;
		ListNode* pNode = new ListNode(pHead->val);
		pHead->pNext = pNode;
		pNode->pNext = pNext;
		pHead = pNext;
	}
	pCur = pHead;
	while (pCur && pCur->pNext)
	{
		if (pCur->pRandom)
		{
			pCur->pNext->pRandom = pCur->pRandom->pNext;
		}
		pCur = pCur->pNext->pNext;
	}
	pCur = pHead->pNext;
	ListNode* pNewHead = pHead->pNext;
	while (pHead && pCur)
	{
		ListNode* pNext = pCur->pNext;
		pHead->pNext = pNext;
		pHead = pCur;
		pCur = pNext;
	}
	return pNewHead;
}