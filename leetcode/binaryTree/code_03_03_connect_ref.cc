class Solution
{
public:
	Node* connect(Node* root)
	{
		if (!root)
		{
			return nullptr;
		}
		Node* level = root;
		Node* cur = root;
		//һ��һ�����������
		while (level->left)
		{
			assert(cur->left);
			cur->left->next = cur->right;
			if (cur->next)
			{
				cur->right->next = cur->next->left;
				cur = cur->next;
			}
			else
			{
				level = level->left;
				cur = level;
			}
		}
		return root;
	}
};