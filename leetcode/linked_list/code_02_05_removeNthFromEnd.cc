//删除链表的倒数第N个节点
//给你一个链表，删除链表的倒数第 n 个结点，并且返回链表的头结点。

//进阶：你能尝试使用一趟扫描实现吗？



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
        //after->next是倒数第n个节点
		nth = after->next;
		assert(nth);
		after->next = nth->next;
		delete nth;
		return head;
    }
};
