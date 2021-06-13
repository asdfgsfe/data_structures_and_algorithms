//2. 两数相加

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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        if (!l1) {
            return l2;
        }
        if (!l2) {
            return l1;
        }
        ListNode* base = nullptr;
        ListNode* tail = nullptr;
        while (l1) {
            ListNode* node = new ListNode(l1->val);
            tail = tail ? tail->next = node : node;
            base = base ? base : node;
            l1 = l1->next;
        }
        tail = base;
        while (l2) {
            AddOneNum(tail, l2->val);
            l2 = l2->next;
            if (l2 && !tail->next) {
                tail->next = new ListNode(0);
            }
            tail = tail->next;
        }
        return base;
    }

    void AddOneNum(ListNode* base, int n) {
        while (base) {
            int val = base->val + n;
            base->val = val % 10;
            if (val < 10) {
                return;
            }
            if (!base->next) {
                base->next = new ListNode(0);
            }
            base = base->next;
            n = 1;
        }
    }
};
