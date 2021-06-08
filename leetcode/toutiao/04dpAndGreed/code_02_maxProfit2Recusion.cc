//122. 买卖股票的最佳时机 II
给定一个数组 prices ，其中 prices[i] 是一支给定股票第 i 天的价格。

设计一个算法来计算你所能获取的最大利润。你可以尽可能地完成更多的交易（多次买卖一支股票）。

注意：你不能同时参与多笔交易（你必须在再次购买前出售掉之前的股票）。

 

示例 1:

输入: prices = [7,1,5,3,6,4]
输出: 7
解释: 在第 2 天（股票价格 = 1）的时候买入，在第 3 天（股票价格 = 5）的时候卖出, 这笔交易所能获得利润 = 5-1 = 4 。
     随后，在第 4 天（股票价格 = 3）的时候买入，在第 5 天（股票价格 = 6）的时候卖出, 这笔交易所能获得利润 = 6-3 = 3 。
示例 2:

输入: prices = [1,2,3,4,5]
输出: 4
解释: 在第 1 天（股票价格 = 1）的时候买入，在第 5 天 （股票价格 = 5）的时候卖出, 这笔交易所能获得利润 = 5-1 = 4 。
     注意你不能在第 1 天和第 2 天接连购买股票，之后再将它们卖出。因为这样属于同时参与了多笔交易，你必须在再次购买前出售掉之前的股票。
示例 3:

输入: prices = [7,6,4,3,1]
输出: 0
解释: 在这种情况下, 没有交易完成, 所以最大利润为 0。
 

提示：

1 <= prices.length <= 3 * 104
0 <= prices[i] <= 104

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if (prices.size() < 2)
        {
            return 0;
        }
        int profit = 0;
        for (int i = 0; i < prices.size(); ++i)
        {
            profit = std::max(profit, BuyProcess(prices, i));
        }
        return profit;
    }
    
    int BuyProcess(const vector<int>& prices, int buyIn)
    {
        if (buyIn == prices.size())
        {
            return 0;
        }
        int maxProfit = 0;
        //从这个时间点买入股票 以后可以出售时间段就出售 赚取的最大利益
        for (int out = buyIn + 1; out < prices.size(); ++out)
        {     
            if (prices[buyIn] < prices[out])
            {
                int profit = prices[out] - prices[buyIn] + BuyProcess(prices, out + 1);
                maxProfit = std::max(maxProfit, profit);
            }
        }
        //虽然这个时间段可以买入 但是我不从这个点买入 从以后的时间点再买
        //最后在买与不买之间选择最大值
        maxProfit = std::max(maxProfit, BuyProcess(prices, buyIn + 1));
        return maxProfit;
    }
};
