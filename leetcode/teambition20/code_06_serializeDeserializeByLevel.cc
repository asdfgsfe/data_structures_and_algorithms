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

二叉树的序列化与反序列化
序列化是将一个数据结构或者对象转换为连续的比特位的操作，
进而可以将转换后的数据存储在一个文件或者内存中，同时也可以通过网络传输到另一个计算机环境，
采取相反方式重构得到原数据。

请设计一个算法来实现二叉树的序列化与反序列化。这里不限定你的序列 / 反序列化算法执行逻辑，
你只需要保证一个二叉树可以被序列化为一个字符串并且将这个字符串反序列化为原始的树结构。

示例: 

你可以将以下二叉树：

    1
   / \
  2   3
     / \
    4   5

序列化为 "[1,2,3,null,null,4,5]"
提示: 这与 LeetCode 目前使用的方式一致，详情请参阅 LeetCode 序列化二叉树的格式。
你并非必须采取这种方式，你也可以采用其他的方法解决这个问题。

说明: 不要使用类的成员 / 全局 / 静态变量来存储状态，你的序列化和反序列化算法应该是无状态的。