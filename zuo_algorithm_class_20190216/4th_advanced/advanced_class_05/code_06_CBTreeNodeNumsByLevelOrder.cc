//层序遍历 时间复杂度一定是o(n)
int CBTreeNodeNumbers(const CBTreeNode* root)
{
	if (!root)
	{
		return 0;
	}
	queue<const CBTreeNode*> nodes;
	nodes.emplace(root);
	int cnt = 1;
	while (!nodes.empty())
	{
		++cnt;
		root = nodes.front();
		nodes.pop();
		if (root->left)
		{
			nodes.emplace(root->left);
		}
		if (root->right)
		{
			nodes.emplace(root->right);
		}
	}
	return cnt;
}