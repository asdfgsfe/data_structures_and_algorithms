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
	vector<int> postorderTraversal(TreeNode* root) {
		if (!root)
		{
			return {};
		}
		vector<int> values;
		stack<TreeNode*> nodes;
		nodes.push(root);
		const TreeNode* pre = root;
		while (!nodes.empty())
		{
			root = nodes.top();
			if (root->left && root->left != pre && root->right != pre)
			{
				nodes.push(root->left);
			}
			else if (root->right && root->right != pre)
			{
				nodes.push(root->right);
			}
			else
			{
				nodes.pop();
				pre = root;
				values.emplace_back(root->val);
			}
		}
		return values;
	}
};