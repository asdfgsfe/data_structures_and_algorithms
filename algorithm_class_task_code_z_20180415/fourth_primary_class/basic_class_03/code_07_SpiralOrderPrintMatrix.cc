#include <iostream>
#include <vector>

using std::vector;

void PrintEdge(const vector<vector<int>>& matrix, int tR, int tC, int dR, int dC)
{
  if (tR == dR)
  {
    while (tC <= dC)
    {
      std::cout << matrix[tR][tC++] << " ";  
    }
    std::cout << std::endl;
  }
  else if (tC == dC)
  {
    while (tR <= dR)
    {
      std::cout << matrix[tR++][tC] << " ";
    }
    std::cout << std::endl;
  }
  else
  {
    int curTC = tC;
    int curTR = tR;
    while (curTC < dC)
    {
      std::cout << matrix[curTR][curTC++] << " ";
    }
    std::cout << std::endl;
    while (curTR < dR)
    {
      std::cout << matrix[curTR++][curTC] << " ";
    }
    std::cout << std::endl;
    while (curTC > tC)
    {
      std::cout << matrix[curTR][curTC--] << " ";
    }
    std::cout << std::endl;
    while (curTR > tR)
    {
      std::cout << matrix[curTR--][curTC] << " ";
    }
    std::cout << std::endl;
  }
}

void SpiralOrderPrintMartix(const vector<vector<int>>& matrix)
{
  if (matrix.empty() || matrix[0].empty())
  {
    return;
  }
  int tR = 0;
  int tC = 0;
  int dR = matrix.size() - 1;
  int dC = matrix[0].size() - 1;
  while (tR <= dR && tC <= dC)
  {
    //std::cout << "tR:" << tR << " tC:" << tC << " dR:" << dR << " dC:" << dC << std::endl; 
    PrintEdge(matrix, tR++, tC++, dR--, dC--);
  }
}

int main(void)
{
  vector<vector<int>> matrix = {{1, 2, 3, 4}, 
                                {5, 6, 7, 8},
                                {9, 10, 11, 12},
                                {13, 14, 15, 16}};
  SpiralOrderPrintMartix(matrix);
  matrix = {{1, 2, 3, 4}};
  SpiralOrderPrintMartix(matrix);
  matrix = {{1}, {2}, {3}, {4}};
  SpiralOrderPrintMartix(matrix);

  return 0;
}
