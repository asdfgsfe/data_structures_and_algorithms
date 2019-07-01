#include <iostream>
#include <vector>
#include <algorithm>

using std::vector;

int Process(const vector<vector<int>>& matrix, int row, int col)
{
  int path = 1;
  if (col > 0 && matrix[row][col-1] > matrix[row][col])
  {
    path = std::max(path, Process(matrix, row, col-1) + 1);
  }
  if (row > 0 && matrix[row-1][col] > matrix[row][col])
  {
    path = std::max(path, Process(matrix, row-1, col) + 1);
  }
  if (col < matrix[0].size()-1 && matrix[row][col+1] > matrix[row][col])
  {
    path = std::max(path, Process(matrix, row, col+1) + 1);
  }
  if (row < matrix.size()-1 && matrix[row+1][col] > matrix[row][col])
  {
    path = std::max(path, Process(matrix, row+1, col) + 1);
  }
  return path;
}

int LogestIncreasingPath1(const vector<vector<int>>& matrix)
{
  int rows = matrix.size();
  int cols = matrix[0].size();
  if (rows <= 0 || cols <= 0)
  {
    return 0;
  }

  int max = -1;
  for (int row = 0; row < rows; ++row)
  {
    for (int col = 0; col < cols; ++col)
    {
      max = std::max(max, Process(matrix, row, col));
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
    if (col > 0 && matrix[row][col-1] > matrix[row][col])
    {
      dp[row][col] = std::max(dp[row][col], ProcessDp(matrix, dp, row, col-1) + 1);
    }
    if (row > 0 && matrix[row-1][col] > matrix[row][col])
    {
      dp[row][col] = std::max(dp[row][col], ProcessDp(matrix, dp, row-1, col) + 1);
    }
    if (col < matrix[0].size()-1 && matrix[row][col+1] > matrix[row][col])
    {
      dp[row][col] = std::max(dp[row][col], ProcessDp(matrix, dp, row, col+1) + 1);
    }
    if (row < matrix.size()-1 && matrix[row+1][col] > matrix[row][col])
    {
      dp[row][col] = std::max(dp[row][col], ProcessDp(matrix, dp, row+1, col) + 1);
    }
  }
  return dp[row][col];
}

int LogestIncreasingPath2(const vector<vector<int>>& matrix)
{
  int rows = matrix.size();
  int cols = matrix[0].size();
  if (rows <= 0 || cols <= 0)
  {
    return 0;
  }

  int max = -1;
  vector<vector<int>> dp(rows, vector<int>(cols, 0));
  for (int row = 0; row < rows; ++row)
  {
    for (int col = 0; col < cols; ++col)
    {
      max = std::max(max, ProcessDp(matrix, dp, row, col) + 1);
    }
  }
  return max;
}

int MaxIncrease(const vector<vector<int>>& matrix, 
                vector<vector<int>>& dp,
                int row,
                int col,
                int pre)
{
  if (col < 0 || col >= matrix[0].size() || row < 0 || row >= matrix.size() 
      || matrix[row][col] >= pre)
  {
    return 0;
  }

  if (dp[row][col] == 0)
  {
    dp[row][col] = MaxIncrease(matrix, dp, row+1, col, matrix[row][col]) + 1;
    dp[row][col] = 
      std::max(dp[row][col], MaxIncrease(matrix, dp, row, col+1, matrix[row][col]) + 1);
    dp[row][col] = 
      std::max(dp[row][col], MaxIncrease(matrix, dp, row-1, col, matrix[row][col]) + 1);
    dp[row][col] = 
      std::max(dp[row][col], MaxIncrease(matrix, dp, row, col-1, matrix[row][col]) + 1);
  }
  return dp[row][col];
}

int LogestIncreasingPath3(const vector<vector<int>>& matrix)
{
  int rows = matrix.size();
  int cols = matrix[0].size();
  if (rows <= 0 || cols <= 0)
  {
    return 0;
  }

  vector<vector<int>> dp(rows, vector<int>(cols, 0));
  int max = 0;
  for (int row = 0; row < rows; ++row)
  {
    for (int col = 0; col < cols; ++col)
    {
      max = std::max(max, MaxIncrease(matrix, dp, row+1, col, matrix[row][col]) + 1);
      max = std::max(max, MaxIncrease(matrix, dp, row, col+1, matrix[row][col]) + 1);
      max = std::max(max, MaxIncrease(matrix, dp, row-1, col, matrix[row][col]) + 1);
      max = std::max(max, MaxIncrease(matrix, dp, row, col-1, matrix[row][col]) + 1);
    }
  }
  return max;
}

int main(void)
{
  vector<vector<int>> matrix = {{9, 9, 4}, {6, 6, 8}, {2, 1, 1}};
  std::cout << LogestIncreasingPath1(matrix) << std::endl;
  std::cout << LogestIncreasingPath2(matrix) << std::endl;
  std::cout << LogestIncreasingPath3(matrix) << std::endl;

  matrix = {{3, 4, 5}, {3, 2, 6}, {2, 2, 1}};
  std::cout << LogestIncreasingPath1(matrix) << std::endl;
  std::cout << LogestIncreasingPath2(matrix) << std::endl;
  std::cout << LogestIncreasingPath3(matrix) << std::endl;

  return 0;
}







