#include <iostream>
#include <vector>
#include <algorithm>

using std::vector;

void PrintDp(const vector<int>& dp)
{
  for (int i = 0; i < dp.size(); ++i)
  {
    int val = dp[i];
    if (dp[i] == 0x7fffffff)
    {
      val = -1;
    }
    std::cout << val << " ";
  }
  std::cout << std::endl;
}

int MaxLeftMost(const vector<int>& v, int dragons)
{
  int l = 0;
  int r = v.size() - 1;
  int id = -1;
  while (l <= r)
  {
    int mid = (l + r) / 2;
    if (v[mid] < dragons)
    {
      l = mid + 1;
    }
    else
    {
      id = mid;
      r = mid - 1;
    }
  }
  return id == -1 ? 0x7fffffff : v[id];
}

int MinGold(const vector<int>& dragons, vector<int>& knights)
{
  if (dragons.empty() || knights.empty())
  {
    return 0;
  }

  std::sort(knights.begin(), knights.end());
  int minGold = 0;
  for (int i = 0; i < dragons.size(); ++i)
  {
    int cost = MaxLeftMost(knights, dragons[i]);
    if (cost == 0x7fffffff)
    {
      return 0x7fffffff;
    }
    minGold += cost;
  }
  return minGold;
}

int MinGold2(const vector<int>& dragons, const vector<int>& knights)
{
  if (dragons.empty() || knights.empty())
  {
    return 0;
  }

  int len = 0;
  for (int i = 0; i < knights.size(); ++i)
  {
    len += knights[i];
  }
  vector<int> dp(len+1, 0x7fffffff);
  dp[0] = 0;
  dp[knights[0]] = knights[0];
  //PrintDp(dp);
  for (int i = 1; i < knights.size(); ++i)
  {
    for (int j = 1; j <= len; ++j)
    {
      if (j - knights[i] >= 0 && dp[j-knights[i]] < 0x7fffffff)
      {
        dp[j] = std::min(dp[j], dp[j-knights[i]] + knights[i]);
      }
    }
    //PrintDp(dp);
  }
  //copy 
  for (int i = dp.size() - 2; i >= 0; --i)
  {
    dp[i] = std::min(dp[i], dp[i+1]);
  }
  //PrintDp(dp);
  
  int res = 0;
  for (int i = 0; i < dragons.size(); ++i)
  {
    int cost = MaxLeftMost(dp, dragons[i]);
    if (cost == 0x7fffffff)
    {
      return 0x7fffffff;
    }
    res += cost;
  }
  return res;
}

int main(void)
{
  vector<int> knights1 = {2, 10, 5};
  vector<int> dragons1 = { 3, 8, 6 };
  std::cout << MinGold(dragons1, knights1) << std::endl;

  vector<int> knights2 = {2, 10, 5};
  vector<int> dragons2 = { 3, 8, 6 };
  std::cout << MinGold2(dragons2, knights2) << std::endl;

  return 0;
}
