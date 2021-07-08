class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if (prices.size() < 2)
        {
            return 0;
        }
        vector<int> dp(prices.size() + 2, 0);
        for (int i = dp.size() - 3; i >= 0; --i)
        {
            dp[i] = dp[i + 1];
            for (int j = i; j < prices.size(); ++j)
            {
                if (prices[i] <= prices[j])
                {
                    dp[i] = std::max(dp[i], dp[j + 2] + prices[j] - prices[i]);
                }
            }
        }
        return dp[0];
    }
};


class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if (prices.size() < 2)
        {
            return 0;
        }
        vector<int> dp(prices.size() + 2, 0);
        for (int i = dp.size() - 3; i >= 0; --i)
        {
            dp[i] = dp[i + 1]; //这个位置不卖入卖出的情况
            //以下是卖出的情况
            for (int j = i; j < prices.size(); ++j)
            {
                if (prices[i] <= prices[j])
                {
                    dp[i] = std::max(dp[i], dp[j + 2] + prices[j] - prices[i]);
                }
            }
        }
        return dp[0];
    }
};



309. 最佳买卖股票时机含冷冻期
给定一个整数数组，其中第 i 个元素代表了第 i 天的股票价格 。​

设计一个算法计算出最大利润。在满足以下约束条件下，你可以尽可能地完成更多的交易（多次买卖一支股票）:

你不能同时参与多笔交易（你必须在再次购买前出售掉之前的股票）。
卖出股票后，你无法在第二天买入股票 (即冷冻期为 1 天)。
示例:

输入: [1,2,3,0,2]
输出: 3
解释: 对应的交易状态为: [买入, 卖出, 冷冻期, 买入, 卖出]
