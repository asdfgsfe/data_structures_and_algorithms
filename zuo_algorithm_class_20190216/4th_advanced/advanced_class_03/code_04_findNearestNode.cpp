//如果当前节点值小于目标值，则结果只可能是当前节点值或者右子树中的值；
//如果当前节点值大于目标值，则结果只可能是当前节点值或者左子树中的值。
BSTNode* FindNearestNode(const BSTNode* pRoot, int aim)
{
	BTreeNode* pCurNearest = nullptr;
	if (!pRoot || pRoot->val == aim)
	{
		return pRoot;
	}
	else if (pRoot->val > aim)
	{
		pCurNearest = FindNearestNode(pRoot->pLeft, aim);
	}
	else 
	{
		pCurNearest = FindNearestNode(pRoot->pRight, aim);
	}
	return pCurNearest && std::abs(pRoot->val - aim) < std::abs(pCurNearest->val - aim) ? pCurNeatestNode : pRoot;
}