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

�����������л��뷴���л�
���л��ǽ�һ�����ݽṹ���߶���ת��Ϊ�����ı���λ�Ĳ�����
�������Խ�ת��������ݴ洢��һ���ļ������ڴ��У�ͬʱҲ����ͨ�����紫�䵽��һ�������������
��ȡ�෴��ʽ�ع��õ�ԭ���ݡ�

�����һ���㷨��ʵ�ֶ����������л��뷴���л������ﲻ�޶�������� / �����л��㷨ִ���߼���
��ֻ��Ҫ��֤һ�����������Ա����л�Ϊһ���ַ������ҽ�����ַ��������л�Ϊԭʼ�����ṹ��

ʾ��: 

����Խ����¶�������

    1
   / \
  2   3
     / \
    4   5

���л�Ϊ "[1,2,3,null,null,4,5]"
��ʾ: ���� LeetCode Ŀǰʹ�õķ�ʽһ�£���������� LeetCode ���л��������ĸ�ʽ��
�㲢�Ǳ����ȡ���ַ�ʽ����Ҳ���Բ��������ķ������������⡣

˵��: ��Ҫʹ����ĳ�Ա / ȫ�� / ��̬�������洢״̬��������л��ͷ����л��㷨Ӧ������״̬�ġ�