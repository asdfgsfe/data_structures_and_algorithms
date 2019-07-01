#include <iostream>
#include <vector>
#include <list>

using std::vector;
using std::list;

struct ReturnData
{
  int buLaiHuo;
  int laiHuo;
  ReturnData(int bh, int lh)
    : buLaiHuo(bh), laiHuo(lh)
  {}
};

struct TreeNode
{
  int happy;
  list<TreeNode*> children;
  TreeNode(int v)
    : happy(v)
  {}
};

ReturnData Process(const TreeNode* pNode)
{
  if (pNode == nullptr)
  {
    return ReturnData(0, 0);
  }
  int buLaiHuo = 0;
  int laiHuo = pNode->happy;
  for (const auto& child : pNode->children)
  {
    ReturnData happyInfo = Process(child);
    laiHuo += happyInfo.buLaiHuo;
    buLaiHuo += std::max(happyInfo.laiHuo, happyInfo.buLaiHuo);
  }
  return ReturnData(buLaiHuo, laiHuo);
}

int MaxHappy(const TreeNode* pRoot)
{
  if (pRoot == nullptr)
  {
    return 0;
  }
  ReturnData happyInfo = Process(pRoot);
  return std::max(happyInfo.buLaiHuo, happyInfo.laiHuo);
}

void Process2(const vector<vector<int>>& matrix,
              vector<vector<int>>& dp, 
              vector<bool>& visited,
              int node)
{
  visited[node] = true;
  dp[node][1] = matrix[node][1];
  for (int i = 0; i < matrix.size(); ++i)
  {
    if (matrix[i][0] == node && !visited[i])
    {
      Process2(matrix, dp, visited, i);
      dp[node][1] += dp[i][0];
      dp[node][0] += std::max(dp[i][0], dp[i][1]);
    }
  }
}

int MaxHappy2(const vector<vector<int>>& matrix)
{
  if (matrix.empty() || matrix[0].empty())
  {
    return 0;
  }
  vector<vector<int>> dp(matrix.size(), vector<int>(2, 0));
  vector<bool> visited(matrix.size(), false);
  int root = 0;
  for (int i = 0; i < matrix.size(); ++i)
  {
    if (i == matrix[i][0])
    {
      root = i;
    }
  }
  Process2(matrix, dp, visited, root);
  return std::max(dp[root][0], dp[root][1]);
}

int main(void)
{
  vector<vector<int>> matrix = { { 1, 8 }, { 1, 9 }, { 1, 10 } };
  std::cout << MaxHappy2(matrix) << std::endl;

  return 0;
}
