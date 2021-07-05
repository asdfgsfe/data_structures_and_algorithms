class Solution {
public:
	int findPeakElement(vector<int>& nums) {
		if (nums.empty())
		{
			return -1;
		}
		if (nums.size() < 2 || nums[0] > nums[1])
		{
			return 0;
		}
		if (nums[nums.size() - 2] < nums[nums.size() - 1])
		{
			return nums.size() - 1;
		}
		//剔除边界 很重要 防止m-1<0和m+1==nums.size()
		int l = 1;
		int r = nums.size() - 2;
		while (l <= r)
		{
			int m = l + (r - l) / 2;
			//注意这里保持同号很重要
			if (nums[m] < nums[m - 1])
			{
				r = m - 1;
			}
			else if (nums[m] < nums[m + 1])
			{
				l = m + 1;
			}
			else
			{
				return m;
			}
		}
		return -1;
	}
};
