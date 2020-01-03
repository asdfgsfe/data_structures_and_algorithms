//区别这道题与左神的题 两种匹配方式不一样
class Solution {
public:
    bool isMatch(string s, string p) {
        if (p.empty())
        {
            return s.empty();
        }
        vector<vector<bool>> dp(s.size() + 1, vector<bool>(p.size() + 1, false));
        dp.back().back() = true;
        for (int i = dp[0].size() - 2; i >= 0; --i)
        {
            if (p[i] != '*')
            {
                break;
            }
            dp[dp.size() - 1][i] = true;
        }
        for (int i = dp.size() - 2; i >= 0; --i)
        {
            for (int j = dp[0].size() - 2; j >= 0; --j)
            {
                if (s[i] == p[j] || p[j] == '?')
                {
                    dp[i][j] = dp[i + 1][j + 1];
                }
                else if (p[j] == '*')
                {
                    int si = i;
                    while (si < dp.size()) //注意这里是dp.size() 而不是s.size()
                    {
                        if (dp[i][j])
                        {
                            break;
                        }
						dp[i][j] = dp[si++][j + 1];
                    }
                }
            }
        }
        return dp[0][0];
    }
};