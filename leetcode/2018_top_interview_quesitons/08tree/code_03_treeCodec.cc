/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
 //中序序列化二叉树
 class Codec {
 public:
	 // Encodes a tree to a single string.
	 string serialize(TreeNode* root) {
		 if (!root)
		 {
			 return string("#!");
		 }
		 queue<TreeNode*> nodes;
		 nodes.push(root);
		 string code;
		 while (!nodes.empty())
		 {
			 int size = nodes.size();
			 while (size--)
			 {
				 root = nodes.front();
				 nodes.pop();
				 if (!root)
				 {
					 code += "#!";
					 continue;
				 }
				 code +=std::to_string(root->val) + "!";
				 nodes.push(root->left);
				 nodes.push(root->right);
			 }
		 }
		 return code;
	 }

	 // Decodes your encoded data to tree.
	 TreeNode* deserialize(string data) {
		 if (data.empty())
		 {
			 return nullptr;
		 }
		 vector<TreeNode*> values = Split(data);
		 TreeNode* root = values[0];
		 queue<TreeNode*> nodes;
		 nodes.push(values[0]);
		 int p = 1;
		 while (p < values.size() - 1)
		 {
			 TreeNode* node = nodes.front();
			 nodes.pop();
			 node->left = values[p++];
			 node->right = values[p++];
			 if (node->left)
			 {
				 nodes.push(node->left);
			 }
			 if (node->right)
			 {
				 nodes.push(node->right);
			 }
		 }
		 return root;
	 }

	 vector<TreeNode*> Split(const string& data)
	 {
		 if (data.empty())
		 {
			 return {};
		 }
		 vector<TreeNode*> nodes;
		 int p = 0;
		 int n = 0;
		 while (n < data.size())
		 {
			 if (data[n] != '!')
			 {
				 ++n;
			 }
			 else
			 {
				 string val = data.substr(p, n - p);
				 TreeNode* node = val == "#" ? nullptr : new TreeNode(::atoi(val.data()));
				 p = ++n;
				 nodes.emplace_back(std::move(node));
			 }
		 }
		 return nodes;
	 }
 };

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.deserialize(codec.serialize(root));
//
