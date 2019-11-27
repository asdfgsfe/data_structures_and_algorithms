/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
	TreeNode * deleteNode(TreeNode* root, int key) {
		if (!root)
		{
			return nullptr;
		}
		TreeNode* keyNode = root;
		TreeNode* pre = nullptr;
		while (keyNode)
		{
			if (keyNode->val == key)
			{
				break;
			}
			pre = keyNode;
			keyNode = keyNode->val > key ? keyNode->left : keyNode->right;
		}
		if (!pre)
		{
			return Deleting(keyNode);
		}
		if (pre->left && pre->left->val == key)
		{
			pre->left = Deleting(keyNode);
		}
		else
		{
			pre->right = Deleting(keyNode);
		}
		return root;
	}

	TreeNode* Deleting(TreeNode* node)
	{
		if (!node)
		{
			return nullptr;
		}
		if (!node->right)
		{
			TreeNode* ans = node->left;
			delete node;
			return ans;
		}
		TreeNode* mostLeft = node->right;
		while (mostLeft->left)
		{
			mostLeft = mostLeft->left;
		}
		mostLeft->left = node->left;
		mostLeft = node->right;
		delete node;
		return mostLeft;
	}
};