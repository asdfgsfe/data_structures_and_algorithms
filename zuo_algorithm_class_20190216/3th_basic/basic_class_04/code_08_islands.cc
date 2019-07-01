void Infection(vector<vector<int>>& islands, int r, int c, int rows, int cols)
{
  if (r < 0 || r == rows || c < 0 || c == cols || islands[r][c] != 1)
  {
    return;
  }
  islands[r][c] = 2;
  Infection(islands, r + 1, c, rows, cols);
  Infection(islands, r - 1, c, rows, cols);
  Infection(islands, r, c + 1, rows, cols);
  Infection(islandfs, r, c - 1, rows, cols);
}

int CountIslands(vector<vector<int>>& islands)
{
  if (islands.empty() || islands[0].empty())
  {
    return 0;
  }
  int count = 0;
  for (int i = 0; i < islands.size(); ++i)
  {
    for (int j = 0; j < islands[0].size(); ++j)
    {
      if (islands[i][j] == 1)
      {
        ++count;
        Infection(islands, i, j, islands.size(), islands[0].size());
      }
    }
  }
  return count;
}
