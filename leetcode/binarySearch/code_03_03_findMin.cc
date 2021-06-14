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
				//这里一定是 大于r 不能是大于l 因为l有可能是目标答案
				//只有大于左边最大的 才能知道m处于右边
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

//代码好理解一点
class Solution {
public:
    int findMin(vector<int>& nums) {
        if (nums.size() < 2) {
            return nums.empty() ? 0x80000000 : nums[0];
        }
        if (nums[0] < nums[nums.size() - 1]) {
            return nums[0];
        }
        if (nums[nums.size() - 1] < nums[nums.size() - 2]) {
            return nums.back();
        }

        int l = 1;
        int r = nums.size() - 2;
        while (l <= r) {
            int m = l + (r - l) / 2;
            if (nums[m] < nums[m - 1] && nums[m] < nums[m + 1]) {
                return nums[m];
            }
            if (nums[m] > nums[r]) {
                l = m + 1;
            } else {
                r = m - 1;
            }
        }
        return 0x80000000;
    }
};
