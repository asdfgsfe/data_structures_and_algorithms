int MinPath(const vector<int>& matrix)
{
	if (matrix.empty() || matrix.front().empty())
	{
		return 0;
	}
	//可以对dp行和列多增加一行一列 然后就可以初始化位0 减少了下面的初始化操作
	vector<vector<int>> dp(matrix.size(), vector<int>(matrix.front().size(), 0));
	dp.back().back() = matrix.back().back();
	for (int i = dp.size() - 2; i >= 0; --i)
	{
		dp[i][dp[0].size() - 1] = dp[i + 1][dp[0].size() - 1] + matrix[i][matrix[0].size() - 1];
	}
	for (int i = dp[0].size() - 2; i >= 0; --i)
	{
		dp[dp.size() - 1][i] = dp[dp.size() - 1][i + 1] + matrix[matrix.size() - 1][i];
	}
	for (int i = dp.size() - 2; i >= 0; --i)
	{
		for (int j = dp[0].size() - 2; j >= 0; --j)
		{
			dp[i][j] = std::min(dp[i + 1][j], dp[i][j + 1]) + matrix[i][j];
		}
	}
	return dp[0][0];
}

int MinPath2(const vector<int>& matrix)
{
	if (matrix.empty() || matrix.front().empty())
	{
		return 0;
	}
	int rows = std::max(matrix.size(), matrix[0].size());
	int cols = std::min(matrix.size(), matrix[0].size());
	vector<int> dp(cols);
	dp[0] = matrix[0][0];
	for (int i = 1; i < cols; ++i)
	{
		dp[i] = dp[i - 1] + (matrix.size() > matrix[0].size() ? matrix[0][i] : matrix[i][0]);
	}
	for (int i = 1; i < rows; ++i)
	{
		dp[0] += matrix[i][0];
		for (int j = 1; j < cols; ++j)
		{
			dp[j] = std::min(dp[j - 1], dp[j]) + (matrix.size() > matrix[0].size() ? matirx[i][j] : matrix[j][i]);
		}
	}
	return dp[cols];
}