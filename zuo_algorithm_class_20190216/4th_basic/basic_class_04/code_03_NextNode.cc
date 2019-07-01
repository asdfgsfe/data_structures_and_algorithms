BTreeNode* NextNode(const BTreeNode* pRoot)
{
	if (!pRoot)
	{
		return nullptr;
	}
	if (pRoot->pRight)
	{
		const BTreeNode* pNode = pRoot->pRight;
		while (pNode && pNode->pLeft)
		{
			pNode = pRight->pLeft;
		}
		return pNode;
	}
	const BTreeNode* pPar = pRoot->pParent;
	while (pPar && pPar->pLeft != pRoot)
	{
		pRoot = pParent;
		pPar = pPar->pParent;
	}
	return pPar;
}