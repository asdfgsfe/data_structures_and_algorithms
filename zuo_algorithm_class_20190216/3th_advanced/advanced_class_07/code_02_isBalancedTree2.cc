bool IsProcess2(const BTreeNode* pRoot, int& depth)
{
  if (pRoot == nullptr)
  {
    depth = 0;
    return true;
  }
  int lh = 0;
  int rh = 0;
  if (IsProcess2(pRoot->pLeft, lh) && IsProcess2(pRoot->pRight, rh) && std::abs(lh - rh) < 2)
  {
    depth = std::max(lh, rh) + 1;
    return true;
  }
  return false;
}

bool IsBalanceBTree2(const BTreeNode* pRoot)
{
  if (pRoot == nullptr)
  {
    return true;
  }
  int depath = 0;
  return IsProcess2(pRoot, depth);
}