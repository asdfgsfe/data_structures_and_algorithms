�������� II
����һ��������������ʼ�뻷�ĵ�һ���ڵ㡣 ��������޻����򷵻� null��

Ϊ�˱�ʾ���������еĻ�������ʹ������ pos ����ʾ����β���ӵ������е�λ�ã������� 0 ��ʼ���� 
��� pos �� -1�����ڸ�������û�л���

˵�����������޸ĸ���������

 

ʾ�� 1��

���룺head = [3,2,0,-4], pos = 1
�����tail connects to node index 1
���ͣ���������һ��������β�����ӵ��ڶ����ڵ㡣

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
//2�ַ��� 1.���Ҫ�ÿ���ÿ����һ�� ����ж���ȵķ��� ����ָ�������ĵ��������������һ���ڵ� �ſ��Բ�Ȼ����ѭ��
//2.����ָ�� ͳ�Ƴ����ϵĽڵ������k ��ͷ�ڵ������ߵ�k�ڵ� Ȼ���ͷ�ڵ��k�ڵ�һ���� ����������ǻ���ڽڵ� ���������ַ������� 
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        if (!head || !head->next || !head->next->next) //����Ҫ
        {
            return nullptr;
        }
        ListNode* quick = head->next->next; //���뵽�������ڵ�
        ListNode* slow = head->next;//����ڶ���
        while (slow != quick)
        {
            if (!slow->next || !quick->next || !quick->next->next) //������ ��ֹcore
            {
                return nullptr;
            }
            slow = slow->next;
            quick = quick->next->next;
        }
        while (head != slow)
        {
            head = head->next;
            slow = slow->next;
        }
        return head;
    }
};
