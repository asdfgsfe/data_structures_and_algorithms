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
	 vector<TreeNode*> generateTrees(int n) {
		 return GenProcess(1, n);
	 }

	 vector<TreeNode*> GenProcess(int l, int r)
	 {
		 if (l > r)
		 {
			 return {};
		 }
		 vector<TreeNode*> roots;
		 for (int s = l; s <= r; ++s)
		 {
			 vector<TreeNode*> lefts = GenProcess(l, s - 1);
			 lefts = lefts.empty() ? vector<TreeNode*>(1, nullptr) : lefts;
			 vector<TreeNode*> rights = GenProcess(s + 1, r);
			 rights = rights.empty() ? vector<TreeNode*>(1, nullptr) : rights;
			 for (int i = 0; i < lefts.size(); ++i)
			 {
				 for (int j = 0; j < rights.size(); ++j)
				 {
					 TreeNode* root = new TreeNode(s);
					 root->left = lefts[i];
					 root->right = rights[j];
					 roots.emplace_back(root);
				 }
			 }
		 }
		 return roots;
	 }
 };