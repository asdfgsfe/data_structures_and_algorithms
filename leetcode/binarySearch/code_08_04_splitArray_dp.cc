//410. 分割数组的最大值
给定一个非负整数数组 nums 和一个整数 m ，你需要将这个数组分成 m 个非空的连续子数组。

设计一个算法使得这 m 个子数组各自和的最大值最小。

 

示例 1：

输入：nums = [7,2,5,10,8], m = 2
输出：18
解释：
一共有四种方法将 nums 分割为 2 个子数组。 其中最好的方式是将其分为 [7,2,5] 和 [10,8] 。
因为此时这两个子数组各自的和的最大值为18，在所有情况中最小。
示例 2：

输入：nums = [1,2,3,4,5], m = 2
输出：9
示例 3：

输入：nums = [1,4,4], m = 3
输出：4
class Solution {
public:
    int splitArray(vector<int>& nums, int m) {
        if (nums.empty() || m < 0 || m > nums.size()) {
            return 0;
        }
        vector<int> sums(nums.size() + 1, 0);
        for (int i = 0; i < nums.size(); ++i) {
            sums[i + 1] = sums[i] + nums[i];
        }
        vector<vector<int>> dp(nums.size() + 1, vector<int>(m + 1, 0x7fffffff));
        dp[0][0] = 0;
        for (int i =  1; i < dp.size(); ++i) {
            for (int j = 1; j < dp[0].size(); ++j) {
                for (int k = 0; k < i; ++k) { //注意这里是 从0判断到i 由于是连续的子数组 0~1 0~2 ...
					//下面也是取dp[k][j - 1] 正常来说取加法也是可以的
                    dp[i][j] = std::min(dp[i][j], std::max(dp[k][j - 1], sums[i] - sums[k]));
                }
            }
        }
        return dp.back().back();
    }
};