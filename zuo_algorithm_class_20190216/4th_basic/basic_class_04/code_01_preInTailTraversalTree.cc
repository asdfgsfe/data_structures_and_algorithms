void PreTravsersalBTree(const BTreeNode* pRoot)
{
  if (pRoo == nullptr)
  {
    return;
  }
  stack<const BTreeNode*> nodes;
  nodes.push(pRoot);
  while (!nodes.empty())
  {
    pRoot = nodes.top();
    nodes.pop();
    if (pRoot->pRight)
    {
      nodes.push(pRoot->pRight);
    }
    if (pRoot->pLeft)
    {
      nodes.push(pRoot->pLeft);
    }
  }
}

void InTraversalBTree(const BTreeNode* pRoot)
{
  stack<const BTreeNode*> nodes;
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
      pRoot = pRoot->pRight;
    }
  }
}

void InTreversalBTreeNode(const BTreeNode* pRoot)
{
  stack<const BTreeNode*> nodes;
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
      pRoot = pRoot->pRight;
    }
  }
}

void TailTraversalBTree(const BTreeNode* pRoot).
{
  if (pRoot == nullptr)
  {
    return;
  }
  stack<const BTreeNode*> nodes;
  nodes.push(pRoot);
  const BTreeNode* pCurNode = nullptr; //pRoot == pPre
  while (!nodes.empty())
  {
    pCurNode = nodes.top();
    if (pCurNode->pLeft && (pRoot != pCurNode->pLeft && pRoot != pCurNode->pRight))
    {
      nodes.push(pCurNode->pLeft);
    } 
    else if (pCurNode->pRight && pRoot != pCurNode->pRight)
    {
      nodes.push(pCurNode->pRight);
    }
    else
    {
      nodes.pop();
      pRoot = pCurNode;
    }
  }
}
