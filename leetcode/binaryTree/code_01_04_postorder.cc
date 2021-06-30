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


//低柜
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<int> postorderTraversal(TreeNode* root) {
        if (!root) {
            return {};
        }
        vector<int> order;
        postorderProcess(root, order);
        return order; 
    }

    void postorderProcess(TreeNode* root, vector<int>& order) {
        if (!root) {
            return;
        }
        postorderProcess(root->left, order);
        postorderProcess(root->right, order);
        order.push_back(root->val);
    }
};


//morris

