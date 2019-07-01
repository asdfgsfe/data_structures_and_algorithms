bool IsCBT(const BTreeNode* pRoot)
{
  if (pRoot == nullptr)
  {
    return true;
  }
  queue<const BTreeNode*> nodes;
  nodes.push(pRoot);
  bool isLeaf = false;
  while (!nodes.empty())
  {
    pRoot = nodes.front();
    nodes.pop();
    if (pRoot->pLeft == nullptr && pRoot->pRight
        || (isLeaf && ((pRoot->pLeft || pRoot->pRight))))
    {
      return false;
    }
    if (pRoot->pLeft)
    {
      nodes.push(pRoot->pLeft);
    }
    if (pRoot->pRight)
    {
      nodes.push(pRoot->pRight);
    }
    if (!isLeaf && !pRoot->pLeft && !pRoot->pRight)
    {
      isLeft = true;
    }
  }
  return true;
}
