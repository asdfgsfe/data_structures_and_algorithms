#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>

using std::string;
using std::vector;
using std::unordered_map;

int Process1(const vector<int>& conis, int index, int aim)
{
  if (index == conis.size())
  {
    return aim == 0 ? 1 : 0;
  }
  int res = 0;
  for (int i = 0; i * conis[index] <= aim; ++i)
  {
    res += Process1(conis, index + 1, aim - i * conis[index]);
  }
  return res;
}

int ConisWay1(const vector<int>& conis, int aim)
{
  if (conis.empty() || aim < 0)
  {
    return 0;
  }
  return Process1(conis, 0, aim);
}

int Process2(const vector<int>& conis, int index, int aim, unordered_map<string, int>& fromIdToEndConisWay)
{
  if (index == conis.size())
  {
    return aim == 0 ? 1 : 0;
  }
  int res = 0;
  for (int i = 0; i * conis[index] <= aim; ++i)
  {
    int nextAim = aim - i * conis[index];
    string key = std::to_string(index + 1) + "_" + std::to_string(nextAim);
    const auto it = fromIdToEndConisWay.find(key);
    if (it != fromIdToEndConisWay.end())
    {
      res += it->second;
    }
    else
    {
      res += Process2(conis, index + 1, nextAim, fromIdToEndConisWay);
    }
  }
  string key = std::to_string(index) + "_" + std::to_string(aim);
  fromIdToEndConisWay[key] = res;
  return res;
}

int ConisWay2(const vector<int>& coins, int aim)
{
  if (coins.empty() || aim < 0)
  {
    return 0;
  }
  unordered_map<string, int> fromIdToEndConisWay;
  return Process2(coins, 0, aim, fromIdToEndConisWay);
}

int ConisWay3(const vector<int>& coins, int aim)
{
  if (coins.empty() || aim < 0)
  {
    return 0;
  }
  vector<vector<int>> dp(coins.size(), vector<int>(aim + 1, 0));
  for (int i = 0; i < coins.size(); ++i)
  {
    dp[i][0] = 1;
  }
  for (int i = 1; i * coins[coins.size() - 1] <= aim; ++i)
  {
    dp[coins.size() - 1][i * coins[coins.size() - 1]] = 1;
  }
  for (int i = coins.size() - 2; i >= 0; --i)
  {
    for (int j = aim; j > 0; --j)
    {
      for (int k = 0; k * coins[i] <= j; ++k)
      {
        dp[i][j] += dp[i + 1][j - k * coins[i]];
      }
    }
  }
  return dp[0][aim];
}

int ConisWay4(const vector<int>& coins, int aim)
{
  if (coins.empty() || aim < 0)
  {
    return 0;
  }
  vector<vector<int>> dp(coins.size(), vector<int>(aim + 1, 0));
  for (int i = 0; i < coins.size(); ++i)
  {
    dp[i][0] = 1;
  }
  for (int i = 1; i * coins[0] <= aim; ++i)
  {
    dp[0][i * coins[0]] = 1;
  }
  for (int i = 1; i < coins.size(); ++i)
  {
    for (int j = 1; j <= aim; ++j)
    {
      dp[i][j] = dp[i - 1][j];
      dp[i][j] += j - coins[i] >= 0 ? dp[i][j - coins[i]] : 0;
    }
  }
  return dp[coins.size() - 1][aim];
}

int ConisWay5(const vector<int>& coins, int aim)
{
  if (coins.empty() || aim < 0)
  {
    return 0;
  }
  vector<int> dp(aim + 1, 0);
  for (int i = 0; i * coins[0] <= aim; ++i)
  {
    dp[i * coins[0]] = 1;
  }
  for (int i = 1; i < coins.size(); ++i)
  {
    for (int j = 1; j <= aim; ++j)
    {
      dp[j] += j - coins[i] >= 0 ? dp[j - coins[i]] : 0;
    }
  }
  return dp[aim];
}

int main(void)
{
  vector<int> conis = {10, 5, 1, 25};
  int aim = 2000;
  std::cout << "1:" << ConisWay1(conis, aim) << std::endl;
  std::cout << "2:" << ConisWay2(conis, aim) << std::endl;
  std::cout << "3:" << ConisWay3(conis, aim) << std::endl;
  std::cout << "4:" << ConisWay4(conis, aim) << std::endl;
  std::cout << "5:" << ConisWay5(conis, aim) << std::endl;
  
  return 0;
}
