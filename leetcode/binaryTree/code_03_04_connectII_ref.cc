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
class Solution {
public:
    Node* connect(Node* root) {
        if (!root)
        {
			return nullptr;
        }
		Node dummy(0, nullptr, nullptr, nullptr); //借助虚拟节点全部链接起来 一层一层的连接
		Node* pre = &dummy;
		Node* cur = root;
		while (cur)
		{
			if (cur->left)
			{
				pre->next = cur->left;
				pre = pre->next;
			}
			if (cur->right)
			{
				pre->next = cur->right;
				pre = pre->next;
			}
			cur = cur->next;
		}
		//dummy.next表示cur下一层的第一个节点 dummy就是cur层的下一层
		connect(dummy.next);
        return root;
    }
};
