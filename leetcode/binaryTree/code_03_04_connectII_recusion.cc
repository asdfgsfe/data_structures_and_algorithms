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
//���ǣ����������п��ܲ�ȱ������Ҫƽ��ɨ�踸�ڵ�ͬ��Ľڵ㣬�ҵ����ǵ������ӽڵ㡣
//���ڵ�ǰɨ���һ���ڵ㣬��ΪҪ�ҵ���ǰ�ڵ����һ����
//�����õݹ麯��ʱ��Ҫ�������µݹ飬����Ҫ�ȵݹ鵱ǰ�ڵ����������Ȼ���ٵݹ���������
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