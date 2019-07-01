#include <iostream>
#include <vector>

using std::vector;

void PrintLevel(const vector<vector<int>>& matrix, int tR, int tC, int dR, int dC, bool f)
{
  if (f)
  {
    while (tR >= dR)
    {
      //std::cout << "f " << f << "tR " << tR << "dR " << dR << std::endl;
      std::cout << matrix[tR--][tC++] << " ";
    }
  }
  else
  {
    while (dR <= tR)
    {
      //std::cout << "f " << f << "tR " << tR << "dR " << dR << std::endl;
      std::cout << matrix[dR++][dC--] << " ";
    }
  }
}

void ZigZagPrintMatrix(const vector<vector<int>>& matrix)
{
  if (matrix.empty() || matrix[0].empty())
  {
    return;
  }
  bool fromUp = true;
  int tR = 0;
  int tC = 0;
  int dR = 0;
  int dC = 0;
  int endR = matrix.size() - 1;
  int endC = matrix[0].size() - 1;
  while (dR <= endR)
  {
    //std::cout << "tR:" << tR << " tC:" << tC << " dR:" << dR << " dC:" << dC << std::endl;
    PrintLevel(matrix, tR, tC, dR, dC, fromUp);
    std::cout << std::endl;
    //NOTICE: 注意tC tR的赋值顺序 先tC后tR 不让tC依赖于tR 
    tC = tR == endR ? tC + 1 : tC;
    tR = tR == endR ? tR : tR + 1;
    dR = dC == endC ? dR + 1 : dR;
    dC = dC == endC ? dC : dC + 1;
    fromUp = !fromUp;
  }
  std::cout << std::endl;
}

int main(void)
{
  vector<vector<int>> matrix = { { 1, 2, 3, 4 }, 
                                 { 5, 6, 7, 8 }, 
                                 { 9, 10, 11, 12 } };
  ZigZagPrintMatrix(matrix);

  return 0;
}
