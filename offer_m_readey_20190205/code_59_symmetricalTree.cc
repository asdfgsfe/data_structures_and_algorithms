bool IsSymmetricalBTree(const BTreeNode* pRoot)
{
  if (pRoot == nullptr)
  {
    return true;
  }
  return Process(pRoot, pRoot);
}

bool Process(const BTreeNode* pRoot1, const BTreeNode* pRoot2)
{
  if (pRoot1 == nullptr && pRoot2 == nullptr)
  {
    return true;
  }
  if (pRoot1 == nullptr || pRoot2 == nullptr)
  {
    return false;
  }
  if (pRoot1->val != pRoot2->val)
  {
    return false;
  }
  return Process(pRoot1->pLeft, pRoot2->pRight) && Process(pRoot1->pRight, pRoot2->pLeft);
}
