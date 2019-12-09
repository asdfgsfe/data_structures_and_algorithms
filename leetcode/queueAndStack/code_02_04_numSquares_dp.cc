//如果能用dfs 一定要想到dp优化
class Solution {
public: 
		int numSquares(int n) {
		if (n < 4)
		{
			return n;
		}
		vector<int> dp(n + 1, 0x7fffffff);
		for (int i = 0; i < 4; ++i)
		{
			dp[i] = i;
		}
		for (int i = 4; i < dp.size(); ++i)
		{
			for (int k = sqrt(i); k >= 1; --k)
			{
				dp[i] = std::min(dp[i], dp[i - k * k] + 1);
			}
		}
		return dp[n];
	}
};