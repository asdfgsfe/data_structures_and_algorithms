ListNode* FirstInterectNode(ListNode* pHead1, ListNode* pHead2)
{
	if (!pHead1 || !pHead2)
	{
		return nullptr;
	}
	ListNode* pLoop1 = IsLoop(pHead1);
	ListNode* pLoop1 = IsLoop(pHead2);
	if (pLoop1 && pLoop2)
	{
		if (pLoop1 == pLoop2)
		{
			return NoLoopFirstInterectNode(pHead1, pHead2, pLoop1);
		}
		ListNode* pNode = pLoop1->pNext;
		while (pNode != pLoop1)
		{
			if (pNode == pLoop2)
			{
				return pNode;
			}
			pNode = pNode->pNext;
		}
	}
	if (!pLoop1 && !pLoop2)
	{
		return NoLoopFirstInterectNode(pHead1, pHead2, nullptr);
	}
	return nullptr;
}

//这里有bug 用左神的方法 必须从next 和next->next开始
ListNode* IsLoop(const ListNode* pHead)
{
	if (!pHead || !pHead->pNext)
	{
		return nullptr;
	}
	ListNode* pSlow = pHead;
	ListNode* pQuick = pHead->pNext;
	while (pQuick && pQuick != pSlow)
	{
		pSlow = pSlow->pNext;
		pQuick = pQuick->pNext;
		if (pQuick)
		{
			pQuick = pQuick->pNext;
		}
	}
	pQuick = pHead;
	while (pQuick && pQuick != pSlow)
	{
		pQuick = pQuick->pNext;
		pSlow = pSlow->pNext;
	}
	return pQuick;
}

ListNode* NoLoopFirstInterectNode(ListNode* pHead1, ListNode* pHead2, ListNode* pTail)
{
	if (!pHead1 || !pHead2)
	{
		return nullptr;
	}
	int len = 0;
	ListNode* pNode = pHead1;
	while (pNode)
	{
		++len;
		pNode = pNode->pNext;
	}
	pNode = pHead2;
	while (pHead2)
	{
		--len;
		pNode = pNode->pNext;
	}
	ListNode* pLong = len ? pHead1 : pHead2;
	ListNode* pShort = len ? pHead2 : pHead1;
	for (int i = 0; i < std::abs(len); ++i)
	{
		pLong = pLong->pNext;
	}
	while (pLong && pShort && pLong != pShort)
	{
		pLong = pLong->pNext;
		pShort = pShort->pNext;
	}
	return pLong;
}