//�����ǰ�ڵ�ֵС��Ŀ��ֵ������ֻ�����ǵ�ǰ�ڵ�ֵ�����������е�ֵ��
//�����ǰ�ڵ�ֵ����Ŀ��ֵ������ֻ�����ǵ�ǰ�ڵ�ֵ�����������е�ֵ��
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