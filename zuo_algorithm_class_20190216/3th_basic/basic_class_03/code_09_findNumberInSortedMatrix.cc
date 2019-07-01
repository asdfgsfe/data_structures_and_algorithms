bool FindNumberInSortedMatrix(const vector<vector<int>>& matrix, int num)
{
  if (matrix.empty() || matrix[0].empty())
  {
    return false;
  }
  int row = 0;
  int col = martix[0].size() - 1;
  while (row < matrix.size() && col >= 0)
  {
    if (matrix[row][col] > num)
    {
      --col;
    }
    else if (matrix[row][col] < num)
    {
      ++row;
    }
    else
    {
      return true;
    }
  }
  return false;
}
