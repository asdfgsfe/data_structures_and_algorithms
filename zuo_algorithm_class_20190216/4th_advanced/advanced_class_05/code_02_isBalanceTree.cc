bool IsBalanceTree1(const BTreeNode* pRoot)
{
	if (!pRoot)
	{
		return true;
	}
	int depth = 0;
	return BalanceProcess1(pRoot, &depth);
}

bool BalanceProcess1(const BTreeNode* pRoot, int* depth)
{
	if (!pRoot)
	{
		*depth = 0;
		return true;
	}
	int lH;
	bool lB = BalanceProcess(pRoot->pLeft, &lH);
	if (!lB)
	{
		return false;
	}
	int rH;
	bool rB = BalanceProcess(pRoot->pRigth, &rH);
	if (!rB)
	{
		return false;
	}
	if (std::abs(rH - lH) > 1)
	{
		return false;
	}
	depth = std::max(lH, rH) + 1;
	return true;
}


struct ReturnData
{
	int h;
	bool isB;
	ReturnData(int height, bool isBalance)
		: h(height), isB(isBalance)
	{}
};
bool IsBalanceTree2(const BTreeNode* pRoot)
{
	if (!pRoot)
	{
		return true;
	}
	return BalanceProcess2(pRoot).isB;
}

ReturnData BalanceProcess2(const BTreeNode* pRoot)
{
	if (!pRoot)
	{
		return ReturnData(0, true);
	}
	ReturnData lInfo = BalanceProcess2(pRoot->pLeft);
	if (!lInfo.isB)
	{
		return ReturnData(0, false);
	}
	RetrunData rInfo = BalanceProcess2(pRoot->pRight);
	if (rInfo.isB)
	{
		return ReturnData(0, false);
	}
	if (::abs(lInfo.h - rInfo.h) > 1)
	{
		return ReturnData(0, false);
	}
	return ReturnData(std::max(lInfo.h, rInfo.h) + 1, true);
}