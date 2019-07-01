BTreeNode* NextNode(const BTreeNode* pNode)
{
	if (!pNode)
	{
		return nullptr;
	}
	//如果有右孩子 找到右孩子最左的孩子 就是目标节点
	if (pNode->pRight)
	{
		const BTreeNode* pMostLeft = pNode->pRight;
		while (pMostLeft->pLeft)
		{
			pMostLeft = pMostLeft->pLeft;
		}
		return pMostLeft;
	}
	//如果无右孩子 向上找 找到第一个父亲节点的左孩子 父亲节点就是目标节点
	const BTreeNode* pFather = pNode;
	while (pFather && pFather->pLeft != pNode)
	{
		pNode = pFather;
		pFather = pFather->pParent;
	}
	return pFather;
}