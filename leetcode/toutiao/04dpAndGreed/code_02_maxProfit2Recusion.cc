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
