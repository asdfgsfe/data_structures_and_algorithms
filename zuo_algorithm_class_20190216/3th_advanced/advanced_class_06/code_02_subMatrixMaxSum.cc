int SubMatrixMaxSum(const vector<vector<int>>& matrix)
{
  if (matrix.empty() || matrix[0].empty())
  {
    return 0;
  }
  int max = 0x80000000;
  for (int i = 0; i < matrix.size(); ++i)
  {
    vector<int> subArr(matrix[0].size(), 0);
    for (int j = i; j < matrix.size(); ++j)
    {
      int cur = 0;
      for (int k = 0; k < matrix[0].size(); ++k)
      {
        subArr[k] += matrix[j][k];
        cur += subArr[k];
        max = cur > max ? cur : max;
        cur = cur <= 0 ? 0 : cur;
      }
    }
  }
  return max;
}
