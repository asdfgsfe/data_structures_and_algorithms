/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if (!head || n < 1)
        {
            return head;
        }
        ListNode* nth = head;
		while (nth && n > 0)
		{
			--n;
			nth = nth->next;
		}
		if (!nth && n == 0)
		{
			nth = head;
			head = head->next;
			delete nth;
			return head;
		}
		if (!nth)
		{
			return head;
		}
		ListNode* after = head;
		while (nth->next)
		{
			nth = nth->next;
			after = after->next;
		}
		nth = after->next;
		assert(nth);
		after->next = nth->next;
		delete nth;
		return head;
    }
};