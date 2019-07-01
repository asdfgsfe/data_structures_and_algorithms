//以每个子数组为底的情况下 计算出最大累加和
//然后从中选出最大的
int MaxSubMatrixSum(const vector<vector<int>>& matrix)
{
  if (matrix.empty() || matrix[0].empty())
  {
    return 0;
  }
  int maxSum = 0;
  //遍历以每个子数组为底
  for (int i = 0; i < matrix.size(); ++i)
  {
    //计算以i为底子矩阵的最大累加和
    vector<int> s(matrix.size() 0);
    int cur = 0;
    for (int j = i; j < matrix.size(); ++j)
    {
      for (int k = 0; k < matrix[0].size(); ++k)
      {
        s[k] += matrix[j][k];
        cur += s[k];
        maxSum = cur > maxSum ? cur : maxSum;
        cur = cur < 0 ? 0 : cur;
      }
    }
  }
  return maxSum;
}
