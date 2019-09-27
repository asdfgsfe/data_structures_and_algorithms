
//这种情况只能搞出长度来 递归通用 待测试 仅仅感觉对
int LonggestSubArray(const vector<int>& nums, int aim)
{
	if (nums.empty() || aim < 1)
	{
		return 0;
	}
	int len = 0;
	for (int i = 0; i < nums.size(); ++i)
	{
		len = std::max(len, SumProcess(nums, i, aim));
	}
	return len;
}

//以每个位置开头的情况怎么怎么样
int SumProcess(const vector<int>& nums, int i, int aim)
{
	if (aim == 0)
	{
		return 0;
	}
	if (i == nums.size())
	{
		return -1;
	}
	return 1 + SumProcess(nums, i + 1, aim - nums[i]);
}

int LonggestSubArrayDp(const vector<int>& nums, int aim)
{
	if (nums.empty() || aim < 1)
	{
		return 0;
	}
	vector<vector<int>> dp(nums.size() + 1, vector<int>(aim + 1, -1));
	dp[dp.size() - 1][0] = 0;
	int len = 0;
	for (int i = dp.size() - 2; i >= 0; --i)
	{
		for (int j = 1; j < dp[0].size() && j - nums[i] >= 0; ++j)
		{
			dp[i][j] = 1 + dp[i + 1][j - nums[i]]
		}
	}
	return dp[0][dp.size() - 1];
}
