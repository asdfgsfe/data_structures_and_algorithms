class Solution {
public:
	//二分答案的思想
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
			//要选出所有切分子数组和的最大值 所以这里用max
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
		long long sum = 0;
		int cnt = 1;
		for (int num : nums)
		{
			sum += num;
			//我已经是当前分出来的最大值 如果累加到i 此刻累加和大于我 则从i开始又是一个新的切割
			//按照这种切分 如果数量大于m 则这种切分不能将整个切分成m份 是一种错误的切分
			//如果按照这种方法切分数量小于等于m 那么一定可以切完 因为全部是正数 单独一个数字和值是最小的和
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