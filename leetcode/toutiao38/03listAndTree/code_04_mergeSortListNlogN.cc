 排序链表
在 O(n log n) 时间复杂度和常数级空间复杂度下，对链表进行排序。

示例 1:

输入: 4->2->1->3
输出: 1->2->3->4
示例 2:

输入: -1->5->3->4->0
输出: -1->0->3->4->5

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
    ListNode* sortList(ListNode* head) {
        if (!head || !head->next)
        {
            return head;
        }
        ListNode* left = head;
        ListNode* right = head->next;
        while (right && right->next)
		{
			left = left->next;
			right = right->next;
			if (right)
			{
				right = right->next;
			}
		}
		right = left->next;
		left->next = nullptr;
		left = head;
        left = sortList(left);
        right = sortList(right);
        return Merge(left, right);
    }

	ListNode* Merge(ListNode* lhs, ListNode* rhs)
	{
		if (!lhs)
		{
			return rhs;
		}
		if (!rhs)
		{
			return lhs;
		}
		ListNode* head;
		if (lhs->val <= rhs->val)
		{
			head = lhs;
			head->next = Merge(lhs->next, rhs);
		}
		else
		{
			head = rhs;
			head->next = Merge(lhs, rhs->next);
		}
		return head;
	}
};