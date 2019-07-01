ListNode* ReverseList(ListNode* pHead)
{
	if (pHead == nullptr || pHead->pNext == nullptr)
	{
		return pHead;
	}
	ListNode* pPre = nullptr;
	while (pHead)
	{
		ListNode* pNext = pHead->pNext;
		pHead->pNext = pPre;
		pPre = pHead;
		pHead = pNext;
	}
	return pPre;
}