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
    ListNode* rotateRight(ListNode* head, int k) {
        if (!head || !head->next || k < 1)
        {
            return head;
        }
		int size = 0;
		ListNode* newHead = ReverseList(head, nullptr, size);
		if (k >= size && (k % size) == 0)
		{
			return ReverseList(newHead, nullptr, size);
		}
		k = k % size;
		ListNode* node = newHead;
		ListNode* pre = nullptr;
		while (k > 0)
		{
			--k;
			ListNode* next = node->next;
			node->next = pre;
			pre = node;
			node = next;
		}
		head = ReverseList(node, nullptr, size);
		newHead->next = head;
        return pre;
    }

	ListNode* ReverseList(ListNode* head, ListNode* tail, int& size)
	{
		size = 0;
		ListNode* pre = tail;
		while (head != tail)
		{
			++size;
			ListNode* next = head->next;
			head->next = pre;
			pre = head;
			head = next;
		}
		return pre;
	}
};