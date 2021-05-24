/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        if (!l1) {
            return l2;
        }
        if (!l2) {
            return l1;
        }
        ListNode* head = nullptr;
        ListNode* tail = nullptr;
        while (l1 && l2) {
            if (l1->val <= l2->val) {
                tail = tail == nullptr ? l1 : tail->next = l1;
                l1 = l1->next;
            } else {
                tail = tail == nullptr ? l2 : tail->next = l2;
                l2 = l2->next;
            }
            head = head == nullptr ? tail : head;
        }
        tail->next = l1 ? l1 : l2;
        return head;
    }
};
