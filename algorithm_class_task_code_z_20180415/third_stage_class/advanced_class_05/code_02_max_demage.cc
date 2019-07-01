#include <iostream>
#include <vector>

using std::vector;

void PrintMatrix(const vector<vector<int>>& v)
{
  for (int i = 0; i < v.size(); ++i)
  {
    for (int j = 0; j < v[0].size(); ++j)
    {
      std::cout << v[i][j] << " ";
    }
    std::cout << std::endl;
  }
}

int Process(const vector<int>& v, int id, int threshold)
{
  if (threshold < 0)
  {
    return -1;
  }
  if (id == v.size())
  {
    return threshold == 0 ? 1 : -1;
  }
  
  int noIncludeCurr = Process(v, id + 1, threshold);
  int includeCurr = v[id] * Process(v, id + 1, threshold - v[id]);
  return std::max(noIncludeCurr, includeCurr);
}

int MaxDemage(const vector<int>& v, int threshold)
{
  if (v.empty() || threshold < 0)
  {
    return -1;
  }
  return Process(v, 0, threshold);
}

int MaxDemage2(const vector<int>& v, int threshold)
{
  if (v.empty() || threshold < 0)
  {
    return -1;
  }

  //顺序填写矩阵 0->n
  vector<vector<int>> dp(v.size(), vector<int>(threshold + 1, 0));
  if (v[0] <= threshold)
  {
    dp[0][v[0]] = v[0];
  }
  for (int i = 1; i < v.size(); ++i)
  {
    for (int j = 0; j <= threshold; ++j)
    {
      int no = dp[i-1][j];
      int only = j - v[i] == 0 ? v[i] : 0;
      int part = j - v[i] > 0 ? dp[i-1][j-v[i]]*v[i] : 0;
      dp[i][j] = std::max(no, std::max(only, part));
    }
  }
  PrintMatrix(dp);
  return dp[dp.size() - 1][dp[0].size() - 1];
}

int main(void)
{
  vector<int> v = {1, 2, 3, 4, 5};
  int threshold =  10;
  std::cout << MaxDemage(v, threshold) << std::endl;
  std::cout << MaxDemage2(v, threshold) << std::endl;

  return 0;
}
