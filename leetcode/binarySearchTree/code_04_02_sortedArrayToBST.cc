/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
 //这样建成的不仅仅是搜索二叉树 而且还是AVL树
class Solution {
public:
    TreeNode* sortedArrayToBST(vector<int>& nums) {
		if (nums.empty())
		{
			return nullptr;
		}
		return BSTProcess(nums, 0, nums.size() - 1);
    }

	TreeNode* BSTProcess(const vector<int>& nums, int l, int r)
	{
		if (l > r)
		{
			return nullptr;
		}
		int m = (l + r) / 2;
		TreeNode* root = new TreeNode(nums[m]);
		root->left = BSTProcess(nums, l, m - 1);
		root->right = BSTProcess(nums, m + 1, r);
		return root;
	}
};