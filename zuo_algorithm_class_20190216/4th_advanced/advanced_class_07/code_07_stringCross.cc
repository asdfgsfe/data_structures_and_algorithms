bool CrossProcess1(const string& s1, const string& s2, const string& aim, int i, int j, int k)
{
  if (k == aim.size())
  {
    return true;
  }
  if (i == s1.size())
  {
    return IsEqual(s2, j, aim, k);
  }
  if (j == s2.size())
  {
    return IsEqual(s1, i, aim, k);
  }
  if (s1[i] == aim[k] && s2[j] != aim[k])
  {
    return CrossProcess(s1, s2, aim, i + 1, j, k + 1);
  }
  if (s1[i] != aim[k] && s2[j] == aim[k])
  {
    return CrossProcess(s1, s2, aim, i, j + 1, k + 1);
  }
  if (s1[i] == aim[k] && s2[k] == aim[k])
  {
    return CrossProcess(s1, s2, aim, i + 1, j, k + 1) || CrossProcess(s1, s2, aim, i, j + 1, k + 1);
  }
  return false;
}

//注意这个边界条件的判断 很诡异
bool CrossProcess2(const string& s1, const string& s2, const string& aim, int i, int j)
{
  if (i == s1.size() && j == s2.size())
  {
    return true;
  }
  int k = i + j;
  assert(k < aim.size());
  if (i == s1.size())
  {
    //return IsEqual(s2, j, aim, k); //这个地方可以继续用递归去判断 fix
	return aim[k] == s2[j] && CrossProcess2(s1, s2, aim, i, j + 1);
  }
  if (j == s2.size())
  {
    //return IsEqual(s1, i, aim, k);
	return aim[k] == s2[i] && CrossProcess2(s1, s2, aim, i + 1, j);
  }
  //k == i + j 因为k的位置等于s1已经匹配完的位置和s2已经匹配完的位置和
  if (s1[i] == aim[k] && s2[j] != aim[k])
  {
    return CrossProcess2(s1, s2, aim, i + 1, j);
  }
  if (s1[i] != aim[k] && s2[j] == aim[k])
  {
    return CrossProcess2(s1, s2, aim, i, j + 1);
  }
  if (s1[i] == aim[k] && s2[k] == aim[k]) //有必要 因为不知道二者那个会返回true
  {
    return CrossProcess2(s1, s2, aim, i + 1, j) || CrossProcess2(s1, s2, aim, i, j + 1);
  }
  return false;
}

bool IsCross(const string& s1, const string& s2, const string& aim)
{
  //这种方法很好 判断边界的方法
  if (s1.empty())
  {
    return s2 == aim;
  }
  if (s2.empty())
  {
    return s1 == aim;
  }
  if (s1.size() + s2.size() != aim.size())
  {
    return false;
  }
  return CrossProcess2(s1, s2, aim, 0, 0);
}

bool IsCrossDp(const string& s1, const string& s2, const string& aim)
{
  if (s1.empty())
  {
    return s2 == aim;
  }
  if (s2.empty())
  {
    return s2 == aim;
  }
  if (s1.size() + s2.size() != aim)
  {
    return false;
  }
  vector<vector<bool>> dp(s1.size() + 1, vector<bool>(s2.size() + 1, false));
  dp[dp.size() - 1][dp[0].size() - 1] = true;
  for (int i = 0; i < s1.size() && s1[i] == aim[i + s2.size()]; ++i) //注意这里从先填第0行0列 和先填最后一行一列不一样
  {
    dp[i][dp[0].size() - 1] = true;
  }
  for (int i = 0; i < s2.size() && s2[i] == aim[i + s1.size()]; ++i)
  {
    dp[dp.size() - 1][i] = true;
  }
  for (int i = dp.size() - 2; i >= 0; --i)
  {
    for (int j = dp[0].size() - 2; j >= 0; --j)
    {
      if (s1[i] == aim[i + j] && s2[j] != aim[i + j])
      {
        dp[i][j] = dp[i + 1][j];
      }
      else if (s1[i] != aim[i + j] && s2[j] == aim[i + j])
      {
        dp[i][j] = dp[i][j + 1];
      }
      else if (s1[i] == aim[i + j] && s2[i] == aim[i + j])
      {
        dp[i][j] = dp[i][j + 1] || dp[i + 1][j];
      }
    }
  }
  return dp[0][0];
}

bool IsCrossDp2(const string& s1, const string& s2, const string& aim)
{
  if (s1.empty())
  {
    return s2 == aim;
  }
  if (s2.empty())
  {
    return s2 == aim;
  }
  if (s1.size() + s2.size() != aim)
  {
    return false;
  }
  vector<vector<bool>> dp(s1.size() + 1, vector<bool>(s2.size() + 1, false));
  dp[dp.size() - 1][dp[0].size() - 1] = true;
  for (int i = 0; i < s1.size() && s1[i] == aim[i]; ++i)
  {
    dp[i][dp[0].size() - 1] = true;
  }
  for (int i = 0; i < s2.size() && s2[i] == aim[i]; ++i)
  {
    dp[dp.size() - 1][i] = true;
  }
  for (int i = dp.size() - 2; i >= 0; --i)
  {
    for (int j = dp[0].size() - 2; j >= 0; --j)
    {
      if ((s1[i] == aim[i + j] && dp[i + 1][j]) || s2[j] == aim[i + j] && dp[i][j + 1])
      {
        dp[i][j] = true;
      }
	  else
	  {
		dp[i][j] = false;
	  }
    }
  }
  return dp[0][0];
}

bool IsCrossDp3(const string& s1, const string& s2, const string& aim)
{
  if (s1.empty())
  {
    return s2 == aim;
  }
  if (s2.empty())
  {
    return s2 == aim;
  }
  if (s1.size() + s2.size() != aim)
  {
    return false;
  }
  
  //矩阵压缩技术核心代码
  if (s1.size() < s2.size())
  {
    std::swap(s1, s2);
  }
  vector<bool> dp(s2.size() + 1, false);
  dp[dp.size() - 1] = true;
  for (int i = 0; i < s2.size() && s2[i] == aim[i]; ++i)
  {
    dp[i] = true;
  }
  for (int i = dp.size() - 2; i >= 0; --i)
  {
    dp[dp.size() - 1] = dp[dp.size() - 1] & s1[i] == aim[i];
    for (int j = dp[0].size() - 2; j >= 0; --j)
    {
      if ((s1[i] == aim[i + j] && dp[j]) || s2[j] == aim[i + j] && dp[j + 1])
      {
        dp[j] = true;
      }
      else
      {
        dp[j] = false;
      }
    }
  }
  return dp[dp.size() - 1];
}

