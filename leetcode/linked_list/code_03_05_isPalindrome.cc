class Solution {
public:
	bool isPalindrome(ListNode* head) {
		if (!head || !head->next)
		{
			return true;
		}
		int n = 0;
		ListNode* node = head;
		while (node)
		{
			++n;
			node = node->next;
		}
		n /= 2;
		ListNode* mid = head;
		while (n-- > 0)
		{
			mid = mid->next;
		}
		node = ReverseList(mid);
		mid = node;
		n /= 2;
		bool status = true;
		while (node && head)
		{
			if (node->val != head->val)
			{
				status = false;
				break;
			}
			node = node->next;
			head = head->next;
		}
		ReverseList(mid);
		return status;
	}

	ListNode* ReverseList(ListNode* head)
	{
		if (!head || !head->next)
		{
			return head;
		}
		ListNode* pre = nullptr;
		while (head)
		{
			ListNode* next = head->next;
			head->next = pre;
			pre = head;
			head = next;
		}
		return pre;
	}
};