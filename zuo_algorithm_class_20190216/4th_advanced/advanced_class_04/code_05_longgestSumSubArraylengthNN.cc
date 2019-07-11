int LonggestSubArrayLength(const vector<int>& nums, int sum)
{
	if (nums.empty())
	{
		return 0;
	}
	vector<int> sums(nums.size(), 0);
	sums[0] = nums[0];
	for (int i = 1; i < nums.size(); ++i)
	{
		sums[i] = nums[i] + sums[i - 1];
	}
	int longgest = 0;
	for (int i = 0; i < nums.size(); ++i)
	{
		for (int j = 0; j < nums.size(); ++j)
		{
			if (nums[j] - nums[i] == sum)
			{
				longgest = std::max(longgest, j - i);
			}
		}
	}
	return longgest;
}