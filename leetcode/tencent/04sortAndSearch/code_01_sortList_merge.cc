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
    ListNode* sortList(ListNode* head) {
        if (!head || !head->next) {
            return head;
        }
        return MergeSort(head);
    }

    ListNode* MergeSort(ListNode* head) {
        if (!head || !head->next) {
            return head;
        }
        ListNode* left = head;
        ListNode* right = head->next->next;
        while (right) {
            left = left->next;
            right = right->next ? right->next->next : nullptr;
        }
        right = left->next;
        left->next = nullptr;
        return Merge(MergeSort(head), MergeSort(right));
    }

    ListNode* Merge(ListNode* lhs, ListNode* rhs) {
        if (!lhs) {
            return rhs;
        }
        if (!rhs) {
            return lhs;
        }
        if (lhs->val <= rhs->val) {
            lhs->next = Merge(lhs->next, rhs);
            return lhs;
        }
        rhs->next = Merge(lhs, rhs->next);
        return rhs;
    }
};

给你链表的头结点 head ，请将其按 升序 排列并返回 排序后的链表 。

进阶：

你可以在 O(n log n) 时间复杂度和常数级空间复杂度下，对链表进行排序吗？


作者：力扣 (LeetCode)
链接：https://leetcode-cn.com/leetbook/read/tencent/x5ip8m/
来源：力扣（LeetCode）
著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。
