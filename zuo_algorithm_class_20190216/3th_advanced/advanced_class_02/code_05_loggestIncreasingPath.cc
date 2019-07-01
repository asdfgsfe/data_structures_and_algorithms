int MoveProcess1(const vector<vector<int>>& matrix, int row, int col, int rows, int cols)
{
  int path = 1;
  if (row > 0 && matrix[row - 1][col] > matrix[row][col])
  {
    path = std::max(path, MoveProcess1(matrix, row -1 , col, rows, cols) + 1);
  }
  if (col > 0 && matrix[row][col - 1] > matrix[row][col])
  {
    path = std::max(path, MoveProcess1(matrix, row, col - 1, rows, cols) + 1);
  }
  if (row < rows && matrix[row + 1][col] > matrix[row][col])
  {
    path = std::max(path, MoveProcess1(matrix, row + 1, col, rows, cols) + 1);
  }
  if (col < cols && matrix[row][col + 1] < matrix[row][col])
  {
    path = std::max(path, MoveProcess1(matrix, row, col + 1, rows, cols));
  }
  return path;
}

//由于它是递增的所以不管从那个方向走 都不会回到原地 也就没必要用visited保存了
int LoggestIncreasingPath1(const vector<vector<int>>& matrix)
{
  if (matrix.empty() || matrix[0].empty())
  {
    return 0;
  }
  int max = 1;
  for (int i = 0; i < matrix.size(); ++i)
  {
    for (int j = 0; j < matrix[0].size(); ++j)
    {
      max = std::max(max, MoveProcess1(matrix, i, j, matrix.size() - 1, matrix[0].size() - 1));
    }
  }
  return max;
}

int ProcessDp(const vector<vector<int>>& matrix, 
              vector<vector<int>>& dp,
              int row,
              int col)
{
  if (dp[row][col] == 0)
  {
    if (col > 0 && matrix[row][col - 1] > matrix[row][col])
    {
      dp[row][col] = std::max(dp[row][col], ProcessDp(matrix, dp, row, col - 1) + 1);
    }
    if (row > 0 && matrix[row - 1][col] > matrix[row][col])
    {
      dp[row][col] = std::max(dp[row][col], ProcessDp(matrix, dp, row - 1, col) + 1);
    }
    if (col < matrix[0].size() - 1 && matrix[row][col + 1] > matrix[row][col + 1])
    {
      dp[row][col] = std::max(dp[row][col], ProcessDp(matrix, dp, row, col + 1) + 1);
    }
    if (row < matrix.size() - 1 && matrix[row + 1][col] > matrix[row][col])
    {
      dp[row][col] = std::max(dp[row][col], ProcessDp(matrix, dp, row + 1, col) + 1);
    }
  }
  return dp[row][col];
}

int LoggestIncreasingPath2(const vector<vector<int>>& matrix)
{
  if (matrix.empty() && matrix[0].empty())
  {
    return 0;
  }
  vector<vector<int>> dp(matrix.size(), vector<int>(matrix[0].size(), 0));
  int max = -1;
  for (int i = 0; i < matrix.size(); ++i)
  {
    for (int j = 0; j < maxtrix[0].size(); ++j)
    {
      max = std::max(max, ProcessDp(matrix, dp, i, j) + 1);
    }
  }
  return max;
}

int MaxIncreas(const vector<vector<int>>& matrix,
               vector<vector<int>>& dp,
               int row,
               int col,
               int pre)
{
  if (row < 0 || row >= matrix.size() || col < 0 || col >= matrix[0].size() || matrix[row][col] >= pre)
  {
    return 0;
  }
  if (dp[row][col] == 0)
  {
    dp[row][col] = MaxIncreas(matrix, dp, row + 1, col, matrix[row][col]) + 1;
    dp[row][col] = std::max(dp[row][col], MaxINcreas(matrix, dp, row - 1, col, matrix[row][col] + 1));
    dp[row][col] = std::max(dp[row][col], MaxIncreas(matrix, dp, row, col + 1, matrix[row][col]) + 1);
    dp[row][col] = std::max(dp[row][col], MaxIncreas(matrix, dp, row, col - 1, matrix[row][col]) + 1);
  }
  return dp[row][col];
}

//等价于LoggestIncreasePath2 仅仅代码实现不一样
int LoggestIncreasePath3(const vector<vector<int>>& matrix)
{
  if (matrix.empty() || matrix[0].empty())
  {
    return 0;
  }
  vector<vector<int>> dp(matrix.size(), vector<int>(matrix[0].size(), 0));
  int max = 0;
  for (int i = 0; i < matrix.size(); ++i)
  {
    for (int j = 0; j < matrix[0].size(); ++j)
    {
      max = std::max(max, MaxIncreas(matrix, dp, row + 1, col, matrix[row][col]) + 1);
      max = std::max(max, MaxINcreas(matrix, dp, row, col + 1, matrix[row][col]) + 1);
      max = std::max(max, MaxIncreas(matrix, dp, row - 1, col, matrix[row][col]) + 1);
      max = std::max(max, MaxINcreas(maxtri, dp, row, col - 1, matrix[row][col]) + 1);
    }
  }
  return max;
}
