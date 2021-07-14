class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        if (coins.empty() || amount < 0) {
            return -1;
        }
        vector<int> dp(amount + 1, 0x7fffffff);
        dp[0] = 0;
        for (int i = 1; i < dp.size(); ++i) {
            for (int c : coins) {
                if (i - c >= 0 && dp[i - c] != 0x7fffffff) {
                    dp[i] = std::min(dp[i], 1 + dp[i - c]);
                }
            }
        }
        return dp[amount] == 0x7fffffff ? -1 : dp[amount];
    }
};

零钱兑换
给定不同面额的硬币 coins 和一个总金额 amount。编写一个函数来计算可以凑成总金额所需的最少的硬币个数。如果没有任何一种硬币组合能组成总金额，返回 -1。

你可以认为每种硬币的数量是无限的。

 

示例 1：

输入：coins = [1, 2, 5], amount = 11
输出：3
解释：11 = 5 + 5 + 1
示例 2：

输入：coins = [2], amount = 3
输出：-1
示例 3：

输入：coins = [1], amount = 0
输出：0
示例 4：

输入：coins = [1], amount = 1
输出：1
示例 5：

输入：coins = [1], amount = 2
输出：2
 

提示：

1 <= coins.length <= 12
1 <= coins[i] <= 231 - 1
0 <= amount <= 104
相关标签
广度优先搜索
数组
动态规划

作者：力扣 (LeetCode)
链接：https://leetcode-cn.com/leetbook/read/top-interview-questions-medium/xvf0kh/
来源：力扣（LeetCode）
著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。
