#include <iostream>
#include <vector>

using std::vector;

int SelectProcess(const vector<int>& w, const vector<int>& p, int index, int bag)
{
  if (bag <= 0)
  {
    return 0x80000000;
  }
  if (index == w.size())
  {
    return 0;
  }
  return std::max(SelectProcess(w, p, index + 1, bag), p[index] + SelectProcess(w, p, index + 1, bag - w[index]));
}

int MaxProfit(const vector<int>& w, const vector<int>& p, int bag)
{
  if (w.empty() || p.empty() || w.size() != p.size() || bag < 1)
  {
    return 0;
  }
  return SelectProcess(w, p, 0, bag);
}

int MaxProfit2(const vector<int>& w, const vector<int>& p, int bag)
{
  if (w.empty() || p.empty() || w.size() != p.size() || bag < 1)
  {
    return 0;
  }
  vector<vector<int>> dp(w.size() + 1, vector<int>(bag + 1, 0));
  for (int i = dp.size() - 2; i >= 0; --i)
  {
    for (int j = 1; j < dp[0].size(); ++j)
    {
      if (j - w[i] >= 0)
      {
        dp[i][j] = std::max(dp[i + 1][j], p[i] + dp[i + 1][j - w[i]]);
      }
    }
  }
  return dp[0][bag];
}

int main(void)
{
  vector<int> w = {3, 2, 4, 7};
  vector<int> p = {5, 6, 3, 19};
  int bag = 11;
  std::cout << MaxProfit(w, p, bag) << std::endl;
  std::cout << MaxProfit2(w, p, bag) << std::endl;

  return 0;
}
