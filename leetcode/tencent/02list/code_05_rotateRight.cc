 ��ת����
����һ��������ת����������ÿ���ڵ������ƶ� k ��λ�ã����� k �ǷǸ�����

ʾ�� 1:

����: 1->2->3->4->5->NULL, k = 2
���: 4->5->1->2->3->NULL
����:
������ת 1 ��: 5->1->2->3->4->NULL
������ת 2 ��: 4->5->1->2->3->NULL
ʾ�� 2:

����: 0->1->2->NULL, k = 4
���: 2->0->1->NULL
����:
������ת 1 ��: 2->0->1->NULL
������ת 2 ��: 1->2->0->NULL
������ת 3 ��: 0->1->2->NULL
������ת 4 ��: 2->0->1->NULL

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
    ListNode* rotateRight(ListNode* head, int k) {
        if (!head || !head->next || k < 1)
        {
            return head;
        }
        int size = 0;
        ListNode* node = head;
        while (node)
        {
            ++size;
            node = node->next;
        }
        if (k >= size && (k % size) == 0)
        {
            return head;
        }
        k = k % size;
        ListNode* newHead = ReverseList(head, nullptr);
        node = newHead;
        while (k > 0)
        {
            --k;
            node = node->next;
        }
        head = ReverseList(node, nullptr);
        node = ReverseList(newHead, node);
        newHead->next = head;
        return node;
    }
    
    ListNode* ReverseList(ListNode* head, ListNode* tail)
    {
        if (!head || !head->next)
        {
            return head;
        }
        ListNode* pre = tail;
        while (head != tail)
        {
            ListNode* next = head->next;
            head->next = pre;
            pre = head;
            head = next;
        }
        return pre;
    }
};