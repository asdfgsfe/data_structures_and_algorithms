int SubArrayMaxSum(const vector<int>& nums)
{
	if (nums.empty())
	{
		return 0;
	}
	int curSum = nums[0];
	int maxSum = nums[0];
	for (int i = 1; i < nums.size(); ++i)
	{
		curSum = std::max(nums[i], curSum + nums[i]);
		maxSum = std::max(maxSum, curSum);
	}
	return maxSum;
}