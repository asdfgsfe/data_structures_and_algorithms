//如果当前节点值小于目标值，则结果只可能是当前节点值或者右子树中的值；
//如果当前节点值大于目标值，则结果只可能是当前节点值或者左子树中的值。
//其实就是前一个节点和当前节点 比较自己谁距离aim近
//这里的编码方式 前一个节点为root 当前节点为递归函数的返回值
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