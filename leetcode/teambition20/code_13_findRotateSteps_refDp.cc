class Solution {
public:
    int findRotateSteps(string ring, string key) {
		//dp[i][j]表示key的从0到i的字符匹配到ring的j字符需要的最小的step，
	    vector<vector<int>> dp(key.size() + 1, vector<int>(ring.size()));
		for (int i = dp.size() - 2; i >= 0; i--)
		{
			for (int j = 0; j < dp[0].size(); j++)
			{
				dp[i][j] = INT_MAX;
				for (int k = 0; k < ring.size(); k++)
				{
					if (key[i] == ring[k])
					{
						//一个环的长度固定 对于某一个字符 所以从只需要计算顺时针就行 
						//逆时针用环的长度减去就行
						int step = std::min(abs(j - k), (int)(ring.size() - abs(j - k)));
						//由于ring里面有可能有多个相同的这字符 所以从零开始完整的搞一遍
						//在所有情况中选出最小的
						dp[i][j] = std::min(dp[i][j], dp[i + 1][k] + step + 1);
					}
				}
			}
		}
		return dp[0][0];
    }
};