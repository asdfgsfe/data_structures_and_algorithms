填充每个节点的下一个右侧节点指针
给定一个 完美二叉树 ，其所有叶子节点都在同一层，每个父节点都有两个子节点。二叉树定义如下：

struct Node {
  int val;
  Node *left;
  Node *right;
  Node *next;
}
填充它的每个 next 指针，让这个指针指向其下一个右侧节点。如果找不到下一个右侧节点，则将 next 指针设置为 NULL。

初始状态下，所有 next 指针都被设置为 NULL。

 

进阶：

你只能使用常量级额外空间。
使用递归解题也符合要求，本题中递归程序占用的栈空间不算做额外的空间复杂度。
 



作者：力扣 (LeetCode)
链接：https://leetcode-cn.com/leetbook/read/data-structure-binary-tree/xoo0ts/
来源：力扣（LeetCode）
著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。


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
		//注意是完全二叉树才能这么做
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
