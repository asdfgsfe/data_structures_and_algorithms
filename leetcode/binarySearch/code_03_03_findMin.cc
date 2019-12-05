class Solution {
public:
	int findMin(vector<int>& nums) {
		if (nums.empty())
		{
			return -1;
		}
		if (nums.size() < 2 || nums.front() < nums.back())
		{
			return nums[0];
		}
		if (nums[nums.size() - 2] > nums[nums.size() - 1])
		{
			return nums.back();
		}
		//掌握这种剔除边界的技巧
		int l = 1;
		int r = nums.size() - 2;
		while (l <= r)
		{
			int m = l + (r - l) / 2;
			if (nums[m] < nums[m - 1])
			{
				return nums[m];
			}
			else
			{
				if (nums[m] > nums[r])
				{
					l = m + 1;
				}
				else
				{
					r = m - 1;
				}
			}
		}
		return -1;
	}
};