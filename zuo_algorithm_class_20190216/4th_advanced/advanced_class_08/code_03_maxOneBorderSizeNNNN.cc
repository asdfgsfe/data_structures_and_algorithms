//暴力o(n*n*n*n)
int MaxOneBorderSize(const vector<vector<int>>& matrix)
{
	if (matrix.empty() || matrix[0].empty())
	{
		return 0;
	}
	int maxSize = 0;
	//遍历o(n*n)
	for (int i = 0; i < matrix.size(); ++i)
	{
		for (int j = 0; j < matrix[0].size(); ++i)
		{
			maxSize = std::max(maxSize, ThisPointMaxSize(matrix, i, j));
		}
	}
	return maxSize;
}

int ThisPointMaxSize(const vector<vector<int>>& matrix, int row, int col)
{
	//遍历边o(n)
	for (int size = std::min(matrix.size() - row, matrix[0].size() - col); size >= 0; --size)
	{
		//检查边o(n)
		if (IsOneBorder(matrix, row, col, size))
		{
			return size;
		}
	}
	return 0;
}

bool IsOneBorder(const vector<vector<int>>& matrix, int row, int col, int size)
{
	int r = row;
	int c = col;
	for (int i = 0; i < size; ++i)
	{
		if (matrix[r][c] != 1)
		{
			return false;
		}
		++c;
	}
	for (int i = 0; i < size; ++i)
	{
		if (matrix[r][c] != 1)
		{
			return false;
		}
		++r;
	}
	for (int i = 0; i < size; ++i)
	{
		if (matrix[r][c] != 1)
		{
			return false;
		}
		--c;
	}
	for (int i = 0; i < size; ++i)
	{
		if (matrix[r][c] != 1)
		{
			return false;
		}
		--r;
	}
	return true;
}