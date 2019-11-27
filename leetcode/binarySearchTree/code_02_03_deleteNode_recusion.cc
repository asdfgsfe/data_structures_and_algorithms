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
		if (root->val == key)
		{
			if (!root->left || !root->right)
			{
				TreeNode* node = root->left ? root->left : root->right;
				delete root;
				return node;
			}
			TreeNode* mostLeft = root->right;
			while (mostLeft->left)
			{
				mostLeft = mostLeft->left;
			}
			root->val = mostLeft->val;
			root->right = deleteNode(root->right, mostLeft->val);
		}
		else if (root->val > key)
		{
			root->left = deleteNode(root->left, key);
		}
		else
		{
			root->right = deleteNode(root->right, key);
		}
		return root;
	}
};