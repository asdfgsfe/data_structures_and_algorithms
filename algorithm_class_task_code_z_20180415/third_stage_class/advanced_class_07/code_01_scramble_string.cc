#include <iostream>
#include <string>
#include <vector>

using std::string;
using std::vector;

//这种模型可以用到子矩阵的统计 两个点就能构成子矩阵
bool Process1(const string& s1, const string& s2, int l1, int r1, int l2, int r2)
{
  if (l1 == r1)
  {
    return s1[l1] == s2[l2];
  }
  for (int i = 0; i < (r1 - l1); ++i)
  {
    if ((Process1(s1, s2, l1, l1 + i, l2, l2 + i) && Process1(s1, s2, l1 + i + 1, r1, l2 + i + 1, r2))
        || (Process1(s1, s2, l1, l1 + i, r2 - i, r2) && Process1(s1, s2, l1 + i + 1, r1, l2, r2 - i - 1)))
    {
      return true;
    }
  }
  return false;
}

//这种模型可以用到子正方形的统计 size就相当于子正方形的边长
//size == r1 - l1
bool Process2(const string& s1, const string& s2, int l1, int l2, int size)
{
  if (size == 1)
  {
    return s1[l1] == s2[l2];
  }
  for (int part = 1; part < size; ++part)
  {
    if ((Process2(s1, s2, l1, l2, part) && Process2(s1, s2, l1 + part, l2 + part, size - part))
        || (Process2(s1, s2, l1, l2 + size - part, part) && Process2(s1, s2, l1 + part, l2, size - part)))
    {
      return true;
    }
  }
  return false;
}

bool IsScrambleString1(const string& s1, const string& s2)
{
  if (s1.size() != s2.size())
  {
    return false;
  } 
  if (s1 == s2)
  {
    return true;
  }
  //return Process1(s1, s2, 0, s1.size() - 1, 0, s2.size() - 1);
  return Process2(s1, s2, 0, 0, s1.size());
}

bool IsScrambleString2(const string& s1, const string& s2)
{
  if (s1.size() != s2.size())
  {
    return false;
  }
  if (s1 == s2)
  {
    return true;
  }
  
  int n = s1.size();
  vector<vector<vector<bool>>> dp(n, vector<vector<bool>>(n, vector<bool>(n + 1)));
  for (int l1 = 0; l1 < n; ++l1)
  {
    for (int l2 = 0; l2 < n; ++l2)
    {
      dp[l1][l2][1] = s1[l1] == s2[l2];
    }
  }
  for (int size = 2; size <= n; ++size)
  {
    for (int l1 = 0; l1 < n - size; ++l1)
    {
      for (int l2 = 0; l2 < n - size; ++l2)
      {
        for (int p = 1; p < size; ++p)
        {
          if ((dp[l1][l2][p] && dp[l1 + p][l2 + p][size - p]) 
              || (dp[l1][l2 + size - p][p] && dp[l1 + p][l2][size - p]))
          {
            dp[l1][l2][size] = true;
            break;
          }
        }
      }
    }
  }
  return dp[0][0][n];
}


int main(void)
{
  string s1 = "bcdebcdebcdebcdebcdebcdebcdebcdebcdebcdebcdebcdebcdebcdebcdebcdebcdebcdebcdebcdebcdebcde";
  string s2 = "cebdcebdcebdcebdcebdcebdcebdcebdcebdcebdcebdcebdcebdcebdcebdcebdcebdcebdcebdcebdcebdcebd";
  //std::cout << IsScrambleString1(s1, s2) << std::endl;
  std::cout << IsScrambleString2(s1, s2) << std::endl;

  s1 = "great";
  s2 = "rgtae";
  //std::cout << IsScrambleString1(s1, s2) << std::endl;
  std::cout << IsScrambleString2(s1, s2) << std::endl;

  return 0;
}
