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
        ListNode* right = head->next->next;
        ListNode* left = head;
        while (right) {
            left = left->next;
            right = right->next ? right->next->next :  nullptr;
        }
        right = left->next;
        left->next = nullptr;
        return Merge(MergeSort(head), MergeSort(right));
    }

    ListNode* Merge(ListNode* l, ListNode* r) {
        if (!l) {
            return r;
        }
        if (!r) {
            return l;
        }
        ListNode* h = nullptr;
        ListNode* t = nullptr;
        while (l && r) {
            if (l->val <= r->val) {
                t = t == nullptr ? l : t->next = l;
                l = l->next;
            } else {
                t = t == nullptr ? r : t->next = r;
                r = r->next;
            }
            h = h == nullptr ? t : h;
        }
        t->next = l ? l : r;
        return h;
    }
};

148. 排序链表
给你链表的头结点 head ，请将其按 升序 排列并返回 排序后的链表 。

进阶：

你可以在 O(n log n) 时间复杂度和常数级空间复杂度下，对链表进行排序吗？


示例 1：


输入：head = [4,2,1,3]
输出：[1,2,3,4]
示例 2：


输入：head = [-1,5,3,4,0]
输出：[-1,0,3,4,5]
示例 3：

输入：head = []
输出：[]


提示：

链表中节点的数目在范围 [0, 5 * 104] 内
-105 <= Node.val <= 105
