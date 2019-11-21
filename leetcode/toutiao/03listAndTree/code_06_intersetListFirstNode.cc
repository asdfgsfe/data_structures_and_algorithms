相交链表
编写一个程序，找到两个单链表相交的起始节点。
注意：

如果两个链表没有交点，返回 null.
在返回结果后，两个链表仍须保持原有的结构。
可假定整个链表结构中没有循环。
程序尽量满足 O(n) 时间复杂度，且仅用 O(1) 内存。

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
        int cnt = 0;
        ListNode* longHead = headA;
        while (longHead)
        {
            ++cnt;
            longHead = longHead->next;
        }
        ListNode* shortHead = headB;
        while (shortHead)
        {
            --cnt;
            shortHead = shortHead->next;
        }
        longHead = headA;
        shortHead = headB;
        if (cnt < 0)
        {
            longHead = headB;
            shortHead = headA;
        }
        for (int i = 0; i < std::abs(cnt); ++i)
        {
            assert(longHead);
            longHead = longHead->next;
        }
        while (longHead && shortHead && longHead != shortHead)
        {
            longHead = longHead->next;
            shortHead = shortHead->next;
        }
        return longHead;
    }
};