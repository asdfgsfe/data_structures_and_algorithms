bool SortedMatrixFindK(const vector<vector<int>>& matrix, int k)
{
	if (matrix.empty() || matrix.front().empty())
	{
		return false;
	}
	int r = 0;
	int c = matrix.front().size() - 1;
	while (c >= 0 && r < matrix.size())
	{
		if (matrix[r][c] == k)
		{
			return true;
		}
		else if (matrix[r][c] > k)
		{
			--c;
		}
		else
		{
			++r;
		}
	}
	return false;
}