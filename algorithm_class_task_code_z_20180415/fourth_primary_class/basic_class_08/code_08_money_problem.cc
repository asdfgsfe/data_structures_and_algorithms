#include <iostream>
#include <vector>

using std::vector;

bool Process(const vector<int>& v, int i, int sum, int aim)
{
  if (i == v.size())
  {
    return sum == aim;
  }
  return Process(v, i + 1, sum, aim) || Process(v, i + 1, sum + v[i], aim);
}

bool IsSum(const vector<int>& v, int aim)
{
  if (v.empty())
  {
    return false;
  }
  return Process(v, 0, 0, aim);
}

//补上数组中有负数的情况
/*bool IsSum1(const vector<int>& v, int aim)
{
  if (v.empty())
  {
    return false;
  }
  int l = 0;
  int r = 0;
  for (auto i : v)
  {
    l = i < 0 ? l + i : l;
    r = i > 0 ? r + i : r;
  }
  int cols = r - l;
  int rows = v.size()-1;
  vector<vector<bool>> dp(v.size(), vector<bool>(cols+1));
  vector<int> sums(cols+1);
  int p = 0;
  while (l <= r)
  {
    sums[p++] = l++;
  }
  for (int i = 0; i <= cols; ++i)
  {
    dp[rows][i] = sums[i] == aim ? true : false;
  }
  for (int i = rows - 1; i >= 0; --i)
  {
    for (int j = 0; j < cols; ++j)
    {
      dp[i][j] = (dp[i+1][j] || dp[i+1][j+[j]]);
    }
  }
  return dp[0][0];
}*/

bool IsSum2(const vector<int>& v, int aim)
{
  if (v.empty())
  {
    return false;
  }
  vector<vector<bool>> dp(v.size() + 1, vector<bool>(aim + 1));
  for (int i = 0; i <= v.size(); ++i)
  {
    dp[i][aim] = true;
  }
  for (int i = v.size() - 1; i >= 0; --i)
  {
    for (int j = aim - 1; j >= 0; --j)
    {
      dp[i][j] = dp[i+1][j];
      if (j + v[i] <= aim)
      {
        dp[i][j] = (dp[i+1][j] || dp[i+1][j+v[i]]);
      }
    }
  }
  return dp[0][0];
}

int main(void)
{
  vector<int> v = {1, 4, 8};
  int aim = 12;
  std::cout << IsSum(v, aim) << std::endl;
  std::cout << IsSum2(v, aim) << std::endl;

  return 0;
}
