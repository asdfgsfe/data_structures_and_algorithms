/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() {}

    Node(int _val, Node* _left, Node* _right, Node* _next) {
        val = _val;
        left = _left;
        right = _right;
        next = _next;
    }
};
*/
//但是，这里子树有可能残缺，故需要平行扫描父节点同层的节点，找到他们的左右子节点。
//对于当前扫描的一个节点，因为要找到当前节点的下一个。
//而调用递归函数时，要不断向下递归，所以要先递归当前节点的右子树，然后再递归左子树。
class Solution
{
public:
	Node* connect(Node* root)
	{
		if (!root)
		{
			return nullptr;
		}
		Node* best = root->next;
		while (best)
		{
			if (best->left)
			{
				best = best->left;
				break;
			}
			if (best->right)
			{
				best = best->right;
				break;
			}
			best = best->next;
		}
		if (root->left)
		{
			root->left->next = root->right ? root->right : best;
		}
		if (root->right)
		{
			root->right->next = best;
		}
		connect(root->right);
		connect(root->left);
		return root;
	}
};