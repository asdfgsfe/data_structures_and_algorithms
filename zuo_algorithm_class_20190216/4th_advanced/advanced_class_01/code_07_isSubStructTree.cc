bool IsSubStruct(const BTreeNode* pRoot, const BTreeNode* pNode)
{
	if (!pNode)
	{
		return true;
	}
	if (!pRoot)
	{
		return false;
	}
	return IsProcess(pRoot, pNode) || IsProcess(pRoot->pLeft, pNode) || IsProcess(pRoot->pRight, pNode);
}

//或操作是串行的从左向右 利用这个可以可以合并顺序的if逻辑
bool IsProcess(const BTreeNode* pRoot, const BTreeNode* pNode)
{
	if (!pNode)
	{
		return true;
	}
	if (!pRoot || pRoot->val != pNode->val)
	{
		return false;
	}
	return IsProcess(pRoot->pLeft, pNode->pLeft) && IsProcess(pRoot->pRight, pNode->pRight);
}