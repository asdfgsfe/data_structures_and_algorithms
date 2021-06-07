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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        if (!l1)
        {
            return l2;
        }
        if (!l2)
        {
            return l1;
        }
        ListNode* newHead = l1->val <= l2->val ? l1 : l2;
        while (l1 && l2)
        {
            if (l1->val <= l2->val)
            {
                while (l1->next && l1->next->val <= l2->val)
                {
                    l1 = l1->next;
                }
                ListNode* next = l1->next;
                l1->next = l2;
                l1 = next;
            }
            else
            {
                while (l2->next && l2->next->val <= l1->val)
                {
                    l2 = l2->next;
                }
                ListNode* next = l2->next;
                l2->next = l1;
                l2 = next;
            }
        }
        return newHead;
    }
};

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

//比较完美的代码写法 设置一个头节点和尾节点 然后去串联整个脸表
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
        //容易丢
        tail->next = l1 ? l1 : l2;
        return head;
    }
};
