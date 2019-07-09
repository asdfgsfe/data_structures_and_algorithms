struct ReturnData
{
	bool isB;
	int h;
};

bool IsBalanceTree1(const BTreeNode* pRoot)
{
	if (!pRoot)
	{
		return true;
	}
	return IsBalanceProcess(pRoot);
}

ReturnData IsBalanceProcess(const BTreeNode* pRoot)
{
	if (!pRoot)
	{
		return ReturnData(true, 0);
	}
	ReturnData lInfo = IsBallanceProcess(pRoot->pLeft);
	if (!lInfo.isB)
	{
		return ReturnData(false, 0);
	}
	ReturnData rInfo = IsBalanceProcess(pRoot->pRight);
	if (!rInfo.isB)
	{
		return ReturnData(false, 0);
	}
	if (std::abs(lInfo.h - rInfo.h) > 1)
	{
		return ReturnData(false, 0);
	}
	return ReturnData(true, std::max(lInfo.h, rInfo) + 1);
}

bool IsBalanceTree2(const BTreeNode* pRoot)
{
	if (!pRoot)
	{
		return true;
	}
	int depth = 0;
	return IsBalanceProcess2(pRoot, depth);
}

bool IsBalanceProcess2(const BTreeNode* pRoot, int& depth)
{
	depth = 0;
	if (!pRoot)
	{
		return true;
	}
	int lH;
	bool isLB = IsBalanceProcess2(pRoot->pLeft, lH);
	if (!isLB)
	{
		return false;
	}
	int rH;
	bool isRB = IsBalanceProcess2(pRoot->pRight, rH);
	if (!isRB)
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