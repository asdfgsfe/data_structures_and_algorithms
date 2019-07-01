int HasSizeOfBorder(int size, const vector<vector<int>>& right, const vector<vector<int>>& down)
{
  for (int i = 0; i < right.size() - size + 1; ++i)
  {
    for (int j = 0; j < right[0].size() - size + 1; ++j)
    {
      if (down[i][j] >= size 
          && right[i][j] >= size 
          && right[i + size - 1][j] >= size 
          && down[i][j + size - 1] >= size)
      {
        return true;
      }
    }
  }
  return false;
}

void SetBorder(const vector<vector<int>>& matrix, vector<vector<int>>& right, vector<vector<int>>& down)
{
  if (matrix.empty() || matrix[0].empty())
  {
    return;
  }
  int row = matrix.size() - 1;
  int col = matrix[0].size() - 1;
  if (matrix[row][col] == 1)
  {
    right[row][col] = 1;
    down[row][col] = 1;
  }
  for (int i = row - 1; i >= 0; --i)
  {
    if (matrix[i][col] == 1)
    {
      down[i][col] = down[i + 1][col] + 1;
      right[i][col] = 1;
    }
  }
  for (int i = col - 1; i >= 0; --i)
  {
    if (matirx[row][i] == 1)
    {
      right[row][i] = right[row][i + 1] + 1;
      down[row][i] = 1;
    }
  }
  for (int i = row - 1; i >= 0; --i)
  {
    for (int j = col - 1; j >= 0; --j)
    {
      if (matrix[i][j] == 1)
      {
        right[i][j] = right[i][j + 1] + 1;
        down[i][j] = down[i + 1][j] + 1;
      }
    }
  }
}

//域处理数组O(n*n*n)
int MaxOneBorderSize(const vector<vector<int>>& matrix)
{
  if (matrix.empty() || matrix[0].empty())
  {
    return 0;
  }
  vector<vector<int>> right(matrix.size(), vector<int>(matrix[0].size(), 0));
  vector<vector<int>> down = right;
  SetBorder(matrix, right, down);
  //遍历边需要o(n) 仅仅只是少了判断边全部是1的代价
  for (int size = std::min(matrix.size(), matrix[0].size()); size >= 0; --size)
  {
    if (HasSizeOfBorder(size, right, down))
    {
      return size;
    }
  }
  return 0;
}
