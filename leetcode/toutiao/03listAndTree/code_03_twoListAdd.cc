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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        if (!l1)
        {
            return l2;
        }
        if (!l2)
        {
            return l1;
        }
        ListNode* sum = l2;
        while (l1)
        {
            AddOneNum(sum, l1->val);
            l1 = l1->next;
            if (l1 && !sum->next)
            {
                sum->next = new ListNode(0);
            }
            sum = sum->next;
        }
        return l2;
    }
    
    void AddOneNum(ListNode* head, int num)
    {
        if (!head || num > 9)
        {
            return;
        }
        while (1)
        {
            int cur = head->val + num;
            head->val = cur % 10;
            if (cur < 10)
            {
                break;
            }
            num = cur / 10;
            if (!head->next)
            {
                head->next = new ListNode(0);
            }
            head = head->next;
        }
    }
};
