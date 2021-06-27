652. 寻找重复的子树
给定一棵二叉树，返回所有重复的子树。对于同一类的重复子树，你只需要返回其中任意一棵的根结点即可。

两棵树重复是指它们具有相同的结构以及相同的结点值。

示例 1：

        1
       / \
      2   3
     /   / \
    4   2   4
       /
      4
下面是两个重复的子树：

      2
     /
    4
和

    4

class Solution {
public:
	vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {
		if (!root)
		{
			return {};
		}
		//key是序列化的子树 val是该子树出现的次数
		unordered_map<string, int> subtreeToNodes;
		//用于记录结果
		vector<TreeNode*> nodes;
		SerializeProcess(root, nodes, subtreeToNodes);
		return nodes;
	}

	//后序遍历 判断两棵子树结构完全相同 他们的序列化一定相同
	string SerializeProcess(TreeNode* root, vector<TreeNode*>& nodes, unordered_map<string, int>& subtreeToNodes)
	{
		if (!root)
		{
			return "#!";
		}
		//依旧是后序遍历 因为处理结果在遍历完左子树和右子树之后
		//res为以当前为根节点序列化之后的树
		string res = std::to_string(root->val) + "!";
		res += SerializeProcess(root->left, nodes, subtreeToNodes);
		res += SerializeProcess(root->right, nodes, subtreeToNodes);
		auto node = subtreeToNodes.find(res);
		//利用val是否等于1去重复
		if (node != subtreeToNodes.end() && node->second == 1)
		{
			nodes.emplace_back(root);
		}
		++subtreeToNodes[res];
		return res;
	}
};
