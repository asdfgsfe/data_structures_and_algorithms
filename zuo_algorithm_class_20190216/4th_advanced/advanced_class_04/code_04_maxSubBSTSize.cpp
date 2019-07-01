struct ReturnData
{
	int size;
	int max;
	int min;
	BTreeNode* pHead;
};

int MaxSubBSTSize(const BTreeNode* pRoot)
{
	if (!pRoot)
	{
		return 0;
	}
	return SizeProcess(pRoot).size;
}

RetrunData SizeProcess(const BTreeNode* pRoot)
{
	if (!pRoot)
	{
		return ReturnData(0, 0, 0, nullptr);
	}
	ReturnData lInfo = SizeProcess(pRoot->pLeft);
	ReturnData rInfo = SizeProcess(pRoot->pRight);
	int includeItSelf = 0;
	if (pRoot->pLeft == lInfo.pHead 
		&& pRoot->pRight == rInfo.pHead 
		&& pRoot->val > lInfo.max
		&& pRoot->val < rInfo.min)
	{
		includeItSelf = lInfo.size + rInfo.size + 1;
	}
	BSTreeNode* pMaxHead = lInfo.size > rInfo.size ? lInfo.pHead : rInfo.pHead;
	int maxSize = std::max(includeItSelf, std::max(lInfo.size, rInfo.size));
	pMaxHead = maxSize == includeItSelf ? pRoot : pMaxHead;
	return ReturnData(maxSize, 
					  std::max(pRoot->val, std::max(lInfo.max, rInfo.max)), 
					  std::min(pRoot->val, std::min(lnfo.min, rInfo.min)), 
					  pMaxHead);
}

