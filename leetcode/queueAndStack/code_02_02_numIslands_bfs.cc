class Solution {
public:
	int numIslands(vector<vector<char>>& grid) {
		if (grid.empty())
		{
			return 0;
		}
		int cnt = 0;
		for (int i = 0; i < grid.size(); ++i)
		{
			for (int j = 0; j < grid[0].size(); ++j)
			{
				if (grid[i][j] == '0')
				{
					continue;
				}
				++cnt;
				queue<pair<int, int>> points;
				points.emplace( i, j );
				while (!points.empty())
				{
					int r = points.front().first;
					int c = points.front().second;
					points.pop();
					grid[r][c] = '0';
					if (r > 0 && grid[r - 1][c] == '1')
					{
						points.emplace( r - 1, c );
					}
					if (c > 0 && grid[r][c - 1] == '1')
					{
						points.emplace(r, c - 1);
					}
					if (r < grid.size() - 1 && grid[r + 1][c] == '1')
					{
						points.emplace(r + 1, c);
					}
					if (c < grid[0].size() - 1 && grid[r][c + 1] == '1')
					{
						points.emplace(r, c + 1);
					}
				}
			}
		}
		return cnt;
	}
};


//²Î¿¼´ð°¸
class Solution {
public:
  int numIslands(vector<vector<char>>& grid) {
    int nr = grid.size();
    if (!nr) return 0;
    int nc = grid[0].size();

    int num_islands = 0;
    for (int r = 0; r < nr; ++r) {
      for (int c = 0; c < nc; ++c) {
        if (grid[r][c] == '1') {
          ++num_islands;
          grid[r][c] = '0'; // mark as visited
          queue<pair<int, int>> neighbors;
          neighbors.push({r, c});
          while (!neighbors.empty()) {
            auto rc = neighbors.front();
            neighbors.pop();
            int row = rc.first, col = rc.second;
            if (row - 1 >= 0 && grid[row-1][col] == '1') {
              neighbors.push({row-1, col}); grid[row-1][col] = '0';
            }
            if (row + 1 < nr && grid[row+1][col] == '1') {
              neighbors.push({row+1, col}); grid[row+1][col] = '0';
            }
            if (col - 1 >= 0 && grid[row][col-1] == '1') {
              neighbors.push({row, col-1}); grid[row][col-1] = '0';
            }
            if (col + 1 < nc && grid[row][col+1] == '1') {
              neighbors.push({row, col+1}); grid[row][col+1] = '0';
            }
          }
        }
      }
    }

    return num_islands;
  }
};