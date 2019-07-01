BSTreeNode* KthNodeInBSTree(const BSTreeNode* pRoot, int k)
{
  if (pRoot == nullptr || k < 1)
  {
    return nullptr;
  }
  return KthNodeProcess(pRoot, &k); 
}

BSTreeNode* KthNodeProcess(const BSTreeNode* pNode, int* k)
{
  if (pNode == nullptr)
  {
    return nullptr;
  }
  BSTreeNode* pKthNode = KthNodeProcess(pNode->pLeft, k);
  if (pKthNode == nullptr)
  {
    if (k == 1)
    {
      pKthNode = pNode;
    }
    --(*k);
  }
  if (pKthNode == nullptr)
  {
    pKthNode = KthNodeInBSTree(pRoot->pRight);
  }
  return pKthNode;
}
