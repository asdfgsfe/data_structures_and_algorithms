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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        if (!headA || !headB) {
            return nullptr;
        }
        int cnt = 0;
        ListNode* node = headA;
        while (node) {
            ++cnt;
            node = node->next;
        }
        node = headB;
        while (node) {
            --cnt;
            node = node->next;
        }
        ListNode* l = headA;
        ListNode* s = headB;
        if (cnt < 0) {
            l = headB;
            s = headA;
        }
        for (int i = 0; i < std::abs(cnt); ++i) {
            l = l->next;
        }
        while (l && s && l != s) {
            l = l->next;
            s = s->next;
        }
        return l;
    }
};
