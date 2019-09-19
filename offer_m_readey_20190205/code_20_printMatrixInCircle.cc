#include <iostream>
#include <vector>

using std::vector;

void PrintProcess(const vector<vector<int>>&, int, int, int, int);

void PrintMatrxiInCircle(const vector<vector<int>>& matrix)
{
  if (matrix.empty() || matrix[0].empty())
  {
    return;
  }
  int x1 = 0;
  int y1 = 0;
  int x2 = matrix.size() - 1;
  int y2 = matrix[0].size() - 1;
  while (x1 <= x2 && y1 <= y2)
  {
    PrintProcess(matrix, x1++, y1++, x2--, y2--);
  }
}

//这个打印有问题 如果矩阵只有一行 就会把这一行重复打印2边
//应该是在打印函数中区分出单行和单列的情况
void PrintProcess(const vector<vector<int>>& matrix, int x1, int y1, int x2, int y2)
{
  if (x1 < 0 || y1 < 0 || x2 >= matrix.size() || y2 >= matrix[0].size())
  {
    return;
  }
  int startX = x1;
  int startY = y1;
  while (y1 < y2)
  {
    std::cout << matrix[x1][y1++] << " ";
  }
  std::cout << std::endl;
  while (x1 < x2)
  {
    std::cout << matrix[x1++][y1] << " ";
  }
  std::cout << std::endl;
  while (y1 > startY)
  {
    std::cout << matrix[x1][y1--] << " ";
  }
  std::cout << std::endl;
  while (x1 > startX)
  {
    std::cout << matrix[x1--][y1] << " ";
  }
  std::cout << std::endl;
}

int main(void)
{
  vector<vector<int>> matrix = {{1, 2, 3, 4},
                                {5, 6, 7, 8},
                                {9, 10, 11, 12},
                                {13, 14, 15, 16}};
  //PrintMatrxiInCircle(matrix);
     matrix = {{1, 2, 3, 4}};
    PrintMatrxiInCircle(matrix);

  return 0;
}
