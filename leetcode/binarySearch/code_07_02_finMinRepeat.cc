//寻找旋转排序数组中的最小值 II 有重复数字

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

class Solution {
public:
    int findMin(vector<int>& nums) {
        if (nums.size() < 2) {
            return nums.empty() ? 0x80000000 : nums[0];
        }
        if (nums[0] < nums[nums.size() - 1]) {
            return nums[0];
        }
        if (nums[nums.size() - 2] > nums[nums.size() - 1]) {
            return nums[nums.size() - 1];
        }
        int l = 1;
        int r = nums.size() - 2;
        while (l <= r) {
            int m = l + (r - l) / 2;
            if (nums[m] > nums[r]) {
                l = m + 1;
            } else if (nums[m] < nums[r]) {
                r = m;
			//可能在左边 也可能在右边 让r向左边移动一个 跳过重复数字
            } else {
                r -= 1;
            }
        }
        return nums[l];
    }
};
