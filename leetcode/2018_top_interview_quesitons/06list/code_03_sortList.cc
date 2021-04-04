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
        while (right->next)
        {
            left = left->next;
            right = right->next;
            if (right->next)
            {
                right = right->next;
            }
        }
        right = left->next;
        left->next = nullptr;
        left = head;
        return Merge(sortList(left), sortList(right));
    }

    //递归的merge两个链表 否则归并的时候 要注意两个链表断开的问题
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
        ListNode* head = nullptr;
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


