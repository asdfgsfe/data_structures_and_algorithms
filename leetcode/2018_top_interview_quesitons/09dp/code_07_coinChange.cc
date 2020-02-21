class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        if (coins.empty())
        {
            return amount == 0 ? 0 : -1;
        }
        if (amount < 1)
        {
            return 0;
        }
        vector<int> dp(amount + 1, 0x7fffffff);
        dp[0] = 0;
        for (int i = 1; i < dp.size(); ++i)
        {
            for (int coin : coins)
            {
                if (i >= coin && dp[i - coin] != 0x7fffffff)
                {
                    dp[i] = std::min(dp[i], dp[i - coin] + 1);
                }
            }
        }
        return dp[amount] == 0x7fffffff ? -1 : dp[amount];
    }
};

//f(i) = f(i - c) + 1
//首先，让我们定义：F(S)：S 金额所需的最小硬币数量
//S：使用的硬币面值和[c0, c1, ...cn - 1]
//我们注意到这个问题有一个最优的子结构性质，这是解决任何动态规划问题的关键。
//最优解可以从其子问题的最优解构造出来。
//如何将问题分解成子问题？假设我们知道 F(S) ，对于金额 S 最少的硬币数，最后一枚硬币的面值是 C。
//那么由于问题的最优子结构以下方程应为：
//F(S) = F(S - C) + 1

链接：https://leetcode-cn.com/problems/coin-change/solution/ling-qian-dui-huan-by-leetcode/
