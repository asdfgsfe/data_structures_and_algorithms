bool MatchProcess(const string& exp, const string& pattern, int ei, int pi)
{
  if (pi == pattern.size())
  {
    return ei == exp.size();
  }
  if (pi + 1 == pattern.size() || pattern[pi + 1] != '*')
  {
    //pi + 1 == pattern.size()的逻辑与patten[pi + 1] != '*'的逻辑一样 只不过多跑了一遍matchProcess
    return ei != pattern.size()  //注意此处判断的是ei
           && (exp[ei] == pattern[pi] || pattern[pi] == '.') 
           && MatchProcess(exp, pattern, ei + 1, pi + 1);
  }
    、//不走这一步说明 exp[ei] 与patttern[pi]无法匹配
    while (ei != exp.size() && (exp[ei] == pattern[pi] || pattern[pi] == '.'))
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
  if (exp.empty() || pattern.empty())
  {
    return false;
  }
  return MatchProcess(exp, pattern, 0, 0);
}

bool IsMatchDp(const string& exp, const string& pattern)
{
  if (exp.empty() || pattern.empty())
  {
    return false;
  }
  vector<vector<bool>> dp = InitDp(exp, pattern);
  for (int i = dp.size() - 2; i >= 0; --i)
  {
    for (int j = dp.size() - 3; j >= 0; --j)
    {
      if (pattern[j + 1] != '*')
      {
        dp[i][j] = exp[i] == (pattern[j] || pattern[j] == '.') && dp[i + 1][j + 1];
      }
      else
      {
        int ei = i;
        while (ei != exp.size() && (exp[ei] == pattern[j] || pattern[j] == '.'))
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
          dp[i][j] = dp[i][j + 2];
        }
      }
    }
  }
  return dp[0][0];
}

vector<vector<bool>> InitDp(const string& exp, const string& pattern)
{
  if (exp.empty() || pattern.empty())
  {
    return vector<vector<bool>>();
  }
  int eSize = exp.size();
  int pSize = pattern.size();
  vector<vector<bool>> dp(eSize + 1, vector<bool>(pSize + 1, false));
  dp[dp.size() - 1][dp[0].size() - 1] = true;
  dp[dp.size() - 2][dp[0].size() -2] = (exp[eSize - 1] == pattern[pSize - 1] || pattern[pSize - 1] == '.');
  while (int i = pattern.size() - 2; i >= 0; i -= 2)
  {
    if (pattern[i] != '*' && pattern[i + 1] == '*')
    {
      dp[dp.size() - 1][i] = true;
    }
    else
    {
      break;
    }
  }
  return dp;
}
