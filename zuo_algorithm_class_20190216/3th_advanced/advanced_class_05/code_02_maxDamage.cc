#include <iostream>
#include <vector>

using std::vector;

//对于子序列的问题一般是选择要当前的数字与不要当前的数字去尝试
//对于子数组的问题一般是以什么开头或者以什么结尾怎么样
//本题可以枚举出所有的子序列 选出子序列的累加和等于aim 且子序列的累乘和最大 选子序列的过程就是要当前与不要当前值

int SelectProcess(const vector<int>& cards, int i, int threshold)
{
  if (threshold < 0)
  {
    return -1;
  }
  if (i == cards.size())
  {
    return threshold == 0 ? 1 : -1;
  }
  int notIncludeCur = SelectProcess(cards, i + 1, threshold);
  int includeCur = SelectProcess(cards, i + 1, threshold - cards[i]) * cards[i];
  return std::max(notIncludeCur, includeCur);
}

int MaxDamage(const vector<int>& cards, int threshold)
{
  if (cards.empty() || threshold < 1)
  {
    return -1;
  }
  return SelectProcess(cards, 0, threshold);
}

int MaxDamageDp(const vector<int>& cards, int threshold)
{
  if (cards.empty() || threshold < 1)
  {
    return -1;
  }
  vector<vector<int>> dp(cards.size() + 1, vector<int>(threshold + 1, -1));
  dp[dp.size() - 1][0] = 1;
  for (int i = dp.size() - 2; i >= 0; --i)
  {
    for (int j = dp[0].size() - 1; j >= 0; --j)
    {
      if (j - cards[i] >= 0)
      {
        dp[i][j] = std::max(dp[i + 1][j], dp[i + 1][j - cards[i]] * cards[i]);
      }
    }
  }
  return dp[0][threshold];
}

int main(void)
{
  vector<int> cards = {1, 2, 3, 4, 5};
  int threshold = 10;
  std::cout << MaxDamage(cards, threshold) << std::endl;
  std::cout << MaxDamageDp(cards, threshold) << std::endl;
  
  return 0;
}
