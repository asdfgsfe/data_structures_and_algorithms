#include <iostream>
#include <vector>

using std::vector;

class Solution {
public:
    void Dump(const vector<int>& v)
    {
        for (int val : v)
        {
            std::cout << val << " ";
        }
        std::cout << std::endl;
    }


    int maxProfit(vector<int>& prices) {
        if (prices.size() < 2)
        {
            return 0;
        }
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
            maxProfit = std::max(maxProfit, dp[i]);
        }
        Dump(dp);
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

int main(void)
{
    int n;
    std::cin >> n;
    vector<int> prices(n);
    for (int i = 0; i < n; ++i)
    {
        std::cin >> prices[i];
    }
    Solution s;
    std::cout << s.maxProfit(prices) << std::endl;
    return 0;
}
