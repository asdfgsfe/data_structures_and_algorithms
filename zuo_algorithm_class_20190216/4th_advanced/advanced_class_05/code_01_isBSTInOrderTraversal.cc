bool IsBST(const BTreeNode* pRoot)
{
  stack<const BTreeNode*> nodes;
  const BTreeNode* pPre = nullptr;
  while (pRoot || !nodes.empty())
  {
    while (pRoot)
    {
      nodes.push(pRoot);
      pRoot = pRoot->pLeft;
    }
    if (!nodes.empty())
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



//µÝ¹é±éÀú
bool IsBST1(const BTreeNode* pRoot)
{
	if (!pRoot)
	{
		return true;
	}
	int preNum = 0x80000000;
	return IsProcess(pRoot, &preNum);
}

bool IsProcess1(const BSTreeNode* pRoot, int* preNum)
{
	if (pRoot == nullptr)
	{
		return true;
	}
	bool lInfo = IsProcess1(pRoot->pLeft, preNum);
	if (!lInfo)
	{
		return false;
	}
	if (preNum >= pRoot->val)
	{
		return false;
	}
	*preNum = pRoot->val;
	return IsProcess1(pRoot->pRight, preNum);
}

//·ÇµÝ¹é±éÀú
bool IsBST2(const BSTreeNode* pRoot)
{
	stack<const BSTreeNode*> nodes;
	int pre = 0x80000000;
	while (pRoot || !nodes.empty())
	{
		if (pRoot)
		{
			nodes.push(pRoot);
		}
		else
		{
			pRoot = nodes.top();
			nodes.pop();
			if (pre >= pRoot->val)
			{
				return false;
			}
			pre = pRoot->val;
			pRoot = pRoot->pRight;
		}
	}
	return true;
}

//morris
bool IsBST3(BSTreeNode* pRoot)
{
	int pre = 0x80000000;
	while (pRoot)
	{
		BSTreeNode* pMostLeft = pRoot->pLeft;
		if (pMostLeft)
		{
			while (pMostLeft->pRight && pMostLet->pRight != pRoot)
			{
				pMostLeft = pMostLeft->pRight;
			}
			if (!pMostLeft->pRight)
			{
				pMostLeft->pRiight = pRoot;
				pRoot = pRoot->pLeft;
				continue;
			}
			if (pMostLeft->pRight == pRoot)
			{
				pMostLeft->pRight = nullptr;
			}
		}
		if (pre >= pRoot->val)
		{
			return false;
		}
		pre = pRoot->val;
		pRoot = pRoot->pRight;
	}
	return true;
}


