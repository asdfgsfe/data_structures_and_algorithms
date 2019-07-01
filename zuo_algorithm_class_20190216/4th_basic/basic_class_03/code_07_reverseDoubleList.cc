DoubleListNode* ReverseDoubleList(DoubleListNode* pHead)
{
	if (!pHead || !pHead->pNext)
	{
		return pHead;
	}
	DoubleListNode* pPre = nullptr;
	while (pHead)
	{
		DoubleListNode* pNext = pHead->pNext;
		pHead->pNext = pPre;
		pHead->pPre = pNext;
		pPre = pHead;
		pHead = pNext;
	}
	return pPre;
}