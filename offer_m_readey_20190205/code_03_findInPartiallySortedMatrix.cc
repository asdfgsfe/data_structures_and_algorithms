bool FindInPartiallySortedMatrix(const vector<vector<int>>& matrix, int num)
{
  if (matrix.empty() || matrix[0].empty())
  {
    return false;
  }
  int row = 0;
  int col = matrix[0].size() - 1;
  while (row < matrix.size() && col >= 0)
  {
    if (matrix[row][col] == num)
    {
      return true;
    }
    else if (matirx[row][col] < num)
    {
      ++row;
    }
    else 
    {
      --col;
    }
  }
  return false;
}

bool FindInPartiallySortedMatrix2(int* matrix, int rows, int cols, int num)
{
  if (!matrix || rows < 1 || cols < 1)
  {
    return false;
  }
  int row = 0;
  int col = cols - 1;
  while (row < rows && col >= 0)
  {
    if (matrix[row * cols + col] == num)
    {
      return true;
    }
    else if (matrix[row * cols + col] < num)
    {
      ++row;
    }
    else
    {
      --col;
    }
  }
  return true;
}
