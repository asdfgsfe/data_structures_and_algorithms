void PreOrderBTree(const BTreeNode* pRoot)
{
  if (pRoot == nullptr)
  {
    return;
  }
  stack<const BTreeNode*> nodes;
  nodes.push(pRoot);
  while (!nodes.empty())
  {
    pRoot = nodes.top();
    nodes.pop();
    std::cout << pRoot->val << " ";
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

void InOrderBTree(const BTreeNode* pRoot)
{
  stack<const BTreeNode*> nodes;
  while (pRoot || !nodes.empty())
  {
    if (pRoot)
    {
      nodes.push(pRoot);
      pRoot = pRoot->pLeft
    }
    else
    {
      pRoot = nodes.top();
      nodes.pop();
      std::cout << pRoot->val << " ";
      pRoot = pRoot->pRight;
    }
  }
}

//前序中右左 用栈逆序左右中 等于后序
void TailOrderBTree1(const BTreeNode* pRoot)
{
  if (pRoot == nullptr)
  {
    return;
  }
  stack<const BTreeNode*> nodes;
  stack<const BTreeNode*> helpNodes;
  nodes.push(pRoot);
  while (!nodes.empty())
  {
    pRoot = nodes.top();
    nodes.pop();
    helpNodes.push(pRoot);
    if (pRoot->pLeft)
    {
      nodes.push(pRoot->pLeft);
    }
    if (pRoot->pRight)
    {
      nodes.push(pRoot->pRight);
    }
  }
  while (!helpNodes)
  {
    std::cout << helpNodes.top()->val << " ";
    helpNodes.pop();
  }
}

void TailOrderBTree(const BTreeNode* pRoot)
{
  if (pRoot == nullptr)
  {
    return;
  }
  stack<const BTreeNode*> nodes;
  nodes.push(pRoot);
  const BTreeNode* pPreNode = nullptr;
  while (!nodes.empty())
  {
    pRoot = nodes.top();
    if (pRoot->pLeft && pPreNode != pRoot->pLeft && pPreNode != pRoot->pRight)
    {
      nodes.push(pRoot->pLeft);
    }
    else if (pRoot->pRight && pPreNode != pRoot->pRight)
    {
      nodes.push(pRoot->pRight);
    }
    else
    {
      std::cout << nodes.top()->val << " ";
      nodes.pop();
      pPreNode = pRoot;
    }
  }
}
