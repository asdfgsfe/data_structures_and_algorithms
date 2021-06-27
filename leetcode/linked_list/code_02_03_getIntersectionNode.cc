相交链表
给你两个单链表的头节点 headA 和 headB ，请你找出并返回两个单链表相交的起始节点。如果两个链表没有交点，返回 null 。


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
    ListNode *detectCycle(ListNode *head) {
        if (!head || !head->next) {
            return nullptr;
        }
        ListNode* slow = head;
        ListNode* quick = head->next;
        while (quick && quick != slow) {
            slow = slow->next;
            quick = quick->next ? quick->next->next : nullptr;
        }
        if (!quick) {
            return nullptr;
        }
        int size = 1;
        quick = quick->next;
        while (quick != slow) {
            ++size;
            quick = quick->next;
        }
        quick = head;
        for (int i = 0; i < size; ++i) {
            quick = quick->next;
        }
        slow = head;
        while (slow != quick) {
            slow = slow->next;
            quick = quick->next;
        }
        return quick;
    }
};
