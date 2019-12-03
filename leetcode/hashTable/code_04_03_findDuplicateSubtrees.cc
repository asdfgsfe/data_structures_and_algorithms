class Solution {
public:
	vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {
		if (!root)
		{
			return {};
		}
		unordered_map<string, int> subtreeToNodes;
		vector<TreeNode*> nodes;
		SerializeProcess(root, nodes, subtreeToNodes);
		return nodes;
	}

	string SerializeProcess(TreeNode* root, vector<TreeNode*>& nodes, unordered_map<string, int>& subtreeToNodes)
	{
		if (!root)
		{
			return "#!";
		}
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