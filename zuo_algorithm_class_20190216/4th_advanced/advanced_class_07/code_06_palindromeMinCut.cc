int PalindromeMinCut(const string& str)
{
  if (str.empty())
  {
    return 0;
  }
  vector<int> dp(str.size(), 0x7fffffff);
  dp[dp.size() - 1] = -1;
  vector<vector<bool>> isPalindrome(str.size(), vector<bool>(str.size(), false));
  for (int i = dp.size() - 2; i >= 0; --i)
  {
    for (int c = i; c < str.size(); ++c)
    {
      if (str[i] == str[c] && (c - i < 2 || dp[i + 1][c - 1]))
      {
        isPalindrome[i][c] = true;
        dp[i] = std::min(dp[i], dp[c + 1] + 1);
      }
    }
  }
  return dp[0];
}
