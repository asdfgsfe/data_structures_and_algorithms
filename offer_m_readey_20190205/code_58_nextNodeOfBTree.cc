const BTreeNode* NextNodeOfBTreeInOrder(const BTreeNode* pRoot, const BTreeNode* pNode)
{
  if (pRoot == nullptr || pNode == nullptr)
  {
    return nullptr;
  }
  if (pNode->pRight)
  {
    const BTreeNode* pNext = pNode->pRight;
    while (pNext && pNext->pLeft)
    {
      pNext = pNext->pLeft;
    }
    return pNext;
  }
  const BTreeNode* pParent = pNode->pParent;
  while (pParent && pNode != pParent->pLeft)
  {
    pNode = pParent;
    pParent = pParent->pPar;
  }
  return pParent;
}
