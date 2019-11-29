class Solution {
public:
	int arrayPairSum(vector<int>& nums) {
		if (nums.size() < 2)
		{
			return 0;
		}
		return PairSumProcess(nums);
	}
	//删除数组中的元素的为目的来递归
	int PairSumProcess(vector<int>& nums)
	{
		if (nums.size() == 2)
		{
			return std::min(nums[0], nums[1]);
		}
		int  maxSum = 0x80000000;
		for (int i = 1; i < nums.size(); ++i)
		{
			vector<int> remove;
			for (int j = 1; j < nums.size(); ++j)
			{
				if (i != j)
				{
					remove.emplace_back(nums[j]);
				}
			}
			int sum = PairSumProcess(remove);
			maxSum = std::max(maxSum, std::min(nums[0], nums[i]) + sum);
		}
		return maxSum;
	}
};