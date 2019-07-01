#include <iostream>
#include <string>
#include <assert.h>
#include <vector>

using std::string;
using std::vector;

bool IsPalindrome1(const string& str, int l, int r)
{
  assert(r >= 0 && r < str.size());
  assert(l >= 0 && l <= r);
  while (l <= r)
  {
    if (str[l++] != str[r--])
    {
      return false;
    }
  }
  return true;
}

bool IsPalindrome2(const string& str, int l, int r)
{
  if (l == r)
  {
    return true;
  }
  if (str[l] != str[r])
  {
    return false;
  }
  return IsPalindrome2(str, --l, --r);
}

int Process(const string& str, int i)
{
  if (i == str.size())
  {
    return 0;
  }
  int min = 0x7fffffff;
  for (int k = i; k < str.size(); ++k)
  {
    if (IsPalindrome1(str, i, k))
    {
      min = std::min(min, Process(str, k + 1));
    }
  }
  return min + 1;
}

int MinCut1(const string& str)
{
  if (str.empty() || str.size() == 1)
  {
    return 0;
  }
  return Process(str, 0);
}

int MinCut2(const string& str)
{
  if (str.empty() || str.size() == 1)
  {
    return 0;
  }
  vector<int> dp(str.size() + 1);
  dp[str.size()] = -1;
  vector<vector<bool>> p(str.size(), vector<bool>(str.size(), false));
  for (int i = str.size() - 1; i >= 0; --i)
  {
    dp[i] = 0x7fffffff;
    for (int j = i; j < str.size(); ++j)
    {
      if (str[i] == str[j] && (j - i < 2 || p[i+1][j-1]))
      {
        p[i][j] = true;
        dp[i] = std::min(dp[i], dp[j+1] + 1);
      }
    }
  }
  return dp[0];
}

int main(void)
{
  string s1 = "ABBA";
  std::cout << MinCut1(s1) << std::endl;
  std::cout << MinCut2(s1) << std::endl;
  s1 = "ACDCDCDAD";
  std::cout << MinCut1(s1) << std::endl;
  std::cout << MinCut2(s1) << std::endl;
  
  //std::cout << IsPalindrome1(s1, 0, 3) << std::endl;
  return 0;
}
