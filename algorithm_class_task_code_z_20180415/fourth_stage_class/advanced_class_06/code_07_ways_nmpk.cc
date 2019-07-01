#include <iostream>
#include <vector>

using std::vector;

int Ways(int n, int m, int p, int k)
{
  if (n < 2 || m < 1 || m > n || p < 0 || k < 1 || k > n)
  {
    return 0;
  }
  if (p == 0)
  {
    return m == k ? 1 : 0;
  }
  int res = 0;
  if (m == 1)
  {
    res = Ways(n, m + 1, p - 1, k);
  }
  else if (m == n)
  {
    res = Ways(n, m - 1, p - 1, k);
  }
  else
  {
    res = Ways(n, m + 1, p - 1, k) + Ways(n, m - 1, p - 1, k);
  }
  return res;
}

int WaysDp(int n, int m, int p, int k)
{
  if (n < 2 || m < 1 || m > n || p < 0 || k < 1 || k > n)
  {
    return 0;
  }
  vector<vector<int>> dp(p + 1, vector<int>(n + 1, 0));
  dp[0][k] = 1;
  int res = 0;
  for (int i = 1; i <= p; ++i)
  {
    for (int j = 1; j <= n; ++j)
    {
      if (j == 1)
      {
        dp[i][j] = dp[i - 1][j + 1];
      }
      else if (j == n)
      {
        dp[i][j] = dp[i - 1][j - 1];  
      }
      else
      {
        dp[i][j] = dp[i - 1][j + 1] + dp[i - 1][j - 1];
      }
    }
  }
  return dp[p][m];
}

int main(void)
{
  int n = 5;
  int m = 3;
  int p = 5;
  int k = 4;
  std::cout << Ways(n, m, p, k) << std::endl;
  std::cout << WaysDp(n, m, p, k) << std::endl;

  return 0;
}
