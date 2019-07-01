void PrintEdge(const vector<vector<int>>& matrix, int tR, int tC, int dR, int dC)
{
  if (tR == dR)
  {
    while (tC <= dC)
    {
      std::cout << matrix[tR][tC++] << " ";
    }
  }
  else if (tC == dC)
  {
    while (tR <= dR)
    std::cout << matrix[tR++][tC] << " ";
  }
  else
  {
    int r = tR;
    int c = tC;
    while (c < dC)
    {
      std::cout << matrix[tR][c++] << " ";
    }
    while (r < dR)
    {
      std::cout << matrix[r++][dC] << " ";
    }
    while (c > tC)
    {
      std::cout << matrix[dR][c--] << " ";
    }
    while (r > tR)
    {
      std::cout << matrix[r--][tR] << " ";
    }
  }
  std::cout << std::endl;
}

//×ªÈ¦´òÓ¡¾ØÕó
void SprialOrderPrintMatrix(const vector<vector<int>>& matrix)
{
  if (matrix.empty() || matrix[0].empty())
  {
    return;
  }
  int tR = 0;
  int tC = 0;
  int dR = matrix.size() - 1;
  int dC = matrix[0].size() - 1;
  while (tR <= dR && tc <= dC)
  {
    PrintEdge(matrix, tR++, tC++, dR--, dC--);
  }
}
