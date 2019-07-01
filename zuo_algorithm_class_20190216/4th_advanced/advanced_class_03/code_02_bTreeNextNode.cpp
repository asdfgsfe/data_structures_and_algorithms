BTreeNode* NextNode(const BTreeNode* pNode)
{
	if (!pNode)
	{
		return nullptr;
	}
	//������Һ��� �ҵ��Һ�������ĺ��� ����Ŀ��ڵ�
	if (pNode->pRight)
	{
		const BTreeNode* pMostLeft = pNode->pRight;
		while (pMostLeft->pLeft)
		{
			pMostLeft = pMostLeft->pLeft;
		}
		return pMostLeft;
	}
	//������Һ��� ������ �ҵ���һ�����׽ڵ������ ���׽ڵ����Ŀ��ڵ�
	const BTreeNode* pFather = pNode;
	while (pFather && pFather->pLeft != pNode)
	{
		pNode = pFather;
		pFather = pFather->pParent;
	}
	return pFather;
}