BTreeNode* PrevNode(const BTreeNode* pNode)
{
	if (!pNode)
	{
		return nullptr;
	}
	//如果有左孩子 左子树左右节点就是前一个节点
	if (pNode->pLeft)
	{
		const BTreeNode* pMostRight = pNode->pLeft;
		while (pMostRight->pRight)
		{
			pMostRight = pMostRight->pRight;
		}
		return pMostRight;
	}
	//如果无最孩子 向上找 找到第一个节点 是他父亲的又孩子 这个父亲节点就是前驱节点
	const BTreeNode* pFather = pNode->pParent;
	while (pFather && pFather->pRight != pNode)
	{
		pNode = pFather;
		pFather = pFather->pParent;
	}
	return pFather;
}