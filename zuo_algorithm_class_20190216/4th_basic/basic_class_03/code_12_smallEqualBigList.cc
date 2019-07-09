ListNode* PartitionList(ListNode* pHead, int pivot)
{
	if (!pHead || !pHead->pNext)
	{
		return pHead;
	}
	ListNode* sH = nullptr;
	ListNode* sE = nullptr;
	ListNode* eH = nullptr;
	ListNode* eE = nullptr;
	ListNode* bH = nullptr;
	ListNode* bE = nullptr;
	while (pHead)
	{
		ListNode* pNext = pHead->pNext;
		pHead->pNext = nullptr;
		if (pHead->val < pivot)
		{
			if (!sH)
			{
				sH = pHead;
				sE = pHead;
			}
			else
			{
				assert(sE);
				sE->pNext = pHead;
				sE = pHead;
			}
		}
		else if (pHead->val == pivot)
		{
			if (!eH)
			{
				eH = pHead;
				eE = pHead;
			}
			else
			{
				assert(eE);
				eE->pNext = pHead;
				eE = pHead;
			}
		}
		else
		{
			if (!bH)
			{
				bH = pHead;
				bE = pHead;
			}
			else
			{
				bE->pNext = pHead;
				bE = pHead;			
			}
		}
		pHead = pNext;
	}
	if (sE)
	{
		sE->pNext = eH;
		eE = eE ? eE : sE;
	}
	if (eE)
	{
		eE->pNext = bH;
	}
	return sH ? sH : eH ? eH : bH;
}