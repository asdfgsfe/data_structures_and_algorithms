class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> dict;
		for (string& word : wordDict)
		{
			dict.emplace(std::move(word));
		}
		vector<bool> dp(s.size() + 1, false);
		dp.back() = true;
		for (int i = dp.size() - 2; i >= 0; --i)
		{
			for (int j = i; j < s.size(); ++j)
			{
				if (!dp[i] && dict.count(s.substr(i, j - i + 1)))
				{
					dp[i] = dp[j + 1];
				}
			}
		}
		return dp[0];
    }
};