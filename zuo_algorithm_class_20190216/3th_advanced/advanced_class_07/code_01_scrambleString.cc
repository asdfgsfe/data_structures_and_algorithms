bool ScrambleProcess1(const string& s1, const string& s2, int l1, int r1, int l2, int r2)
{
  if (l1 == r1)
  {
    return s1[l1] == s2[l2];
  }
  for (int s = 0; s < (r1 - l1); ++s)
  {
    if ((ScrambleProcess1(s1, s2, l1, l1 + i, l2, l2 + i) && ScrambleString1(s1, s2, l1 + i + 1, r1, l2 + i + 1, r2))
        || ScrambleProcess1(s1, s2, l1, l1 + i, r2 - i, r2) && ScrambleProcess(s1, s2, l1 + i + 1, r1, l2, r2- i - 1))
    {
      return true;
    }
  }
  return false;
}

bool ScrambleProcess2(const string& s1, const strign& s2, int l1, int l2, int size)
{
  if (size == 1)
  {
    return s1[l1] == s2[l2];
  }
  for (int s = 1; s < size; ++s)
  {
    if ((ScrambleProcess2(s1, s2, l1, l2, s) && ScrambleProcess2(s1, s2, l1 + s, l2 + s, size - s))
        || ScrambleProcess2(s1, s2, l1, l2 + size - s, s) && ScrambleProcess2(s1, s2, l1 + s, l2, size - s))
    {
      return true;
    }
  }
  return false;
}

bool IsScrambleString1(const strign& s1, const string& s2)
{
  if (s1.size() < 2 || s2.size() < 2 || s1.size() != s2.size())
  {
    return false;
  }
  if (s1 == s2)
  {
    return true;
  }
  //return ScrambleProcess1(s1, s2, 0, s1.size() - 1, 0, s2.size() - 1);
  return ScrambleProcess2(s1, s2, 0, 0, s1.size());
}

bool IsScrambleStringDp(const string& s1, const string& s2)
{
  if (s1.size() < 2 || s2.size() < 2 || s1.size() != s2.size())
  {
    return false;
  }
  if (s1 == s2)
  {
    return true;
  }
  //dp[s1][s2][size]
  int n = s1.size();
  vector<vector<vector<bool>>> dp(n + 1, vector<vector<bool>>(n, vector<bool>(n, false)));
  for (int l1 = 0; l1 < n; ++l1)
  {
    for (int l2 = 0; l2 < n; ++l2)
    {
      dp[1][l1][l2] = s1[l1] == s2[l2];
    }
  }
  //几维的dp for就是几层 几层完了才是递归里面的逻辑
  for (int size = 2; size <= n; ++size)
  {
    for (int l1 = 0; l1 < n - size; ++l1)
    {
      for (int l2 = 0; l2 < n - size; ++l2)
      {
        for (int p = 1; p < size; ++p)
        {
          if ((dp[p][l1][l2] && dp[size - p][l1 + p][l2 + p])
              || (dp[p][l1][l2 + size - p] && dp[size - p][l1 + size - p][l2]))
              {
                dp[[size]l1][l2] = true;
                break;
              }
        }
      }
    }
  }
  //递归的入口决定了dp返回位置 也决定了dp大小的边界值 
  //入口填多少要返回多少 所以dp的值要比这个至少大1
  return dp[n][0][0];
}
