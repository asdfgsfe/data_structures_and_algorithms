bool MatchProcess(const string& exp, const string& pattern, int ei, int pi)
{
  if (pi == pattern.size())
  {
    return ei == exp.size();
  }
  if (pi != pattern.size() - 1 || pattern[pi + 1] != '*')
  {
    return ei != exp.size() 
           && (exp[ei] == pattern[pi] || pattern[pi] == '.')
           && MatchProcess(exp, pattern, ei + 1, pi + 1);
  }
  while (ei < exp.size() && (exp[ei] == pattern[pi] || pattern[pi] == '.'))
  {
    if (MatchProcess(exp, pattern, ei, pi + 2))
    {
      return true;
    }
    ++ei;
  }
  return MatchProcess(exp, pattern, ei, pi + 2);
}

bool IsMatch(const string& exp, const string& pattern)
{
  if (exp.empty() || pattern.empty() || IsVaild(pattern))
  {
    return false;
  }
  return MatchProcess(exp, pattern, 0, 0);
}

bool IsMatchDp(const string& exp, const string& pattern)
{
  if (exp.empty() || pattern.empty() || !IsVaild(pattern))
  {
    return false;
  }
  vector<vector<bool>> dp(exp.size() + 1, vector<bool>(pattern.size() + 1, false));
  dp[dp.size() - 1][dp[0].size() - 1] = true;
  if (exp[exp.size() - 1] == pattern[pattern.size() - 1] || pattern[pattern.size() - 1] == '.')
  {
    dp[dp.size() - 2][dp[0].size() - 2] = true;
  }
  for (int j = dp.size() - 2; j >= 0; j -= 2)
  {
    if (pattern[j] != '*' && pattern[j + 1] == '*')
    {
      dp[dp.size() - 1][j] = true;
    }
  }
  for (int i = dp.size() - 2; i >= 0; --i)
  {
    for (int j = dp[0].size() - 3; j >= 0; --j)
    {
      if (pattern[j + 1] != '*')
      {
        dp[i][j] = (exp[i] == pattern[j] || pattern[j] == '.') && dp[i + 1][j + 1];
      }
      else
      {
        int ei = i;
        while (ei < exp.size() && exp[ei] == pattern[j] || pattern[j] == '.')
        {
          if (dp[ei][j + 2])
          {
            dp[i][j] = true;
            break;
          }
          ++ei;
        }
        if (!dp[i][j])
        {
          dp[i][j] = dp[ei][j + 2];
        }
      }
    }
  }
  return dp[0][0];
}
