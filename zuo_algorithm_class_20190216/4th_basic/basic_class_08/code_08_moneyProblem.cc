#include <iostream>
#include <vector>

using std::vector;

int ChangeProcess(const vector<int>& money, int i, int aim)
{
  if (aim == 0)
  {
    return 1;
  }
  if (i >= money.size())
  {
    return 0;
  }
  int ways = 0;
  for (int k = 0; k * money[i] <= aim; ++k)
  {
    ways += ChangeProcess(money, i + 1, aim - money[i] * k);
  }
  return ways;
}

int ChangeMoneyWays(const vector<int>& money, int aim)
{
  if (money.empty() || aim < 0)
  {
    return 0;
  }
  return ChangeProcess(money, 0, aim);
}

int ChangeMoneyWaysDp(const vector<int>& money, int aim)
{
  if (money.empty() ||aim < 0)
  {
    return 0;
  }
  vector<vector<int>> dp(money.size() + 1, vector<int>(aim + 1, 0));
  for (int i = 0; i < dp.size(); ++i)
  {
    dp[i][0] = 1;
  }
  for (int i = dp.size() - 2; i >= 0; --i)
  {
    for (int j = 1; j < dp[0].size(); ++j)
    {
      for (int k = 0; k * money[i] <= j; ++k)
      {
        dp[i][j] += dp[i + 1][j - money[i] * k];
      }
    }
  }
  return dp[0][aim];
}

int main(void)
{
  vector<int> money = {5, 10, 25, 1};
  int aim = 0;
  std::cout << ChangeMoneyWays(money, 0) << std::endl;
  std::cout << ChangeMoneyWays(money, 15) << std::endl;
  std::cout << ChangeMoneyWaysDp(money, 0) << std::endl;
  std::cout << ChangeMoneyWaysDp(money, 15) << std::endl;
  
  money = {3, 5};
  std::cout << ChangeMoneyWays(money, 2) << std::endl;

  return 0;
}
