class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if (prices.size() < 2)
        {
            return 0;
        }

        //有i点买入和不买入两种情况
        //思想是从i点买入 out点卖出能获得最大收益
        //dp[i]表示i点买入能获取的最大利益, 答案比在其中
        int maxProfit = 0;
        vector<int> dp(prices.size(), 0);
        for (int i = dp.size() - 2; i >= 0; --i)
        {
            //i点买入 其后面某一个点卖出 所能获取的最大利益
            for (int out = i + 1; out < prices.size(); ++out)
            {
                if (prices[i] < prices[out])
                {
                    int profit = prices[out] - prices[i];
                    profit = out + 1 < dp.size() ? profit + dp[out + 1] : profit;
                    dp[i] = std::max(dp[i], profit);
                }
            }
            //i点不买入时候的最大利益
            dp[i] = std::max(dp[i], dp[i + 1]);
            maxProfit = std::max(maxProfit, dp[i]);
        }
        return maxProfit;
    }
};

//最原声的想法 从递归出发
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if (prices.size() < 2)
        {
            return 0;
        }
        //int profit = 0;
        //for (int i = 0; i < prices.size(); ++i)
        //{
        //    profit = std::max(profit, BuyProcess(prices, i));
        //}
        
        int maxProfit = 0;
        vector<int> dp(prices.size(), 0);
        for (int i = dp.size() - 2; i >= 0; --i)
        {
            for (int out = i + 1; out < prices.size(); ++out)
            {
                if (prices[i] < prices[out])
                {
                    int profit = prices[out] - prices[i];
                    if (out + 1 < dp.size())
                    {
                        profit += dp[out + 1];
                    }
                    dp[i] = std::max(dp[i], profit);
                }
            }
            dp[i] = std::max(dp[i], dp[i + 1]);
            //if (i + 1 < prices.size())
            {
                maxProfit = std::max(maxProfit, dp[i]);
            }
        }
        return maxProfit;
    }
    
    int BuyProcess(const vector<int>& prices, int buyIn)
    {
        if (buyIn == prices.size())
        {
            return 0;
        }
        int maxProfit = 0;
        for (int out = buyIn + 1; out < prices.size(); ++out)
        {     
            if (prices[buyIn] < prices[out])
            {
                int profit = prices[out] - prices[buyIn] + BuyProcess(prices, out + 1);
                maxProfit = std::max(maxProfit, profit);
            }
        }
        maxProfit = std::max(maxProfit, BuyProcess(prices, buyIn + 1));
        return maxProfit;
    }
};
