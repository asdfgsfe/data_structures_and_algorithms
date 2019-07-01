#include <iostream>
#include <vector>

using std::vector;

void Infect(vector<vector<int>>& matrix, int row, int col, int rows, int cols)
{
  if (row < 0 || row >= rows || col < 0 || col >= cols || matrix[row][col] != 1)
  {
    return;
  }
  matrix[row][col] = 2;
  Infect(matrix, row, col + 1, rows, cols);
  Infect(matrix, row, col - 1, rows, cols);
  Infect(matrix, row - 1, col, rows, cols);
  Infect(matrix, row + 1, col, rows, cols);
}

int CountIsLands(vector<vector<int>>& matrix)
{
  if (matrix.empty() || matrix[0].empty())
  {
    return 0;
  }
  int n = matrix.size();
  int m = matrix[0].size();
  int res = 0;
  for (int i = 0; i < n; ++i)
  {
    for (int j = 0; j < m; ++j)
    {
      if (matrix[i][j] == 1)
      {
        ++res;
        Infect(matrix, i, j, n, m);
      }
    }
  }
  return res;
}

int main(void)
{
  vector<vector<int>> m1 = {  
    { 0, 0, 0, 0, 0, 0, 0, 0, 0 }, 
    { 0, 1, 1, 1, 0, 1, 1, 1, 0 }, 
    { 0, 1, 1, 1, 0, 0, 0, 1, 0 },
    { 0, 1, 1, 0, 0, 0, 0, 0, 0 }, 
    { 0, 0, 0, 0, 0, 1, 1, 0, 0 }, 
    { 0, 0, 0, 0, 1, 1, 1, 0, 0 },
    { 0, 0, 0, 0, 0, 0, 0, 0, 0 }, };
  std::cout << CountIsLands(m1) << std::endl;

  vector<vector<int>> m2 = {  
    { 0, 0, 0, 0, 0, 0, 0, 0, 0 }, 
    { 0, 1, 1, 1, 1, 1, 1, 1, 0 }, 
    { 0, 1, 1, 1, 0, 0, 0, 1, 0 },
    { 0, 1, 1, 0, 0, 0, 1, 1, 0 }, 
    { 0, 0, 0, 0, 0, 1, 1, 0, 0 }, 
    { 0, 0, 0, 0, 1, 1, 1, 0, 0 },
    { 0, 0, 0, 0, 0, 0, 0, 0, 0 }, };
  std::cout << CountIsLands(m2) << std::endl;

  return 0;
}
