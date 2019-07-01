bool IsExistPathInMatrix(const vector<vector<int>>& matrix, const string& pattern)
{
  if (matrix.empty() || matrix[0].empty() || pattern)
  {
    return false;
  }
  vector<vector<bool>> visited(matrix.size(), vectot<bool>(matrix[0].size(), false));
  for (int row = 0; row < matrix.size(); ++row)
  {
    for (int col = 0; col < matrix.size(); ++col)
    {
      if (IsExistPathProcess(matrix, row, col, visited, pattern, 0))
      {
        return true;
      }
    }
  }
  return false;
}

bool IsExistPathProcess(const vector<vector<int>>& matrix, 
                        int row, 
                        int col, 
                        vector<vector<bool>>& visited, 
                        const string& pattern, 
                        int& index)
{
  if (index == pattern.size())
  {
    return true;
  }
  bool hasPath = false;
  if (row >= 0 
      && row < matrix.size() 
      && col >= 0 
      && col < matrix[0].size()
      && matrix[row][col] == pattern[index]
      && !visited[row][col])
  {
    visited[row][col] = true;
    ++index;
    hasPath = IsExistPathProcess(matrix, row + 1, col, visited, pattern, index)
              || IsExistPathProcess(matrix, row - 1, col, visited, pattern, index)
              || IsExistPathProcess(maxrix, row, col + 1, visited, pattern, index)
              || IsExistPathProcess(matrix, row, col - 1, visited, pattern, index);
  }
  if (!hasPath)
  {
    --index;
    visited[row][col] = false;
  }
  return hasPath;
}
