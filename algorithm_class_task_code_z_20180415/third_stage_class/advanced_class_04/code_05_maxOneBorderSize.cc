#include <stdlib.h>
#include <time.h>
#include <iostream>
#include <vector>

using std::vector;

void SetBorderMap(const vector<vector<int>>& matrix,
             vector<vector<int>>& down,
             vector<vector<int>>& right)
{
  int r = matrix.size() - 1;
  int c = matrix[0].size() - 1;
  if (matrix[r][c] == 1)
  {
    down[r][c] = 1;
    right[r][c] = 1;
  }
  for (int i = r - 1; i >=0; --i)
  {
    if (matrix[i][c] == 1)
    {
      right[i][c] = 1;
      down[i][c] = down[i+1][c] + 1;
    }
  }
  for (int i = c - 1; i >= 0; --i)
  {
    if (matrix[r][i] == 1)
    {
      down[r][i] = 1;
      right[r][i] = right[r][i+1] + 1;
    }
  }
  for (int i = r - 1; i >= 0; --i)
  {
    for (int j = c - 1; j >=0; --j)
    {
      if (matrix[i][j] == 1)
      {
        down[i][j] = down[i+1][j] + 1;
        right[i][j] = right[i][j+1] + 1;
      }
    }
  }
}

bool HasSizeOfBorder(const vector<vector<int>>& down,
                     const vector<vector<int>>& right,
                     int l)
{
  int rows = down.size();
  int cols = down[0].size();
  //rows - l + 1表示该点的行坐标
  for (int i = 0; i < rows - l + 1; ++i)
  {
    //表示该点的列坐标
    for (int j = 0; j < cols - l + 1; ++j)
    {
      if (down[i][j] >= l && right[i][j] >= l && down[i][j+l-1] >= l && right[i+l-1][j] >= l)
      {
        return true;
      }
    }
  }
  return false;
}

int MaxBorderSize(const vector<vector<int>>& matrix)
{
  if (matrix.empty())
  {
    return 0;
  }

  int rows = matrix.size();
  int cols = matrix[0].size();
  vector<vector<int>> down(rows, vector<int>(cols, 0));
  vector<vector<int>> right = down;
  SetBorderMap(matrix, down, right);
  for (int size = std::min(rows, cols); size != 0; --size)
  {
    if(HasSizeOfBorder(down, right, size))
    {
      return size;
    }
  }
  return 0;
}

void PrintMatrix(const vector<vector<int>>& m)
{
  for (int i = 0; i < m.size(); ++i)
  {
    for (int j = 0; j < m[0].size(); ++j)
    {
      std::cout << m[i][j] << " ";
    }
    std::cout << std::endl;
  }
}

vector<vector<int>> GetRandomMatrix(int rows, int cols)
{
  vector<vector<int>> m(rows, vector<int>(cols, 0));
  for (int i = 0; i < rows; ++i)
  {
    for (int j = 0; j < cols; ++j)
    {
      ::srand((unsigned int)time(NULL));
      m[i][j] = ::rand() % 2;
    }
  }
  return m;
}

int main(void)
{
  vector<vector<int>> matrix = GetRandomMatrix(7, 8);
  PrintMatrix(matrix);
  std::cout << MaxBorderSize(matrix) << std::endl;

  vector<vector<int>> m1 = {
    {0, 1, 1, 1, 1},
    {0, 1, 0, 0, 1},
    {0, 1, 0, 0, 1},
    {0, 1, 1, 1, 1},
    {0, 1, 0, 1, 1}};
  std::cout << MaxBorderSize(m1) << std::endl;

  return 0;
}
