#include <iostream>
#include <string>
#include <vector>

using std::string;
using std::vector;

int LCSProcess(const string& s1, const string& s2, int i, int j)
{
  if (i == 0 && j == 0)
  {
    return s1[i] == s2[j] ? 1 : 0;
  }
  if (i == 0 || j == 0)
  {
    return 0;
  }
  if (s1[i] == s2[j])
  {
    return LCSProcess(s1, s2, i - 1, j - 1) + 1;
  }
  return 0;
}

int LCS(const string& s1, const string& s2)
{
  if (s1.empty() || s2.empty())
  {
    return 0;
  }
  int maxLen = 0;
  for (int i = s1.size() - 1; i >= 0; --i)
  {
    for (int j = s2.size() - 1; j >= 0; --j)
    {
      //返回以每个位置结尾的情况下最长的公共字串
      int tmp = LCSProcess(s1, s2, i, j);
      std::cout << tmp << " ";
      maxLen = std::max(maxLen, tmp);
    }
  }
  std::cout << std::endl;
  return maxLen;
}

vector<vector<int>> LCSDp(const string& s1, const string& s2, int end, int maxLen)
{
  if (s1.empty() || s2.empty())
  {
    return vector<vector<int>>();
  }
  vector<vector<int>> dp(s1.size(), vector<int>(s2.size()));
  dp[0][0] = s1[0] == s2[0] ? 1 : 0;
  for (int i = 1; i < s1.size(); ++i)
  {
    dp[i][0] = s1[1] == s2[0] ? 1 : 0;
  }
  for (int j = 1; j < s2.size(); ++j)
  {
    dp[0][j] = s1[0] == s2[j] ? 1 : 0;
  }
  for (int i = 1; i < s1.size(); ++i)
  {
    for (int j = 1; j < s2.size(); ++j)
    {
      if (s1[i] == s2[j])
      {
        dp[i][j] = dp[i -1][j - 1] + 1;
      }
	  if (maxLen < dp[i][j])
	  {
		  maxLen = dp[i][j];
		  end = i;
	  }
    }
  }
  return dp;
}

string LCSubstring(const string& s1, const string& s2)
{
  if (s1.empty() || s2.empty())
  {
    return string();
  }
  int end = -1;
  int maxLen = 0;
  vector<vector<int>> dp = LCSDp(s1, s2, end, maxLen);
  return s1.substr(end + 1 - maxLen, maxLen);
}

//矩阵压缩技术
string LCSubstring2(const string& s1, const string& s2)
{
  if (s1.empty() || s2.empty())
  {
    return string();
  }
  int row = 0;
  int col = s2.size() - 1;
  int maxLen = 0;
  int end = 0;
  while (row < s1.size())//以s1的每个位置结尾
  {
    int i = row;
    int j = col;
    int len = 0;
    while (i < s1.size() && j < s2.size()) //以s2 每个位置结尾的情况下 由于只要每个位置结尾下的长度 所以不用dp记录每个过程
    {
      if (s1[i++] == s2[j++]) //只计算相等的情况S
      {
        ++len;
      }
      else
      {
        len = 0;
      }
      if (len > maxLen)
      {
        maxLen = len;
        end = i;
      }
    }
    if (col > 0)
    {
      --col;
    }
    else
    {
      ++row;
    }
  }
  return s1.substr(end + 1 -maxLen, maxLen);
}

int main(void)
{
  string s1 = "1ab2345cd";
  string s2 = "12345ef";
  std::cout << LCS(s1, s2) << std::endl;
  std::cout << LCSubstring(s1, s2) << std::endl;
  std::cout << LCSubstring2(s1, s2) << std::endl;
  
  return 0;
}
