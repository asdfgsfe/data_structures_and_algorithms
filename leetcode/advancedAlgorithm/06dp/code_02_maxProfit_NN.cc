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