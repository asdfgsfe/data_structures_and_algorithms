class Solution {
public:
	int kInversePairs(int n, int k) {
		if (n < 1)
		{
			return 0;
		}
		if (k < 1)
		{
			return 1;
		}
        const static int mod = 1000000007;
		vector<vector<int>> dp(n + 1, vector<int>(k + 1, 0));
		dp[1][0] = 1;
		for (int i = 2; i < dp.size(); ++i)
		{
			dp[i][0] = 1;
			for (int j = 1; j < dp[0].size(); ++j)
			{
				dp[i][j] = (dp[i][j - 1] + dp[i - 1][j]) % mod;
				if (j - i >= 0)
				{
					dp[i][j] = (dp[i][j] - dp[i - 1][j - i] + mod) % mod;
				}
			}
		}
		return dp[n][k];
	}
};


//矩阵压缩技术 其实只依赖于他上面的一行 仅仅减小了空间复杂度
class Solution {
public:
    int kInversePairs(int n, int K) {
        int64_t dp[2][K+1];
        memset(dp, 0, sizeof(dp));
        int pre = 0;
        int cur = 1;
        constexpr int mod = 1e9 + 7;
        dp[0][0] = 1;
        for (int i = 2; i <= n; i++) {
            dp[cur][0] = 1;
            for (int k = 1; k <= K; k++) {
                dp[cur][k] = 1;
                if (k >= i) {
                    dp[cur][k] = (dp[pre][k] + dp[cur][k-1] + mod - dp[pre][k-i]) % mod;
                } else {
                    dp[cur][k] = (dp[pre][k] + dp[cur][k-1]) % mod;
                }
            }
            swap(pre, cur);
        }
        return dp[pre][K];
    }
};