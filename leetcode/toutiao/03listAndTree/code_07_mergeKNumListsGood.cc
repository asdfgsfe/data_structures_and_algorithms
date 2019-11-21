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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        ListNode* head = nullptr;
        for (ListNode* list : lists)
        {
            head = MergeTwoLists(head, list);
        }
        return head;
    }
    
    ListNode* MergeTwoLists(ListNode* lhs, ListNode* rhs)
    {
        if (!lhs)
        {
            return rhs;
        }
        if (!rhs)
        {
            return lhs;
        }
        if (lhs->val <= rhs->val)
        {
            lhs->next = MergeTwoLists(lhs->next, rhs);
            return lhs;
        }
        else
        {
            rhs->next = MergeTwoLists(lhs, rhs->next);
            return rhs;
        }
    }
};
