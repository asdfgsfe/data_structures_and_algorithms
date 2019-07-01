bool MatchProcess2(const string& exp, const string& pattern, int ei, int pi)
{
  if (pi == pattern.size())
  {
    return ei == exp.size();
  }
  if ((pi + 1 == pattern.size() || pattern[pi + 1] != '*'))
  {
    return s1 != exp.size() 
           && (exp[ei] == pattern[pi] || pattern[pi] == '.')
           && MatchProcess2(exp, pattern, ei + 1, pi + 1);
  }
  while (ei != exp.size() && (exp[ei] == pattern[pi] || pattern[pi] == '.'))
  {
    if (MatchProcess2(exp, pattern, ei, pi + 2))
    {
      return true;
    }
    ++si;
  }
  return MatchProcess2(exp, pattern, ei, pi + 2);
}

bool RegualExpressionMatching2(const string& exp, const string& pattern)
{
  id (exp.empty() && pattern.empty())
  {
    return true;
  }
  if (exp.empty() || pattern)
  {
    return false;
  }
  return MatchProcess2(exp, pattern, 0, 0);
}

bool RegualExpressionMatching1(const char* pExp, const char* pPattern)
{
  if (pExp == nullptr || pPattern == nullptr)
  {
    return false;
  }
  return MatchProcess1(pExp, pPattern);
}

bool MatchProcess1(const char* pExp, const char* pPattern)
{
  if (*pExp == '\0' && *pPattern == '\0')
  {
    return true;
  }
  if (*pExp != '\0' && *pPattern == '0')
  {
    return false;
  }
  if (*pPattern + 1 == '*')
  {
    if (*pExp == *pPattern || (*pPattern == '.' && *pExp != '0'))
    {
      return MatchProcess1(pExp + 1, pPattern + 2) 
             || MatchProcess1(pExp, pPattern + 2) 
             || MatchProcess1(pExp + 1, pPattern);
    }
    return MatchProcess1(pExp, pPattern + 2);
  }
  if (*pExp == *pPattern || (*pPatterm == '.' && *pExp != '0'))
  {
    return MatchProcess1(pExp + 1, pPattern + 1);
  }
}

bool RegualExpressionMatchingDp(const string& exp, const string& pattern)
{
  if (exp.empty() && pattern.empty())
  {
    return true;
  }
  if (exp.empty() || pattern.empty())
  {
    return false;
  }
  vector<vector<bool>> dp = InitDp(exp, pattern);
  for (int i = exp.size() - 1; i >= 0; --i)
  {
    for (int j = pattern.size() - 2; j >= 0; --j)
    {
      if (pattern[j + 1] != '*')
      {
        dp[i][j] = (exp[i] == pattern[j] || pattern[j] == '.') && dp[i + 1][j + 1];
      }
      else
      {
        int ei = i;
        while (ei != exp.size() && exp[i] == pattern[j] || pattern[j] == '.')
        {
          if (dp[i][j + 2])
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
  vector<vector<bool>> dp(exp.size() + 1, vector<bool>(pattern.size() + 1, false));
  dp[exp.size()][pattern.size()] = true;
  if (exp[exp.size() - 1] == pattern[pattern.size() - 1] || pattern[pattern.size() - 1] == '.')
  {
    dp[exp.size() - 1][pattern.size() - 1] = true;
  }
  for (int i = pattern.size() - 2; i >= 0; i -= 2)
  {
    if (pattern[i] != '*' && pattern[i + 1] == '*')
    {
      dp[exp.size()][i] = true;
      continue;
    }
    break;
  }
  return dp;
}
