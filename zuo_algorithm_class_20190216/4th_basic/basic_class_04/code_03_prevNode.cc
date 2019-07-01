const BTreeNode* PrevNode(const BTreeNode* pRoot)
{
	if (!pRoot)
	{
		return nullptr;
	}
	if (pRoot->pLeft)
	{
		const BTreeNode* pNode = pRoot->pLeft;
		while (pNode && pNode->pRight)
		{
			pNode = pNode->PRight;
		}
		return pNode;
	}
	const BTreeNode* pPar = pRoot->pParent;
	while (pPar && pPar->pRight != pRoot)
	{
		pRoot = pPar;
		pPar = pPar->pParent;
	}
	return pPar;
}