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
    ListNode* reverseList(ListNode* head) {
        if (!head || !head->next)
        {
            return head;
        }
        ListNode* newHead = reverseList(head->next);
        head->next->next = head; //head->next 表示以head->next为头反转后的链表
        head->next = nullptr;
        return newHead;
    }
};
