#include <iostream>
#include <vector>

using std::vector;

void PrintEdge(const vector<vector<int>>& matrix, int tR, int tC, int dR, int dC, bool fromUp)
{
  if (fromUp)
  {
    while (dR >= tR && dC <= tC)
    {
      std::cout << matrix[dR--][dC++] << " ";
    }
  }
  else
  {
    while (tR <= dR && tC >= dC)
    {
      std::cout << matrix[tR++][tC--] << " ";
    }
  }
  std::cout << std::endl;
}

//之字型打印矩阵
void ZigZagPrintMatrix(const vector<vector<int>>& matrix)
{
  if (matrix.empty() || matrix[0].empty())
  {
    return;
  }
  int tR = 0;
  int tC = 0;
  int dR = 0;
  int dC = 0;
  bool fromUp = true;
  while (tR <= matrix.size() -1 && tC <= matrix[0].size() - 1)
  {
    PrintEdge(matrix, tR, tC, dR, dC, fromUp);
    //tR 依赖tC dC依赖dR 所以注意顺序 先tR 在tC 先dC在dR
    tR = tC == matrix[0].size() - 1 ? tR + 1 : tR;
    tC = tC == matrix[0].size() - 1 ? tC : tC + 1;
    dC = dR == matrix.size() - 1 ? dC + 1 : dC;
    dR = dR == matrix.size() - 1 ? dR : dR + 1;
    fromUp = !fromUp;
  }
}

int main(void)
{
  vector<vector<int>> matrix = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
  ZigZagPrintMatrix(matrix);

  return 0;
}
