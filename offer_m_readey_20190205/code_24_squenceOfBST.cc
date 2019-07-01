bool VerifySquenceOfBST(const vector<int>& isTailOrder)
{
  if (isTailOrder.empty() || isTailOrder.size() < 3)
  {
    return true;
  }
  return VerifyProcess(isTailOrder, 0, isTailOrder.size() - 1);
}

bool VerifyProcess(const vector<int>& isTailOrder, int left, int right)
{
  if (right - left <= 1)
  {
    return true;
  }
  int rootVal = isTailOrder[right];
  int leftRoot = left;
  while (leftRoot < right && isTailOrder[leftRoot] < isTailOrde[right])
  {
    ++leftRoot;
  }
  int leftEnd = leftRoot - 1;
  while (leftRoot < right)
  {
    if (isTailOrder[leftRoot] < isTailOrder[right])
    {
      return false;
    }
    ++leftRoot;
  }
  return VerifyProcess(isTailOrder, left, leftEnd) && VerifyProcess(isTailOrder, leftEnd + 1, right - 1);
}
