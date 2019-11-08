class Solution {
public:
	int searchInsert(vector<int>& nums, int target) {
		if (nums.empty())
		{
			return -1;
		}
        if (target < nums[0])
        {
            return 0;
        }
        if (target > nums.back())
        {
            return nums.size();
        }
		int l = 0;
		int r = nums.size() - 1;
		int p = -1;
		while (l <= r)
		{
			int m = (l + r) / 2;
			if (nums[m] >= target)
			{
				p = m;
				r = m - 1;
			}
			else
			{
				l = m + 1;
			}
		}
		return p;
	}
};