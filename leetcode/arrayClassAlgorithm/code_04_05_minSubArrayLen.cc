209. 长度最小的子数组
给定一个含有 n 个正整数的数组和一个正整数 target 。

找出该数组中满足其和 ≥ target 的长度最小的 连续子数组 [numsl, numsl+1, ..., numsr-1, numsr] ，并返回其长度。如果不存在符合条件的子数组，返回 0 。

 

示例 1：

输入：target = 7, nums = [2,3,1,2,4,3]
输出：2
解释：子数组 [4,3] 是该条件下的长度最小的子数组。
示例 2：

输入：target = 4, nums = [1,4,4]
输出：1
示例 3：

输入：target = 11, nums = [1,1,1,1,1,1,1,1]
输出：0


//滑动窗口
class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        if (nums.empty()) {
            return 0;
        }
        int len = 0x7fffffff;
        int l = 0;
        int r = 0;
        int sum = 0;
		//注意这里nums.size()的时候 是一个答案
        while (r <= nums.size()) {
            if (sum < target) {
                sum += nums[r++];
            } else {
                len = std::min(len, r - l);
                sum -= nums[l++];
            }
			//保证数组不越界
            if (sum < target && r == nums.size()) {
                break;
            }
        }
        return len == 0x7fffffff ? 0 : len;
    }
};
