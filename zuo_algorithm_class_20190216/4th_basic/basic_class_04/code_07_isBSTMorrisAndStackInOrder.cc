bool IsBST(const BSTNode* pRoot)
{
	stack<const BSTNode*> nodes;
	const BSTNode* pPre = nullptr;
	while (pRoot || !nodes.empty())
	{
		if (pRoot)
		{
			nodes.push(pRoot);
			pRoot = pRoot->pLeft;
		}
		else
		{
			pRoot = nodes.top();
			nodes.pop();
			if (pPre && pPre->val > pRoot->val)
			{
				return false;
			}
			pPre = pRoot;
			pRoot = pRoot->pRight;
		}
	}
	return true;
}

//morris
bool IsBST2(BSTNode* pRoot)
{
	BSTNode* pPre = nullptr;
	while (pRoot)
	{
		BSTNode* pLeft = pRoot->pLeft;
		if (pLeft)
		{
			while (pLeft->pRight && pLeft->pRight != pRoot)
			{
				pLeft = pLeft->pRight;
			}
			if (!pLeft->pRight)
			{
				pLeft->pRight = pRoot;
				pRoot = pRoot->pLeft;
				continue;
			}
			pLeft->pRight = nullptr;
		}
		if (pPre && pPre->val > pRoot->val)
		{
			return false;
		}
		pPre = pRoot;
		pRoot = pRoot->pRight;
	}
	return true;
}