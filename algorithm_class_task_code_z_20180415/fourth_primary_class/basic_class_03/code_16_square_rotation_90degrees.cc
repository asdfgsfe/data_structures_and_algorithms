#include <iostream>
#include <vector>

using std::vector;

void RotationPoints(vector<vector<int>>& matrix, int tR, int tC, int dR, int dC)
{
  while ((dR - tR) > 0)
  {
    std::swap(matrix[tR][tC], matrix[tC][dC]);
    //std::cout << "(" << tR << ", " << tC << ") -> " << "(" << tC << ", " << dC << ")" << std::endl;
    std::swap(matrix[tR][tC], matrix[dC][dR]);
    //std::cout << "(" << tR << ", " << tC << ") -> " << "(" << dC << ", " << dR  << ")" << std::endl;
    std::swap(matrix[tR][tC++], matrix[dR--][tR]);
    //std::cout << "(" << tR << ", " << tC << ") -> " << "(" << dR << ", " << tR << ")" << std::endl;
    //std::cout << std::endl;
  }
}

void SquareRotation90Degress(vector<vector<int>>& matrix)
{
  if (matrix.empty() || matrix[0].empty() || matrix.size() == 1 || matrix.size() != matrix[0].size())
  {
    return;
  }
  int tR = 0;
  int tC = 0;
  int dR = matrix.size() - 1;
  int dC = matrix[0].size() - 1;
  while (tR <= dR)
  {  
    RotationPoints(matrix, tR++, tC++, dR--, dC--);
  }
}

void PrintMatrix(const vector<vector<int>>& m)
{
  for (const auto& rows : m)
  {
    for (auto row : rows)
    {
      std::cout << row << " ";
    }
    std::cout << std::endl;
  }
}

int main(void)
{
  vector<vector<int>> matrix = {{1, 2, 3, 4},
                                {5, 6, 7, 8},
                                {9, 10, 11, 12},
                                {13, 14, 15, 16}};
  PrintMatrix(matrix);
  SquareRotation90Degress(matrix);
  std::cout << std::endl;
  PrintMatrix(matrix);

  std::cout << std::endl;
  matrix = {{1, 2, 3, 4 ,5},
            {6, 7, 8, 9, 10},
            {11, 12, 13, 14, 15},
            {16, 17, 18, 19, 20},
            {21, 22, 23, 24, 25}};
  PrintMatrix(matrix);
  SquareRotation90Degress(matrix);
  std::cout << std::endl;
  PrintMatrix(matrix);
  return 0;
}
