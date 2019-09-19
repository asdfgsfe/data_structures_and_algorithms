买卖股票的最佳时机 II
给定一个数组，它的第 i 个元素是一支给定股票第 i 天的价格。

设计一个算法来计算你所能获取的最大利润。你可以尽可能地完成更多的交易（多次买卖一支股票）。

注意：你不能同时参与多笔交易（你必须在再次购买前出售掉之前的股票）。

示例 1:

输入: [7,1,5,3,6,4]
输出: 7
解释: 在第 2 天（股票价格 = 1）的时候买入，在第 3 天（股票价格 = 5）的时候卖出, 这笔交易所能获得利润 = 5-1 = 4 。
     随后，在第 4 天（股票价格 = 3）的时候买入，在第 5 天（股票价格 = 6）的时候卖出, 这笔交易所能获得利润 = 6-3 = 3 。
示例 2:

输入: [1,2,3,4,5]
输出: 4
解释: 在第 1 天（股票价格 = 1）的时候买入，在第 5 天 （股票价格 = 5）的时候卖出, 这笔交易所能获得利润 = 5-1 = 4 。
     注意你不能在第 1 天和第 2 天接连购买股票，之后再将它们卖出。
     因为这样属于同时参与了多笔交易，你必须在再次购买前出售掉之前的股票。
示例 3:

输入: [7,6,4,3,1]
输出: 0
解释: 在这种情况下, 没有交易完成, 所以最大利润为 0。

//贪心算法，买卖次数不限，问题就简单了，只要挣钱就卖出。
class Solution {
public:
	    int maxProfit(vector<int>& prices) {
        if (prices.empty())
        {
            return 0;
        }
        int profit = 0;
		for (int i = 0; i < prices.size() - 1; ++i)
		{
            if (prices[i + 1] > prices[i])
            {
                profit += prices[i + 1] - prices[i];
            }
		}
        return profit;
    }
};

//dp解法 但是会超时貌似这个dp有问题 少了我这个点开始不买的情况
class Solution {
public:
	    int maxProfit(vector<int>& prices) {
        if (prices.empty())
        {
            return 0;
        }
        int profit = 0;
        vector<int> dp(prices.size() + 1, 0);
		for (int i = dp.size() - 2; i >= 0; --i)
		{
			for (int j = i; j < prices.size(); ++j)
			{
                dp[i] = std::max(dp[i], dp[j + 1] + prices[j] - prices[i]);
                profit = std::max(profit, dp[i]);
            }
		}
        return profit;
    }
};

//递归
class Solution {
public:
	int maxProfit(vector<int>& prices) {
        if (prices.empty())
        {
            return 0;
        }
        int profit = 0;
        for (int i = 0; i < prices.size(); ++i)
        {
            profit = std::max(profit, BuyProcess(prices, i, i + 1));
        }
        return profit;
    }
    
    int BuyProcess(const vector<int>& prices, int i, int j)
    {
        if (j == prices.size())
        {
            return 0;
        }
        assert(i < j);
        int profit = 0;
        for (int end = j; end < prices.size(); ++end)
        {
            profit = std::max(profit, BuyProcess(prices, end + 1, end + 1) + prices[end + 1] - prices[i]);
        }
        return profit;
    }

//原始dp
	int maxProfit(vector<int>& prices) {
        if (prices.empty())
        {
            return 0;
        }
        int profit = 0;
		vector<vector<int>> dp(prices.size() + 1, vector<int>(prices.size() + 1), 0);
		for (int i = dp.size() - 2; i >= 0; --i)
		{
			for (int j = dp.size() - 2; j >= 0; --j)
			{
				for (int end = j; end < prices.size(); ++end) //遍历行为可以优化下去 用j的遍历代替
				{
					dp[i][j] = dp[end + 1][end + 1] + prices[end + 1] - prices[i];
				}
			}
		}
        return dp[0][1];
    }
};

