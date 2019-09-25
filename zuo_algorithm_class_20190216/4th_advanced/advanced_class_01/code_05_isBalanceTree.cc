struct ReturnData
{
	bool isB;
	int h;
	ReturnData(bool balance, int height)
		: isB(balance), h(height)
	{}
};

bool IsBalanceBTree(const BTreeNode* root)
{
	if (!root)
	{
		return true;
	}
	return BalanceProcess(root).isB;
}

ReturnData BalanceProcess(const BTreeNode* root)
{
	if (!root)
	{
		return ReturnData(true, 0);
	}
	ReturnData lInfo = BalanceProcess(root->left);
	if (!lInfo.isB)
	{
		return ReturnData(false, 0);
	}
	ReturnData rInfo = BalanceProcess(root->right);
	if (!rInfo.isB)
	{
		return ReturnData(false, 0);
	}
	if (std::abs(lInfo.h - rInfo.h) > 1)
	{
		return ReturnData(false, 0);
	}
	return ReturnData(true, std::max(lInfo.h + rInfo.h) + 1);
}

//后续遍历 方法2
bool IsBalaceBTree(const BTreeNode* root)
{
	if (!root)
	{
		return true;
	}
	int depth = 0;
	return BalanceProcess(root, depath);
}

bool BalanceProcess(const BTreeNode* root, int& depth)
{
	depth = 0;
	if (!root)
	{
		return true;
	}
	int lH;
	int rH;
	if (!BalanceProcess(root->left, lH) || !BalanceProcess(root->right, rH))
	{
		return false;
	}
	if (std::abs(lH - rH) > 1)
	{
		return false;
	}
	depth = std::max(lH, rH) + 1;
	return true;
}