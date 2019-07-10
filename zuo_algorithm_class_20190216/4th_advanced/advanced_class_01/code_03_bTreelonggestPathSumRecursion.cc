//应该是可以的 复杂度高
//遍历每个节点 去判断能不能累加出来这个sum的 累加不出来结果位 -1肯定取不到
//从每个节点中取出最大值
int LengthPathSum(const BTreeNode* root, int sum)
{
	if (!root)
	{
		return 0;
	}
	int length = SumProcess(root, sum);
	length = std::max(length, SumProcess(root->left, sum));
	length = std::max(length, SumProcess(root->right, sum));
	return length;
}

int SumProcess(const BTreeNode* node, int sum)
{
	if (sum == 0)
	{
		return 0;
	}
	if (!node)
	{
		return -1;
	}
	sum -= node->val;
	int length = std::max(SumProcess(root->left, sum), SumProcess(root->right, sum));
	return length == -1 ?  -1, length + 1;
}