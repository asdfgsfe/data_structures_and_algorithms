void TwoSortedListCommonPart(const ListNode* pHead1, const ListNode* pHead2)
{
	if (pHead1 == nullptr || pHead2 == nullptr)
	{
		return;
	}
	while (pHead1 && pHead2)
	{
		if (pHead1->val == pHead2->val)
		{
			std::cout << pHead1->val << " ";
			pHead1 = pHead1->pNext;
			pHea2 = pHead2->pNext;
		}
		else if (pHead1->val > pHead2->val)
		{
			pHead2 = pHead2->pNext;
		}
		else
		{
			pHead1 = pHead1->pNext;
		}
	}
}