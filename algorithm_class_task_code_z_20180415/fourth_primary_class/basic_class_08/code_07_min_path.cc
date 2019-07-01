#include <iostream>
#include <vector>

using std::vector;

void PrintMatrix(const vector<vector<int>>& m)
{
  std::cout << "matirx:" << std::endl;
  for (auto v : m)
  {
    for (auto i : v)
    {
      std::cout << i << " ";
    }
    std::cout << std::endl;
  }
}

int Walk(const vector<vector<int>>& matrix, int r, int c)
{
  if (r == matrix.size() - 1 && c == matrix[0].size() - 1)
  {
    return matrix[r][c];
  }
  if (r == matrix.size() - 1)
  {
    return matrix[r][c] + Walk(matrix, r, c + 1);
  }
  if (c == matrix[0].size() - 1)
  {
    return matrix[r][c] + Walk(matrix, r + 1, c);
  }
  int right = Walk(matrix, r, c + 1);
  int down = Walk(matrix, r + 1, c);
  return matrix[r][c] + std::min(right, down);
}

int MinPath(const vector<vector<int>>& matrix)
{
  if (matrix.empty() || matrix[0].empty())
  {
    return 0;
  }
  return Walk(matrix, 0, 0);
}

int MinPath1(const vector<vector<int>>& matrix)
{
  if (matrix.empty() || matrix[0].empty())
  {
    return 0;
  }
  vector<vector<int>> dp(matrix.size(), vector<int>(matrix[0].size()));
  int rows = matrix.size() - 1;
  int cols = matrix[0].size() - 1;
  dp[rows][cols] = matrix[rows][cols];
  for (int i = cols - 1; i >= 0; --i)
  {
    dp[rows][i] = dp[rows][i+1] + matrix[rows][i];
  }
  for (int i = rows - 1; i >= 0; --i)
  {
    dp[i][cols] = dp[i+1][cols] + matrix[i][cols];
  }
  //PrintMatrix(dp);
  for (int i = rows - 1; i >= 0; --i)
  {
    for (int j = cols -1; j >= 0; --j)
    {
      dp[i][j] = matrix[i][j] + std::min(dp[i+1][j], dp[i][j+1]);
    }
  }
  //PrintMatrix(dp);
  return dp[0][0];
}

int main(void)
{
  vector<vector<int>> matrix = { { 1, 3, 5, 9 }, 
                                 { 8, 1, 3, 4 }, 
                                 { 5, 0, 6, 1 }, 
                                 { 8, 8, 4, 0 } };
  std::cout << MinPath(matrix) << std::endl;
  std::cout << MinPath1(matrix) << std::endl;

  return 0;
}
