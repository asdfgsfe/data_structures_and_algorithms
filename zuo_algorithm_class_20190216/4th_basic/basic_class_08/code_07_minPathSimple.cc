#include <iostream>
#include <vector>

using std::vector;

//Recusion
int MinProcess(const vector<vector<int>>& m, int r, int c)
{
  if (r < 0 || r >= m.size() || c < 0 || c >= m[0].size())
  {
    return 0;
  }
  return m[r][c] + std::min(MinProcess(m, r + 1, c), MinProcess(m, r, c + 1));
}

int MinPath1(const vector<vector<int>>& m)
{
  if (m.empty() || m[0].empty())
  {
    return 0;
  }
  return MinProcess(m, 0, 0);
}

//DP
int MinPathDp(const vector<vector<int>>& m)
{
  if (m.empty() || m[0].empty())
  {
    return 0;
  }
  vector<vector<int>> dp(m.size() + 1, vector<int>(m[0].size() + 1, 0));
  for (int i = dp.size() - 2; i >= 0; --i)
  {
    for (int j = dp[0].size() - 2; j >= 0; --j)
    {
      dp[i][j] = std::min(dp[i + 1][j], dp[i][j + 1]) + m[i][j];
    }
  }
  return dp[0][0];
}

void Dump(const vector<int>& vs)
{
  for (int v : vs)
  {
    std::cout << v << " ";
  }
  std::cout << std::endl;
}

//矩阵压缩
int MinPathDp2(const vector<vector<int>>& m)
{
  if (m.empty() || m[0].empty())
  {
    return 0;
  }
  vector<int> dp(std::min(m.size(), m[0].size()));
  dp[0] = m[0][0];
  for (int i = 1; i < dp.size(); ++i)
  {
    dp[i] = dp[i - 1] + (m.size() >= m[0].size() ? m[0][i] : m[i][0]);
  }
  for (int i = 1; i < std::max(m.size(), m[0].size()); ++i)
  {
    dp[0] += m.size() >= m[0].size() ? m[i][0] : m[0][i];
    for (int j = 1; j < std::min(m.size(), m[0].size()); ++j)
    {
      dp[j] = std::min(dp[j], dp[j - 1]) + (m.size() >= m[0].size() ? m[i][j] : m[j][i]);
    }
  }
  return dp.back();
}


int main(void)
{
  vector<vector<int>> m = { 
                            {1, 3, 5, 9 }, 
                            {8, 1, 3, 4 }, 
                            {5, 0, 6, 1 }, 
                            {8, 8, 4, 0 } 
                          };
  std::cout << MinPathDp(m) << std::endl;
  std::cout << MinPathDp2(m) << std::endl;
  std::cout << MinPath1(m) << std::endl;
  
  return 0;
}
