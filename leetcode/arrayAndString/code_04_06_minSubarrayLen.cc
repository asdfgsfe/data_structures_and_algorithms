长度最小的子数组
给定一个含有 n 个正整数的数组和一个正整数 target 。

找出该数组中满足其和 ≥ target 的长度最小的 连续子数组 [numsl, numsl+1, ..., numsr-1, numsr] ，并返回其长度。如果不存在符合条件的子数组，返回 0 。

 

示例 1：

输入：target = 7, nums = [2,3,1,2,4,3]
输出：2
解释：子数组 [4,3] 是该条件下的长度最小的子数组。
示例 2：

输入：target = 4, nums = [1,4,4]
输出：1
示例 3：

输入：target = 11, nums = [1,1,1,1,1,1,1,1]
输出：0
 

提示：

1 <= target <= 109
1 <= nums.length <= 105
1 <= nums[i] <= 105
 

进阶：

如果你已经实现 O(n) 时间复杂度的解法, 请尝试设计一个 O(n log(n)) 时间复杂度的解法。

作者：力扣 (LeetCode)
链接：https://leetcode-cn.com/leetbook/read/array-and-string/c0w4r/
来源：力扣（LeetCode）
著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。

//滑动窗口
//和下面的代码差不多
//由于数组中 全部是正数 target是正数 所有才可以这么做
class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        if (nums.empty()) {
            return 0;
        }
        int minLen = 0x7fffffff;
        int n = 0;
        int p = 0;
        int sum = 0;
		//<=
        while (n < nums.size()) {
            while (n < nums.size() && sum < target) {
                sum += nums[n++];
            }
            while (sum >= target) {
                minLen = std::min(minLen, n - p);
                sum -= nums[p++];
            }
        }
        return minLen == 0x7fffffff ? 0 : minLen;
    }
};

class Solution {
public:
	int minSubArrayLen(int s, vector<int>& nums) {
		if (nums.empty() || s < 1)
		{
			return 0;
		}
		int len = 0x7fffffff;
		int l = 0;
		int f = 0;
		int sum = 0;
		while (f <= nums.size())
		{
			if (sum < s)
			{
				sum += nums[f++];
			}
			else
			{
	
				len = std::min(len, f - l);
				sum -= nums[l++];
			}
			if (sum < s && f == nums.size())
			{
				break;
			}
		}
		return len == 0x7fffffff ? 0 : len;
	}
};
