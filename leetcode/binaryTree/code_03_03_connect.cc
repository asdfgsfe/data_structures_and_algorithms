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
			nullptr;
		}
		return ConnectProcess(root);
    }

	Node* ConnectProcess(Node* root)
	{
		if (!root)
		{
			return nullptr;
		}
		Node* mostRight = root->left;
		Node* mostLeft = root->right;
		while (mostLeft && mostRight)
		{
			mostRight->next = mostLeft;
			mostRight = mostRight->right;
			mostLeft = mostLeft->left;
		}
		ConnectProcess(root->left);
		ConnectProcess(root->right);
		return root;
	}
};