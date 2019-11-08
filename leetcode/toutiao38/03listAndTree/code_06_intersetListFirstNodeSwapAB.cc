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
        if (!headA || !headB)
        {
            return nullptr;
        } 
        if (headA == headB)
        {
            return headA;
        }
        ListNode* node = headA;
        int k = 0;
        while (node)
        {
            ++k;
            node = node->next;
        }
        node = headB;
        while (node)
        {
            --k;
            node = node->next;
        }
        if (k < 0)
        {
            std::swap(headA, headB);
        }
        for (int i = 0; i < std::abs(k); ++i)
        {
            headA = headA->next;
        }
        while (headA && headB)
        {
            if (headA == headB)
            {
                return headA;
            }
            headA = headA->next;
            headB = headB->next;
        }
        if (k < 0)
        {
            std::swap(headA, headB);
        }
        return nullptr;
    }
};
