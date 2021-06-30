class Solution {
	struct Path
	{
		int r;
		int c;
		int d;
		Path() = default;
		Path(int row, int col, int distance)
			: r(row), c(col), d(distance)
		{}
	};
public:
	vector<vector<int>> updateMatrix(vector<vector<int>>& matrix) {
		if (matrix.empty() || matrix[0].empty())
		{
			return {};
		}
		vector<vector<int>> distances(matrix.size(), vector<int>(matrix[0].size(), 0));
		for (int i = 0; i < matrix.size(); ++i)
		{
			for (int j = 0; j < matrix[0].size(); ++j)
			{
				if (matrix[i][j] == 0)
				{
					continue;
				}
				vector<vector<bool>> visited(matrix.size(), vector<bool>(matrix[0].size(), false));
				visited[i][j] = true;
				queue<Path> paths;
				paths.emplace(i, j, 0);
				while (!paths.empty())
				{
					Path path = paths.front();
					paths.pop();
					int r = path.r;
					int c = path.c;
					if (matrix[r][c] == 0)
					{
						distances[i][j] = path.d;
						break;
					}
					//可以在这里 提前进行判断 如果mat[r][c] == 0, 就break 然后用这个path 应该就不超时了
					if (r > 0 && !visited[r - 1][c])
					{
						paths.emplace(r - 1, c, path.d + 1);
						visited[r - 1][c] = true;
					}
					if (c > 0 && !visited[r][c - 1])
					{
						paths.emplace(r, c - 1, path.d + 1);
						visited[r][c - 1] = true;
					}
					if (r < matrix.size() - 1 && !visited[r + 1][c])
					{
						paths.emplace(r + 1, c, path.d + 1);
						visited[r + 1][c] = true;
					}
					if (c < matrix[0].size() - 1 && !visited[r][c + 1])
					{
						paths.emplace(r, c + 1, path.d + 1);
						visited[r][c + 1] = true;
					}
				}
			}
		}
		return distances;
	}
};
