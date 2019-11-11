 交错字符串
给定三个字符串 s1, s2, s3, 验证 s3 是否是由 s1 和 s2 交错组成的。

示例 1:

输入: s1 = "aabcc", s2 = "dbbca", s3 = "aadbbcbcac"
输出: true
示例 2:

输入: s1 = "aabcc", s2 = "dbbca", s3 = "aadbbbaccc"
输出: false

class Solution {
public:
	bool isInterleave(string s1, string s2, string s3) {
		if (s1.empty())
		{
			return s2 == s3;
		}
		if (s2.empty())
		{
			return s1 == s3;
		}
		if (s1.size() + s2.size() != s3.size())
		{
			return false;
		}
		vector<vector<bool>> dp(s1.size() + 1, vector<bool>(s2.size() + 1, false));
		for (int i = dp.size() - 1; i >= 0; --i)
		{
			for (int j = dp[0].size() - 1; j >= 0; --j)
			{
				if (i == s1.size() && j == s2.size())
				{
					dp[i][j] = true;
				}
				else if ((i == s1.size() || s1[i] != s3[i + j]) && s2[j] == s3[i + j])
				{
					dp[i][j] = dp[i][j + 1];
				}
				else if ((j == s2.size() || s2[j] != s3[i + j]) && s1[i] == s3[i + j])
				{
					dp[i][j] = dp[i + 1][j];
				}
				else if (s1[i] == s3[i + j] && s2[j] == s3[i + j])
				{
					dp[i][j] = dp[i + 1][j] || dp[i][j + 1];
				}
			}
		}
		return dp[0][0];
	}
};