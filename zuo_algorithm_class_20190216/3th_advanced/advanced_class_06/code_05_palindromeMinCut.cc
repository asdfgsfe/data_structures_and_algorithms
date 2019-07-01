#include <iostream>
#include <string>
#include <vector>

using std::string;
using std::vector;

bool IsPalindrome(const string& str, int l, int r)
{
  while (l <= r)
  {
    if (str[l] != str[r])
    {
      return false;
    }
    ++l;
    --r;
  }
  return true;
}


bool IsPalindromeDp(const string& str, int l, int r)
{
  if (l == r)
  {
    return true;
  }
  if (r - l == 1)
  {
    return str[l] == str[r];
  }
  if (str[l] != str[r])
  {
    return false;
  }
  return IsPalindromeDp(str, l + 1, r - 1);
}

bool IsPalindromeDp2(const string& str, int l, int r)
{
  int len = r - l + 1;
  vector<vector<bool>> dp(len, vector<bool>(len));
  for (int i = 0; i <= len; ++i)
  {
    dp[i][i] = true;
    dp[i + 1][i] = str[i + l] == str[i + l + 1];
  }
  for (int i = len - 3; i >= 0; --i)
  {
    for (int j = i + 2; j < len; ++j)
    {
      dp[i][j] = dp[i + 1][j - 1];
    }
  }
  return dp[0][len - 1];
}
//对于递归函数返回结果+1的这种 一般取到i==str.size 而且返回-1
int CutProcess(const string& str, int i)
{
  if (i == str.size())
  {
    return -1;
  }
  int min = 0x7fffffff;
  for (int s = i; s < str.size(); ++s)
  {
    if (IsPalindrome(str, i, s))
    {
      min = std::min(min, CutProcess(str, s + 1) + 1);
    }
  }
  return min;
}

int PalindromeMinCut(const string& str)
{
  if (str.size() < 2)
  {
    return 0;
  }
  return CutProcess(str, 0);
}

int PalindromeMinCutDp(const string& str)
{
  if (str.size() < 2)
  {
    return 0;
  }
  vector<int> dp(str.size() + 1, 0x7fffffff);
  dp[dp.size() - 1] = -1;
  for (int i = dp.size() - 2; i >= 0; --i)
  {
    for (int s = i; s < str.size(); ++s)
    {
      if (IsPalindromeDp(str, i, s))
      {
        dp[i] = std::min(dp[i], dp[s + 1] + 1);
      }
    }
  }
  return dp[0];
}

int PalindromeMinCutDp2(const string& str)
{
  if (str.empty())
  {
    return 0;
  }
  vector<int> dp(str.size() + 1, 0x7fffffff);
  dp[dp.size() - 1] = -1;
  vector<vector<bool>> isPalindromes(str.size(), vector<bool>(str.size(), false));
  for (int i = dp.size() - 2; i >= 0; --i)
  {
    for (int s = i; s < str.size(); ++s)
    {
      if (str[i] == str[s] && (s - i < 2 || isPalindromes[i + 1][s - 1]))
      {
        isPalindromes[i][s] = true;
        dp[i] = std::min(dp[i], dp[s + 1] + 1);
      }
    }
  }
  return dp[0];
}

int main(void)
{
  string str = "acdcdcdad";
  std::cout << PalindromeMinCut(str) << std::endl;
  std::cout << PalindromeMinCutDp(str) << std::endl;
  std::cout << PalindromeMinCutDp2(str) << std::endl;

  return 0;
}
