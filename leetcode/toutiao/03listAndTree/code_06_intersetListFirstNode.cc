�ཻ����
��дһ�������ҵ������������ཻ����ʼ�ڵ㡣
ע�⣺

�����������û�н��㣬���� null.
�ڷ��ؽ���������������뱣��ԭ�еĽṹ��
�ɼٶ���������ṹ��û��ѭ����
���������� O(n) ʱ�临�Ӷȣ��ҽ��� O(1) �ڴ档

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