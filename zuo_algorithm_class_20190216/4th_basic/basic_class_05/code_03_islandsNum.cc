int IslandsNum(const vector<vector<int>>& matrix)
{
	int num = 0;
	for (int i = 0; i < matrix.size(); ++i)
	{
		for (int j = 0; j < matrix.front().size(); ++j)
		{
			if (matrix[i][j] == 1)
			{
				++num;
				Infect(matrix, i, j);
			}
		}
	}
	return num;
}

void Infect(const vector<vector<int>>& matrix, int r, int c)
{
	if (r < 0 || r >= matrix.size() || c < 0 || c >= matrix.front().size() || matrix[r][c] != 1)
	{
		return;
	}
	matrix[r][c] = 2;
	Infect(matrix, r, c + 1);
	Infect(matrix, r, c - 1);
	Infect(matrix, r + 1, c);
	Infect(matrix, r - 1, c);
}