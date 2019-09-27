#include <iostream>
#include <string>
#include <vector>

using std::string;
using std::vector;

int MinEditCost(const string& exp, const string& pattern, int ic, int dc, int rc)
{
  if (exp.empty())
  {
    return pattern.size() * dc;
  }
  if (pattern.empty())
  {
    return exp.size() * ic;
  }
  vector<vector<int>> dp(exp.size() + 1, vector<int>(pattern.size() + 1));
  dp[exp.size()][pattern.size()] = 0;
  for (int i = 0; i < exp.size(); ++i)
  {
    dp[i][pattern.size()] = (exp.size() - i) * ic;
  }
  for (int i = 0; i < pattern.size(); ++i)
  {
    dp[exp.size()][i] = (pattern.size() - i) * dc;
  }
  for (int i = dp.size() - 2; i >= 0; --i)
  {
    for (int j = dp[0].size() - 2; j >= 0; --j)
    {
      if (exp[i] == pattern[j])
      {
        dp[i][j] = dp[i + 1][j + 1];
      }
      else
      {
        dp[i][j] = dp[i +1][j + 1] + rc;
      }
      dp[i][j] = std::min(dp[i][j], dp[i][j + 1] + ic);
      dp[i][j] = std::min(dp[i][j], dp[i + 1][j] + dc);
    }
  }
  return dp[0][0];
}

//æÿ’Û—πÀı
int MinEditCost2(const string& exp, const string& pattern, int ic, int dc, int rc)
{
  if (exp.empty())
  {
    return pattern.size() * dc;
  }
  if (pattern.empty())
  {
    return exp.size() * ic;
  }
  if (exp.size() < pattern.size())
  {
    std::swap(exp, pattern);
    std::swap(ic, dc);
  }
  vector<int> dp(pattern.size() + 1);
  dp[0] = 0;
  for (int i = 1; i < pattern.size(); ++i)
  {
    dp[i] = i * ic;
  }
  for (int i = 1; i <= exp.size(); ++i)
  {
    int pre = dp[0];
    dp[0] = dc * i;
    for (int j = 1; j <= pattern.size(); ++j)
    {
      int tmp = dp[j];
      if (exp[i - 1] == pattern[j - 1])
      {
        dp[j] = pre;
      }
      else
      {
        dp[j] = pre + rc;
      }
      dp[j] = std::min(dp[j], dp[j - 1] + ic);
      dp[j] = std::min(dp[j], tmp + dc);
      pre = tmp;
    }
  }
  return dp[dp.size() - 1];
}

int main(void)
{
  string exp = "abc";
  string pattern = "adc";
  std::cout << MinEditCost(exp, pattern, 5, 3, 100) << std::endl;

  return 0;
}

