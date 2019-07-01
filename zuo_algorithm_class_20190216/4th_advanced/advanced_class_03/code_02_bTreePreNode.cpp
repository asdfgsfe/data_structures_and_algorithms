BTreeNode* PrevNode(const BTreeNode* pNode)
{
	if (!pNode)
	{
		return nullptr;
	}
	//��������� ���������ҽڵ����ǰһ���ڵ�
	if (pNode->pLeft)
	{
		const BTreeNode* pMostRight = pNode->pLeft;
		while (pMostRight->pRight)
		{
			pMostRight = pMostRight->pRight;
		}
		return pMostRight;
	}
	//�������� ������ �ҵ���һ���ڵ� �������׵��ֺ��� ������׽ڵ����ǰ���ڵ�
	const BTreeNode* pFather = pNode->pParent;
	while (pFather && pFather->pRight != pNode)
	{
		pNode = pFather;
		pFather = pFather->pParent;
	}
	return pFather;
}