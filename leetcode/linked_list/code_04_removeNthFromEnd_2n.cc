删除链表的倒数第N个节点
给你一个链表，删除链表的倒数第 n 个结点，并且返回链表的头结点。

进阶：你能尝试使用一趟扫描实现吗？

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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if (n < 1 || !head) {
            return head;
        }
        int size = 0;
        ListNode* node = head;
        while (node) {
            node = node->next;
            ++size;
        }
        int k = size - n;
        if (k < 0) {
            return head;
        }
        if (k == 0) {
            node = head->next;
            head->next = nullptr;
            return node;
        }
        node = head;
        for (int i = 0; i < k - 1; ++i) {
            node = node->next;
        }
        ListNode* tmp = node->next;
        node->next = node->next->next;
        tmp->next = nullptr;
        return head;
    }
};
