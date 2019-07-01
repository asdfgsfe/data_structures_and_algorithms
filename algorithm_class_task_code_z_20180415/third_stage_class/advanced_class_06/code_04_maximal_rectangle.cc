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
  int maxArea = 0;
  stack<int> st;
  for (int i = 0; i < height.size(); ++i)
  {
    while (!st.empty() && height[i] <= height[st.top()])
    {
      int j = st.top();
      st.pop();
      int k = st.empty() ? -1 : st.top();
      int currArea = (i - k - 1) * height[j];
      maxArea = std::max(maxArea, currArea);
    }
    st.push(i);
  }
  while (!st.empty())
  {
    int j = st.top();
    st.pop();
    int k = st.empty() ? -1 : st.top();
    int currArea = (height.size() - k - 1) * height[j];
    maxArea = std::max(maxArea, currArea);
  }
  return maxArea;
}

int MaxRectangleSize(const vector<vector<int>>& matrix)
{
  if (matrix.empty() || matrix[0].empty())
  {
    return 0;
  }
  vector<int> height(matrix[0].size(), 0);
  int maxArea = 0;
  for (int i = 0; i < matrix.size(); ++i)
  {
    for (int j = 0; j < matrix[0].size(); ++j)
    {
      height[j] = matrix[i][j] == 0 ? 0 : height[j] + 1;
    }
    maxArea = std::max(MaxRecFromBottom(height), maxArea);
  }
  return maxArea;
}

int main(void)
{
  vector<vector<int>> matrix = { { 1, 0, 1, 1 }, { 1, 1, 1, 1 }, { 1, 1, 1, 0 } };
  std::cout << MaxRectangleSize(matrix) << std::endl;

  return 0;
}
