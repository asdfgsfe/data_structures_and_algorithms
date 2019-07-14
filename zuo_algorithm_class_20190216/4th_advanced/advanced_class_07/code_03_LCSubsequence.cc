#include <iostream>
#include <string>
#include <vector>

using std::string;
using std::vector;

int LCSProcess(const string& s1, const string& s2, int i, int j)
{
  if (i == 0 && j == 0)
  {
    //待验证 此处应该返回0 : -1 因为在传入参数的时候已经加了1
    return s1[i] == s2[j] ? 1 : 0;
  }
  if (i == 0 || j == 0)
  {
    return 0;
  }
  int maxLCS = 0;
  //来自三种尝试的策略 
  //1.如果i=j同时向前走 
  //2.不想等 分区去尝试 i向前走或者j向前走 选出三种方式中的最大值
  if (s1[i] == s2[j])
  {
    maxLCS = LCSProcess(s1, s2, i - 1, j - 1) + 1;
  }
  maxLCS = std::max(maxLCS, std::max(LCSProcess(s1, s2, i - 1, j), LCSProcess(s1, s2, i, j - 1)));
  return maxLCS;
}

//仅仅只是返回 最长无重复子序列的长度
int LCS(const string& s1, const string& s2)
{
  if (s1.empty() || s2.empty())
  {
    return 0;
  }
  return LCSProcess(s1, s2, s1.size() - 1, s2.size() - 1);//此处从零开始 还是从末尾开始选择都一样
}

//对于dp多取大一行 可以简化初始化dp的代码
vecor<vector<int>> GenDp(const string& s1, const string& s2)
{
	if (s1.empty() || s2.empty())
	{
		return vector<vector<int>>();
	}
	vector<vector<int>> dp(s1.size() + 1, vector<int>(s2.size() + 1, 0));
	dp.back().back() = 1; //这个地方可以实际测试下 有必要为等于1吗 感觉等于0就行
	for (int i = dp.size() - 2; i >= 0; --i)
	{
		for (int j = dp[0].size() - 2; j >= 0; --j)
		{
			dp[i][j] = std::max(dp[i + 1][j], dp[i][j + 1]);
			if (s1[i] == s2[j])
			{
				dp[i][j] = std::max(dp[i][j], dp[i + 1][j + 1] + 1);
			}
		}
	}
	return dp;
}


vector<vector<int>> LCSDp(const string& s1, const string& s2)
{
  if (s1.empty() || s2.empty())
  {
    return vector<vector<int>>();
  }
  vector<vector<int>> dp(s1.size(), vector<int>(s2.size(), 0));
  dp[0][0] = s1[0] == s2[0] ? 1 : 0;
  for (int i = 1; i < s1.size(); ++i)
  {
    dp[i][0] = std::max(dp[i - 1][0], s1[i] == s2[0] ? 1 : 0);
  }
  for (int j = 1; j < s2.size(); ++j)
  {
    dp[0][j] = std::max(dp[0][j - 1], s1[0] == s2[j] ? 1 : 0);
  }
  for (int i = 1; i < dp.size(); ++i)
  {
    for (int j = 1; j < dp[0].size(); ++j)
    {
      dp[i][j] = std::max(dp[i - 1][j], dp[i][j - 1]);
      if (s1[i] == s2[j])
      {
        dp[i][j] = std::max(dp[i][j], dp[i - 1][j - 1] + 1);
      }
    }
  }
  return dp;
}

string LCSE(const string& s1, const string& s2)
{
  if (s1.empty() || s2.empty())
  {
    return string();
  }
  vector<vector<int>> dp = LCSDp(s1, s2);
  int m = dp.size() - 1;
  int n = dp[0].size() - 1;
  int index = dp[m][n] - 1;
  char res[index + 1];
  while (index >= 0)
  {
    if (n > 0 && dp[m][n] == dp[m][n - 1])
    {
      --n;
    }
    else if (m > 0 && dp[m][n] == dp[m - 1][n])
    {
      --m;
    }
    else //s1[i] == s2[j]
    {
      res[index--] = s1[m--];
      --n;
    }
  }
  return string(res, dp[dp.size() - 1][dp[0].size() - 1]);
}

int main(void)
{
  string s1 = "1a2c3d4b56";
  string s2 = "b1d23ca45b6a";
  std::cout << LCS(s1, s2) << std::endl;
  std::cout << LCSE(s1, s2) << std::endl;

  return 0;
}
