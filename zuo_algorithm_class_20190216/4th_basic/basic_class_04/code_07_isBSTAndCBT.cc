bool IsBST(BTreeNode* pRoot)
{
  if (pRoot == nullptr)
  {
    return true;
  }
  bool isBST = true;
  BTreeNode* pPre = nullptr;
  while (pRoot)
  {
    BTreeNode* pLeft = pRoot->pLeft;
    if (pLeft)
    {
      while (pLeft->pRight && pLeft->pRight != pRoot)
      {
        pLeft = pLeft->pRight;
      }
      if (pLeft->pRigth == nullptr)
      {
        pLeft->pRight = pRoot;
        pRoot = pRoot->pLeft;
        continue;
      }
      if (pLeft->pRight == pRoot)
      {
        pLeft->pRight == nullptr;
      }
    }
    if (pPre && pPre->val > pRoot->val)
    {
      isBST = false;
    }
    pPre = pRoot;
    pRoot = pRoot->pRight;
  }
  return isBST;
}

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
    int size = nodes.size();
    while (szie--)
    {
      pRoot = nodes.top();
      nodes.pop();
      BTreeNode* pLeft = pRoot->pLeft;
      BTreeNode* pRight = pRoot->pRight;
      if ((isLeaf && (pLeft == nullptr || pRight == nulltr)) || (pLeft == nullptr && Right))
      {
        return false;
      }
      if (pLeft)
      {
        nodes.push(pLeft);
      }
      else if (pRight)
      {
        nodes.push(pRight);
      }
      else
      {
        isLeaf = true;
      }
    }
  }
}
