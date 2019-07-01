int RobotMoveCount(int m, int n, int k)
{
  if (m < 1 || n < 1)
  {
    return 0;
  }
  vector<vector<bool>> visited(m, vector<bool>(n, false));
  return MovingCountProcess(0, m, 0, n, k, visited);
}

int MovingCountProcess(int row, int col, int rows, int cols, int k, vector<vector<bool>>& visited)
{
  int count = 0;
  if (CheckIsPass(row, rows, col, cols, k, visited))
  {
    visited[row][col] = true;
    count = 1 + MovingCountProcess(row + 1, rows, col, cols, k, visited)
              + MovingCountProcess(row - 1, rows, col, cols, k, visited)
              + MovingCountProcess(row, rows, col + 1, cols, k, visited)
              + MovingCountProcess(row, rows, col -1, cols, k, visited);
  }
  return count;
}

bool CheckIsPass(int row, int rows, int col, int cols, int k, vector<vector<bool>>& visited)
{
  if (row >= 0 && row < rows && col >= 0 && col < cols 
      && !visited[row][col]
      && (DigitSum(row) + DigitSum(row) <= k))
  {
    return true;
  }
  return false;
}

int DigitSum(int num)
{
  int sum = 0;
  while (num)
  {
    sum += num % 10;
    num /= 10;
  }
  return sum;
}
