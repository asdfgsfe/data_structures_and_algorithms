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
    int getDecimalValue(ListNode* head) {
        if (!head)
        {
            return 0;
        }
        long long num = 0;
        while (head)
        {
            num = num * 2 + (head->val);
            head = head->next;
        }
        return (int)num;
    }
};