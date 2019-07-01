#include <iostream>
#include <list>
#include <vector>

using std::list;
using std::vector;

struct Staff
{
  int happy;
  list<Staff*> nexts;

  Staff(int h)
    : happy(h),nexts()
  {}
};

struct ReturnType
{
  int laiMax;
  int buLaiMax;
  
  ReturnType(int lm, int blm)
    : laiMax(lm), buLaiMax(blm)
  {}
};

void PrintDp(const vector<vector<int>>& dp)
{
  std::cout << "dp: " << std::endl;
  for (int i = 0; i < dp.size(); ++i)
  {
    for (int j = 0; j < dp[0].size(); ++j)
    {
      std::cout << dp[i][j] << " ";
    }
    std::cout << std::endl;
  }
}

void PrintVector(const vector<bool>& v)
{
  std::cout << "visited:" << std::endl;
  for (int i = 0; i <v.size(); ++i)
  {
    std::cout << v[i] << " ";
  }
  std::cout << std::endl;
}

ReturnType Process(Staff* pNode)
{
  if (pNode == nullptr)
  {
    return ReturnType(0, 0);
  }
  vector<ReturnType> nextsResult;
  for (auto it = pNode->nexts.begin(); it != pNode->nexts.end(); ++it)
  {
    nextsResult.push_back(Process(*it));
  }
  int laiMax = pNode->happy;
  int buLaiMax = 0;
  for (auto it = nextsResult.begin(); it != nextsResult.end(); ++it)
  {
    laiMax += it->buLaiMax;
    buLaiMax += std::max(it->buLaiMax, it->laiMax);
  }
  return ReturnType(laiMax, buLaiMax);
}

int MaxHappy1(Staff* pRoot)
{
  if (pRoot == nullptr)
  {
    return 0;
  }
  ReturnType res = Process(pRoot);
  return std::max(res.laiMax, res.buLaiMax);
}

void Process1(const vector<vector<int>>& staff,
              vector<vector<int>>& dp,
              vector<bool>& visited,
              int root)
{
  visited[root] = true;
  dp[root][1] = staff[root][1];
  for (int i = 0; i < staff.size(); ++i)
  {
    //遍历这个父节点相关的子节点 直到找到最底层的节点 
    //由于最底层节点 无依赖可以填值 来去自如 别人不受影响
    if (staff[i][0] == root && !visited[i])
    {
      Process1(staff, dp, visited, i);
      dp[root][1] += dp[i][0];
      dp[root][0] += std::max(dp[i][1], dp[i][0]);
    }
  }
}

int MaxHappy2(const vector<vector<int>>& staff)
{
  if (staff.empty() || staff[0].empty())
  {
    return 0;
  }
  vector<vector<int>> dp(staff.size(), vector<int>(2));
  vector<bool> visited(staff.size(), false);
  int root = 0;
  for (int i = 0; i < staff.size(); ++i)
  {
    if (i == staff[i][0])
    {
      root = i;
    }
  }
  Process1(staff, dp, visited, root);
  //PrintDp(dp);
  //PrintVector(visited);
  return std::max(dp[root][0], dp[root][1]);
}

int main(void)
{
  vector<vector<int>> staff = { { 1, 8 }, { 1, 9 }, { 1, 10 } };
  std::cout << MaxHappy2(staff) << std::endl;
   std::cout << MaxHappy1(staff) << std::endl;
  return 0;
}
