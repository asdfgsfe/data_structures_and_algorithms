class Solution {
public:
	int splitArray(vector<int>& nums, int m) {
		if (nums.empty() || m < 0)
		{
			return 0;
		}
		long long maxSum = 0;
		long long minSum = 0;
		for (int num : nums)
		{
			maxSum += num;
			minSum = std::max(minSum, (long long)num);
		}
		while (minSum <= maxSum)
		{
			long long half = (maxSum + minSum) / 2;
			if (CanSplit(nums, m, half))
			{
				maxSum = half - 1;
			}
			else
			{
				minSum = half + 1;
			}
		}
		return minSum;
	}

	bool CanSplit(const vector<int>& nums, int m, long long maxSum)
	{
		//统计最小和为maxSum的子数组有多少个
		//如果多与m个 说明maxSum分划分小了 应该向右边走
		long long sum = 0;
		int cnt = 1;
		for (int num : nums)
		{
			sum += num;
			if (sum <= maxSum)
			{
				continue;
			}
			++cnt;
			sum = num;
			if (cnt > m)
			{
				return false;
			}
		}
		return true;
	}
};
