//感觉也没啥问题依旧不会 改变原来的链表
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
		node = head->next;
		//区别仅仅在这个地方
		while (head)
		{
			Node* next = head->next;
            if (next)
            {
			    head->next = next->next;
            }
			head = next;
		}
		return node;
	}
};