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
				if (grid[i][j] == '1')
				{
					InfectProcess(grid, i, j);
					++cnt;
				}
			}
		}
		return cnt;
	}

	void InfectProcess(vector<vector<char>>& grid, int i, int j)
	{
		if (i < 0 || i >= grid.size() || j < 0 || j >= grid[0].size() || grid[i][j] != '1')
		{
			return;
		}
		grid[i][j] = '2';
		InfectProcess(grid, i + 1, j);
		InfectProcess(grid, i, j + 1);
		InfectProcess(grid, i - 1, j);
		InfectProcess(grid, i, j - 1);
	}
};