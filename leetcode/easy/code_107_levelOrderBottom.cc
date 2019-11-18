 class Solution {
 public:
	 vector<vector<int>> levelOrderBottom(TreeNode* root) {
		 if (!root)
		 {
			 return {};
		 }
		 vector<vector<int>> levels;
		 queue<TreeNode*> nodes;
		 stack<vector<int>> tmp;
		 nodes.push(root);
		 while (!nodes.empty())
		 {
			 int size = nodes.size();
			 vector<int> vals;
			 while (size--)
			 {
				 root = nodes.front();
				 nodes.pop();
				 vals.emplace_back(root->val);
				 if (root->left)
				 {
					 nodes.push(root->left);
				 }
				 if (root->right)
				 {
					 nodes.push(root->right);
				 }
			 }
			 tmp.push(vals);
		 }
		 while (!tmp.empty())
		 {
			 levels.emplace_back(tmp.top());
			 tmp.pop();
		 }
		 return levels;
	 }
 };