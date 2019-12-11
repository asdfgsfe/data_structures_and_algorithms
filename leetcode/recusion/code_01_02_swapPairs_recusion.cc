class Solution {
public:
	ListNode * swapPairs(ListNode* head) {
		if (!head || !head->next)
		{
			return head;
		}
		ListNode* second = head->next;
		ListNode* next = second->next;
		second->next = head;
		head->next = swapPairs(next);
		return second;
	}
};