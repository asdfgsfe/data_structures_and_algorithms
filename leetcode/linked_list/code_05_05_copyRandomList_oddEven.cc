//�о�Ҳûɶ�������ɲ��� �ı�ԭ��������
class Solution {
public:
	Node * copyRandomList(Node* head) {
		if (!head)
		{
			return nullptr;
		}
		Node* node = head;
		while (node)
		{
			Node* cur = new Node(node->val, nullptr, nullptr);
			cur->next = node->next;
			node->next = cur;
			node = cur->next;
		}
		node = head;
		while (node && node->next)
		{
			if (node->random)
			{
				node->next->random = node->random->next;
			}
			node = node->next->next;
		}
		node = head;
		Node* cpHead = nullptr;
		Node* cpTail = nullptr;
		Node* bkTail = nullptr;
		Node* bkHead = nullptr;
		bool copy = false;
		//ģ����ż�ڵ㷽��
		while (node)
		{
			Node* next = node->next;
			node->next = nullptr;
			if (copy)
			{
				cpHead = !cpHead ? node : cpHead;
				cpTail = !cpTail ? node : cpTail->next = node;
			}
			else
			{
				bkHead = !bkHead ? node : bkHead;
				bkTail = !bkTail ? node : bkTail->next = node;
			}
			copy = !copy;
			node = next;
		}
		return cpHead;
	}
};