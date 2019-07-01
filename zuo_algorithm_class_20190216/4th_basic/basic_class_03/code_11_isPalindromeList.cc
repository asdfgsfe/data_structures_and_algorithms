bool IsPalindromeList(ListNode* pHead)
{
	if (!pHead || !pHead->pNext)
	{
		return true;
	}
	ListNode* pSlow = pHead;
	ListNode* pQuick = pHead;
	while (pQuick && pQuick->pNext)
	{
		pSlow = pSlow->pNext;
		pQuick = pQuick->pNext->pNext;
	}
	ListNode* pQuick = ReverseList(pSlow);
	ListNode* pSlow = pQuick;
	while (pHead && pQuick)
	{
		if (pHead->val != pQuick->val)
		{
			return false;
		}
		pHead = pHead->pNext;
		pQuick = pQuick->pNext;
	}
	ReverseList(pSlow);
	return true;
}

ListNode* ReverseList(ListNode* pHead)
{
	if (!pHead || !pHead->pNext)
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