class Solution {
public:
    int findMin(vector<int>& nums) {
        if (nums.empty())
        {
            return 0x7fffffff;
        }
        int l = 0;
        int r = nums.size() - 1;
        while (l < r)
        {
            int m = l + (r - l) / 2;
			//搞明白 l一定处于左边半部分 r一定处于右边半部分 所以才能这么判断
            if (nums[m] > nums[r])
            {
                l = m + 1;
            }
            else if (nums[m] < nums[r])
            {
                r = m;//m有可能是答案
            }
            else
            {
                r = r - 1;
            }
        }
        return nums[l];
    }
};