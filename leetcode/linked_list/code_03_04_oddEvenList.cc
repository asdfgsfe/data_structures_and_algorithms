//��ż����
//����һ�������������е������ڵ��ż���ڵ�ֱ�����һ��
//��ע�⣬����������ڵ��ż���ڵ�ָ���ǽڵ��ŵ���ż�ԣ������ǽڵ��ֵ����ż�ԡ�
//�볢��ʹ��ԭ���㷨��ɡ�����㷨�Ŀռ临�Ӷ�ӦΪ O(1)��ʱ�临�Ӷ�ӦΪ O(nodes)��nodes Ϊ�ڵ�������
//ʾ�� 1:
//����: 1->2->3->4->5->NULL
//���: 1->3->5->2->4->NULL
//ʾ�� 2:
//����: 2->1->3->5->6->4->7->NULL 
//���: 2->3->6->7->1->5->4->NULL
//˵��:
//Ӧ�����������ڵ��ż���ڵ�����˳��
//����ĵ�һ���ڵ���Ϊ�����ڵ㣬�ڶ����ڵ���Ϊż���ڵ㣬�Դ����ơ�


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
	ListNode * oddEvenList(ListNode* head) {
		if (!head || !head->next)
		{
			return head;
		}
		bool odd = true;
		ListNode* oddH = nullptr;
		ListNode* oddT = nullptr;
		ListNode* evenH = nullptr;
		ListNode* evenT = nullptr;
		while (head)
		{
			ListNode* next = head->next;
			head->next = nullptr;
			if (odd)
			{
				oddH = !oddH ? head : oddH;
				oddT = !oddT ? head : oddT->next = head;
			}
			else
			{
				evenH = !evenH ? head : evenH;
				evenT = !evenT ? head : evenT->next = head;
			}
			head = next;
			odd = !odd;
		}
		assert(oddT);
		oddT->next = evenH;
		return oddH;
	}
};