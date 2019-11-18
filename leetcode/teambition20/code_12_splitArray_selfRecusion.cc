class Solution {
public:
	int splitArray(vector<int>& nums, int m) {
		if (nums.empty() || m < 1)
		{
			return 0;
		}
		vector<int> sums;
		int minSum = 0x7fffffff;
		SplitProcess(nums, 0, m, sums, minSum);
		return minSum;
	}

	//掌握这种从头向下遍历 收集结果的方法
	void SplitProcess(const vector<int>& nums, int i, int m, vector<int>& sums, int& minSum)
	{
		if (i == nums.size() && m == 0)
		{
			int maxSum = 0x80000000;
			for (int sum : sums)
			{
				maxSum = std::max(sum, maxSum);
			}
			minSum = std::min(maxSum, minSum);
			return;
		}
		if (i >= nums.size() || m <= 0)
		{
			return;
		}
		int sum = 0;
		for (int s = i; s < nums.size(); ++s)
		{
			sum += nums[s];
			sums.emplace_back(sum);
			SplitProcess(nums, s + 1, m - 1, sums, minSum);
			sums.pop_back();
		}
	}
};