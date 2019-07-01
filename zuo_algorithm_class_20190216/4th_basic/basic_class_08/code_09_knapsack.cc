#include <iostream>
#include <vector>

using std::vector;

int PackageProcess(const vector<int>& w, const vector<int>& v, int i, int bag)
{
  if (bag <= 0 || i == w.size())
  {
    return 0;
  }
  if (bag < w[i]) //如果当前的重量大于已经大于现有的背包 就忽略当前
  {
    return PackageProcess(w, v, i + 1, bag);
  }
  return std::max(PackageProcess(w, v, i + 1, bag), PackageProcess(w, v, i + 1, bag - w[i]) + v[i]);
}

int Knapsack(const vector<int>& w, const vector<int>& v, int bag)
{
  if (w.empty() || v.empty() || w.size() != v.size() || bag < 1)
  {
    return 0;
  }
  return PackageProcess(w, v, 0, bag);
}

//有bug
int process1(const vector<int>& weights, const vector<int>& values, int i, int alreadyweight, int bag) 
{
  if (alreadyweight > bag) {
    return 0;
    }
  if (i == weights.size()) {
    return 0;
  }
  return std::max(process1(weights, values, i + 1, alreadyweight, bag), 
      values[i] + process1(weights, values, i + 1, alreadyweight + weights[i], bag));
}

int maxValue1(const vector<int>& c, const vector<int>& p, int bag) 
{
  return process1(c, p, 0, 0, bag);
}

int MaxValueDp(const vector<int>& w, const vector<int>& v, int bag)
{
  if (w.empty() || v.empty() || bag < 1)
  {
    return 0;
  }
  vector<vector<int>> dp(w.size() + 1, vector<int>(bag + 1, 0));
  for (int i = dp.size() - 2; i >= 0; --i)
  {
    for (int j = 1; j < dp[0].size(); ++j)
    {
      dp[i][j] = dp[i + 1][j];
      if (j - w[i] >= 0)
      {
        dp[i][j] = std::max(dp[i][j], dp[i + 1][j - w[i]] + v[i]);
      }
    }
  }
  return dp[0][bag];
}

int MaxValueDp2(const vector<int>& w, const vector<int>& v, int bag)
{
  if (w.empty() || v.empty() || bag < 1)
  {
    return 0;
  }
  vector<vector<int>> dp(w.size() + 1, vector<int>(bag + 1, 0));
  for (int i = dp.size() - 2; i >= 0; --i)
  {
    for (int j = dp[0].size() - 1; j >= 0; --j)
    {
      dp[i][j] = dp[i + 1][j];
      if (j + w[i] <= bag)
      {
        dp[i][j] = std::max(dp[i][j], dp[i + 1][j + w[i]] + v[i]);
      }
    }
  }
  return dp[0][0];
}

int main(void)
{
  vector<int> w = { 3, 2, 4, 7 };
  vector<int> v= { 5, 6, 3, 19 };
  int bag = 11;
  std::cout << Knapsack(w, v, bag) << std::endl;
  std::cout << maxValue1(w, v, bag) << std::endl;
  std::cout << MaxValueDp(w, v, bag) << std::endl;
  std::cout << MaxValueDp2(w, v, bag) << std::endl;

  return 0;
}
