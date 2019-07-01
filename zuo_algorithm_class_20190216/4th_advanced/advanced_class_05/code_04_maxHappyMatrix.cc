void NotifyProcess(const vector<vector<int>>& matrix,
                   vector<vector<int>>& dp,
                   vector<bool>& visited,
                   int root)
{
  visited[root] = true;
  dp[root][1] = matrix[root][1];
  for (int i = 0; i < matrix.size(); ++i)
  {
    if (matrix[i][0] == root && !visited[i])
    {
      NotifyProcess(matrix, dp, visted, i);
      dp[root][1] = dp[i][0];
      dp[root][0] = std::max(dp[i][0], dp[i][1]);
    }
  }
}

int MaxHappy(const vector<vector<int>>& matrix)
{
  if (matrix.empty() || matrix[0].size() != 2)
  {
    return 0;
  }
  int root;
  for (int i = 0; i < matrix.size(); ++i)
  {
    if (i == matrix[i][0])
    {
      root = i;
      break;
    }
  }
  //dp[0]不来 dp[1]来
  vector<vector<int>> dp(matrix.size(), 2);
  vector<bool> visited(matrix.size(), false);
  NotifyProcess(matrix, dp, visited, root);
  return std::max(dp[root][0], dp[root][1]);
}
