void MultiplyArray(const vector<int>& arrA, vector<int>& arrB)
{
  if (arrA.size() < 2 || arrA.size() != arrB.size())
  {
    return;
  }
  arrB[0] = 1;
  for (int i = 1; i < arrA.size(); ++i)
  {
    arrB[i] = arrB[i - 1] * arrA[i - 1];
  }
  int temp = 1;
  for (int i = arrA.size() - 2; i >= 0; --i)
  {
    temp *= arrA[i + 1];
    arrB[i] *= temp;
  }
}

vector<int> MultiplyArray2(const vector<int>& a)
{
  if (a.size() < 2)
  {
    return vector<int>();
  }
  vector<int> b(a.size());
  b[0] = 1;
  for (int i = 1; i < a.size(); ++i)
  {
    b[i] = b[i - 1] * a[i - 1];
  }
  int d = 1;
  for (int i = a.size() - 2; i >= 0; ++i)
  {
    d *= a[i + 1];
    b[i] *= d;
  }
  return b;
}
