#include <iostream>
#include <string>
#include <vector>

using std::string;
using std::vector;

bool IsVaild(const string& str, const string& exp)
{
  for (int i = 0; i < str.size(); ++i)
  {
    if (str[i] == '.' || str[i] == '*')
    {
      return false;
    }
  }
  for (int i = 0; i < exp.size(); ++i)
  {
    if (exp[i] == '*' && (i == 0 || exp[i-1] == '*'))
    {
      return false;
    }
  }
  return true;
}

bool Process(const string& s, const string& e, int si, int ei)
{
  if (ei == e.size())
  {
    return si == s.size();
  }
  if (ei + 1 == e.size() || e[ei + 1] != '*')
  {
    return si != s.size() && (e[ei] == s[si] || e[ei] == '.') && Process(s, e, si + 1, ei + 1);
  }
  while (si != s.size() && (s[si] == e[ei] || e[ei] == '.'))
  {
    if (Process(s, e, si, ei + 2))
    {
      return true;
    }
    ++si;
  }
  return Process(s, e, si, ei + 2);
}

bool IsMatch(const string& str, const string& exp)
{
  if (str.empty() && exp.empty())
  {
    return true;
  }
  if (str.empty() || exp.empty())
  {
    return false;
  }
  
  return IsVaild(str, exp) && Process(str, exp, 0, 0);
}

vector<vector<bool>> InitDp(const string& str, const string& exp)
{
  int slen = str.size();
  int elen = exp.size();
  vector<vector<bool>> dp(slen + 1, vector<bool>(elen + 1, false));
  dp[slen][elen] = true;
  for (int i = elen - 2; i >= 0; i -= 2)
  {
    if (exp[i] != '*' && exp[i+1] == '*')
    {
      dp[slen][i] = true;
    }
    else
    {
      break;
    }
  }

  if (slen > 0 && elen > 0)
  {
    if (str[slen-1] == exp[elen-1] || exp[elen-1] == '.')
    {
      dp[slen-1][elen-1] = true;
    }
  }
  return dp;
}

bool IsMatchDp(const string& str, const string& exp)
{
  if (str.empty() && exp.empty())
  {
    return true;
  }
  if (str.empty() || exp.empty())
  {
    return false;
  }
  if (!IsVaild(str, exp))
  {
    return false;
  }

  vector<vector<bool>> dp = InitDp(str, exp);
  for (int i = str.size() - 1; i >= 0; --i)
  {
    for (int j = exp.size() - 2; j >= 0; --j)
    {
      if (exp[j+1] != '*')
      {
        dp[i][j] = (exp[j] == str[i] || exp[j] == '.') && dp[i+1][j+1];
      }
      else
      {
        int si = i;
        while (si < str.size() && (str[si] == exp[j] || exp[j] == '.'))
        {
          if (dp[si][j+2])
          {
            dp[i][j] = true;
            break;
          }
          ++si;
        }
        if (!dp[i][j])
        {
          dp[i][j] = dp[si][j+2];
        }
      }
    }
  }
  return dp[0][0];
}

int main(void)
{
  string str = "abcccdefg";
  string exp = "ab.*d.*e.*";
  std::cout << "1: " << IsMatch(str, exp) << std::endl;
  std::cout << "2: " << IsMatchDp(str, exp) << std::endl;
  
  str = "";
  exp = "..*";
  std::cout << "3: " << IsMatch(str, exp) << std::endl;
  std::cout << "4: " << IsMatchDp(str, exp) << std::endl;

  str = "abc";
  exp = "a.c";
  std::cout << "5: " << IsMatch(str, exp) << std::endl;
  std::cout << "6: " << IsMatchDp(str, exp) << std::endl;

  str = "abcd";
  exp = ".*";
  std::cout << "7: " << IsMatch(str, exp) << std::endl;
  std::cout << "8: " << IsMatchDp(str, exp) << std::endl;

  return 0;
}
