//����һ����������ɾ�������ظ���Ԫ�أ�ʹ��ÿ��Ԫ��ֻ����һ�Ρ�

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
    ListNode* deleteDuplicates(ListNode* head) {
		if (!head || !head->next)
		{
			return head;
		}    
		ListNode* newHead = head;
		while (head)
		{
			ListNode* curNext = head->next;
			if (curNext && head->val == curNext->val)
			{
				int val = head->val;
				while (curNext && val == curNext->val)
				{
					ListNode* delNode = curNext;
					curNext = curNext->next;
					delete delNode;
				}
			}
			head->next = curNext;
			head = curNext;
		}
		return newHead;
    }
};