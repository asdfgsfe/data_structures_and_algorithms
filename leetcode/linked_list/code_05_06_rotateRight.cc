//旋转链表
//给你一个链表的头节点 head ，旋转链表，将链表每个节点向右移动 k 个位置。



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
    ListNode* rotateRight(ListNode* head, int k) {
        if (k < 1 || !head || !head->next) {
            return head;
        }
        int size = 0;
        ListNode* node = head;
        while (node) {
            ++size;
            node = node->next;
        }
        k %= size;
        if (k == 0) {
            return head;
        }
        head = ReverseList(head, nullptr);
        node = head;
        for (int i = 0; i < k; ++i) {
            node = node->next;
        }
        ListNode* lH = ReverseList(head, node);
        ListNode* rH = ReverseList(node, nullptr);
        head->next = rH;
        return lH;
    }

    ListNode* ReverseList(ListNode* head, ListNode* tail) {
        if (!head || head == tail) {
            return head;
        }
        ListNode* pre = tail;
        while (head != tail) {
            ListNode* next = head->next;
            head->next = pre;
            pre = head;
            head = next;
        }
        return pre;
    }
};
