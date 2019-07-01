//两个链表相交一系列问题 共6中情况
ListNode FindFirstIntersetNode(const ListNode* head1, const ListNode* head2)
{
	if (!head1 || !head2)
	{
		return nullptr;
	}
	const ListNode* loop1 = IsLoop(head1);
	const ListNode* loop2 = IsLoop(hea2);
	if (loop1 && loop2)
	{
		if (loop1 == loop2)
		{
			return NoLoopFirstIntersetNode(head1, head2, loop1);
		}
		const ListNode* cur = loop1->next;
		while (cur != loop2 && cur != loop1)
		{
			assert(cur);
			cur = cur->next;
		}
		return cur == loop2 ? loop2 : nullptr;
	}
	if (!loop1 && !loop1)
	{
		return NoLoopFirstIntersetNode(head1, head2, nullptr)
	}
	return nullptr;
}

ListNode* NoLoopFirstIntersetNode(const ListNode* head1, const ListNode* head2, const ListNode* tail)
{
	if (!head1 || !head2)
	{
		return nullptr;
	}
	int cnt = 0;
	const ListNode* shortNode = head1;
	while (shortNode && shortNode != tail)
	{
		++cnt;
		shortNode = shortNode->next;
	}
	const ListNode* longNode = head2;
	while (longNode && longNode != tail)
	{
		--cnt;
		longNode = longNode->next;
	}
	shortNode = cnt > 0 ? head1 : head2;
	longNode = cnt > 0 ? head2 : head1;
	for (int i = 0; i < std::abs(cnt); ++i)
	{
		longNode = longNode->next;
	}
	while (shortNode && longNode && shortNode != longNode)
	{
		shortNode = shortNode->next;
		longNode = longNode->next;
	}
	return longNode;
}

ListNode* IsLoop(const ListNode* head)
{
	if (!head || !head->next)
	{
		return nullptr;
	}
	const ListNode* quick = head->next;
	const ListNode* slow = head;
	while (quick && slow && quick != slow)
	{
		slow = slow->next;
		quick = quick->next;
		quick = quick ? quick->next : nullptr;
	}
	if (!quick)
	{
		return nullptr;
	}
	while (head != slow)
	{
		assert(head);
		head = head->next;
		slow = slow->next;
	}
	return head;
}