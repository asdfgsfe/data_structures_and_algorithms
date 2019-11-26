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
		//一层一层的网下链接
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