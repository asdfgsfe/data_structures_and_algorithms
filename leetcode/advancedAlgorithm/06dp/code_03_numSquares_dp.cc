class Solution {
public:
    int numSquares(int n) {
        if (n < 1) {
            return 0;
        }
        vector<long long> dp(n + 1, 0x7fffffff);
        dp[0] = 0;
        for (int i = 1; i < dp.size(); ++i) {
            for (int j = 1; j <= sqrt(i); ++j) {
                dp[i] = std::min(dp[i], 1 + dp[i - j * j]);
            }
        }
        return dp[n];
    }
};
