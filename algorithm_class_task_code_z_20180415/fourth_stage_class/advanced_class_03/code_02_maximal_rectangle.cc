#include <iostream>
#include <vector>
#include <stack>

using std::vector;
using std::stack;

int MaxRecFromBottom(const vector<int>& height)
{
  if (height.empty())
  {
    return 0;
  }
  stack<int> st;
  int maxArea = 0;
  for (int i = 0; i < height.size(); ++i)
  {
    while (!st.empty() && height[st.top()] >= height[i])
    {
      int cur = st.top();
      st.pop();
      int l = st.empty() ? -1 : st.top();
      maxArea = std::max(maxArea, (i - l - 1) * height[cur]);
    }
    st.push(i);
  }
  while (!st.empty())
  {
    int cur = st.top();
    st.pop();
    int l = st.empty() ? -1 : st.top();
    int curArea = (height.size() - l - 1) * height[cur];
    maxArea = std::max(maxArea, curArea);
  }
  return maxArea;
}

int MaxRecSize(const vector<vector<int>>& matrix)
{
  if (matrix.empty() || matrix[0].empty())
  {
    return 0;
  }
  vector<int> height(matrix.size(), 0);
  int maxArea = 0;
  for (int i = 0; i < matrix.size(); ++i)
  {
    for (int j = 0; j < matrix[0].size(); ++j)
    {
      height[j] = matrix[i][j] == 0 ? 0 : height[j] + 1;
      maxArea = std::max(MaxRecFromBottom(height), maxArea);
    }
  }
  return maxArea;
}

int main(void)
{
  vector<vector<int>> matrix = { { 1, 0, 1, 1 }, { 1, 1, 1, 1 }, { 1, 1, 1, 0 }, };
  std::cout << MaxRecSize(matrix) << std::endl;
  return 0;
}
