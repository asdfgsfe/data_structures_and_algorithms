//域处理数组的方法 各种数据通用o(n*n)
vector<int> LonggestSubArray(const vector<int>& nums, int aim)
{
	if (nums.empty() || aim < 1)
	{
		return 0;
	}
	vector<int> sums(nums.size(), 0);
	sums[0] = nums[0];
	for (int i = 1; i < nums.size(); ++i)
	{
		sums[i] = sums[i - 1] + nums[i];
	}
	int len = 0;
	int l = -1;
	int r = -1;
	for (int i = 0; i < nums.size(); ++i)
	{
		for (int j = i; j < nums.size(); ++j)
		{
			if (nums[j] - nums[i] == aim && len < (j - i + 1))
			{
				len = j -i + 1;
				l = i;
				r = j
			}
		}
	}
	return {l, r};
}