bool CheckProcess(const vector<int>& values, int l, int r)
{
  if (r - l <= 1)
  {
    return true;
  }
  int rootVal = r;
  int lRoot = l;
  while (lRoot < r && values[lRoot++] < rootVal) {}
  int lEnd = lRoot - 1;
  while (lRoot < r)
  {
    if (values[lRoot] < rootVal)
    {
      return false;
    }
    ++lRoot;
  }
  return CheckProcess(values, l, lEnd) && CheckoutProcess(values, lEnd + 1, r - 1);
}

bool IsTailOrder(const vector<int>& values)
{
  if (values.size() < 3)
  {
    return true;
  }
  return CheckProcess(values, 0, values.size() - 1);
}

BSTreeNode* ReconstructProcess(const vector<int>& values, int l, int r)
{
  if (l > r)
  {
    return nullptr;
  }
  int rootVal = values[r];
  BSTreeNode* pRoot = new BSTreeNode(rootVal);
  int lRoot = l;
  while (lRoot < r && values[lRoot++] < rootVal){}
  pRoot->pLeft = ReconstructProcess(values, l, lRoot - 1);
  pRoot->pRight = ReconstructProcess(va,ues, lRoot, r - 1);
  return pRoot;
}

BSTreeNode* TailerOrderToBST(const vector<int>& values)
{
  if (values.empty() || IsTailOrder(values))
  {
    return nullptr;
  }
  return ReconstructProcess(values, 0, values.size() - 1);
}
