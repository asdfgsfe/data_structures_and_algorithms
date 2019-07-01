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

//������Ǵ��еĴ������� ����������Կ��Ժϲ�˳���if�߼�
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