/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
 class Codec {
 public:

	 // Encodes a tree to a single string.
	 string serialize(TreeNode* root) {
		 if (!root)
		 {
			 return string("#!");
		 }
		 string code = std::to_string(root->val) + "!";
		 code += serialize(root->left);
		 code += serialize(root->right);
		 return code;
	 }

	 // Decodes your encoded data to tree.
	 TreeNode* deserialize(string data) {
		 if (data.empty())
		 {
			 return nullptr;
		 }
		 vector<TreeNode*> nodes = Split(data);
		 int p = 0;
		 return DeserializeProcess(nodes, p);
	 }

	 TreeNode* DeserializeProcess(const vector<TreeNode*>& nodes, int& i)
	 {
		 if (i >= nodes.size())
		 {
			 return nullptr;
		 }
		 TreeNode* root = nodes[i++];
		 if (!root)
			 return nullptr;
		 root->left = DeserializeProcess(nodes, i);
		 ++i;
		 root->right = DeserializeProcess(nodes, i);
		 ++i;
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