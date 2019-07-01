#include <iostream>
#include <vector>

using std::vector;

int MoveProcess(vector<vector<int>>& matrix, int r, int c, int rows, int cols)
{
  if ( r == rows && c == cols)
  {
    return matrix[r][c];
  }
  if (r == rows &&  c != cols)
  {
    return matrix[r][c] + MoveProcess(matrix, r, c + 1, rows, cols);
  }
  if (r != rows && c == cols)
  {
    return matrix[r][c] + MoveProcess(matrix, r + 1, c, rows, cols);
  }
  int down = MoveProcess(matrix, r + 1, c, rows, cols);
  int right = MoveProcess(matrix, r, c + 1, rows, cols);
  return matrix[r][c] + std::min(down, right);
}

int MinPath(vector<vector<int>>& matrix)
{
  if (matrix.empty() || matrix[0].empty())
  {
    return -1;
  }
  return MoveProcess(matrix, 0, 0, matrix.size() - 1, matrix[0].size() - 1);
}

int MinPath2(vector<vector<int>>& matrix)
{
  if (matrix.empty() || matrix[0].empty())
  {
    return 0;
  }
  int rows = matrix.size();
  int cols = matrix[0].size();
  vector<vector<int>> dp(rows, vector<int>(cols));
  dp[rows - 1][cols - 1] = matrix[rows - 1][cols - 1];
  for (int i = rows - 2; i >= 0; --i)
  {
    dp[i][cols - 1] = dp[i + 1][cols - 1] + matrix[i][cols - 1];
  }
  for (int i = cols - 2; i >= 0; --i)
  {
    dp[rows - 1][i] = dp[rows - 1][i + 1] + matrix[rows - 1][i];
  }
  for (int i = rows - 2; i >= 0; --i)
  {
    for (int j = cols - 2; j >= 0; --j)
    {
      dp[i][j] = std::min(dp[i + 1][j], dp[i][j + 1]) + matrix[i][j];
    }
  }
  return dp[0][0];
}

int main(void)
{
  vector<vector<int>> matrix = { { 1, 3, 5, 9 }, { 8, 1, 3, 4 }, { 5, 0, 6, 1 }, { 8, 8, 4, 0 } };
  std::cout << MinPath(matrix) << std::endl;
  std::cout << MinPath(matrix) << std::endl;

  return 0;
}
