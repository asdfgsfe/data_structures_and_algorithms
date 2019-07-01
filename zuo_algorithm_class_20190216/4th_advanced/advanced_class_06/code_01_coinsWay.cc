#include <iostream>
#include <vector>

using std::vector;

int WayProcess(const vector<int>& coins, int i, int aim)
{
  if (aim == 0)
  {
    return 1;
  }
  if (i == coins.size())
  {
    return 0;
  }
  int way = 0;
  for (int k = 0; aim - k * coins[i] >= 0; ++k)
  {
    way += WayProcess(coins, i + 1, aim - k * coins[i]);
  }
  return way;
}

int ConisWay(const vector<int>& coins, int aim)
{
  if (coins.empty())
  {
    return 0;
  }
  return WayProcess(coins, 0, aim);
}

int CoinsWayDp(const vector<int>& coins, int aim)
{
  if (coins.empty())
  {
    return 0;
  }
  vector<vector<int>> dp(coins.size() + 1, vector<int>(aim + 1, 0));
  for (int i = 0; i < dp.size(); ++i)
  {
    dp[i][0] = 1;
  }
  for (int i = dp.size() - 2; i >= 0; --i)
  {
    for (int j = 1; j <= aim; ++j)
    {
      for (int k = 0; j - k * coins[i] >= 0; ++k)
      {
        dp[i][j] += dp[i + 1][j - k* coins[i]];
      }
    }
  }
  return dp[0][aim];
}

int main(void)
{
  vector<int> coins = {5, 10, 25, 1};
  std::cout << ConisWay(coins, 0) << std::endl;
  std::cout << ConisWay(coins, 15) << std::endl;
  std::cout << CoinsWayDp(coins, 0) << std::endl;
  std::cout << CoinsWayDp(coins, 15) << std::endl;

  coins = {3, 5};
  std::cout << ConisWay(coins, 2) << std::endl;
  std::cout << CoinsWayDp(coins, 2) << std::endl;

  return 0;
}
