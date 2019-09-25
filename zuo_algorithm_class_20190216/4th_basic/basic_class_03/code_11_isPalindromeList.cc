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
	//注意这里不断开链表 仅仅只是翻转 如果断开后翻转 最后需要连接
	ListNode* pQuick = ReverseList(pSlow);
	ListNode* pSlow = pQuick;
	bool isPalindrome = true;
	while (pHead && pQuick)
	{
		if (pHead->val != pQuick->val)
		{
			isPalindrome = false;
			break;
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