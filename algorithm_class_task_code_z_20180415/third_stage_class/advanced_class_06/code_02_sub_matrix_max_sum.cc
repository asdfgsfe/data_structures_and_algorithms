#include <iostream>
#include <vector>

using std::vector;

int SubArrayMaxSum(const vector<int>& arr)
{
  if (arr.empty())
  {
    return 0;
  }
  int cur = 0;
  int max = 0x80000000;
  for (int i = 0; i < arr.size(); ++i)
  {
    cur += arr[i];
    max = std::max(max, cur);
    cur = cur < 0 ? 0 : cur;
  }
  return max;
}

int SubMatrixMaxSum(const vector<vector<int>>& matrix)
{
  if (matrix.empty() || matrix[0].empty())
  {
    return 0;
  }
  
  int rows = matrix.size();
  int cols = matrix[0].size();
  int res = 0x80000000;
  for (int i = 0; i < rows; ++i)
  {
    vector<int> tmp = matrix[i];
    for (int j = i; j < rows; ++j)
    {
      for (int k = 0; k < cols & j != 0; ++k)
      {
        tmp[k] += matrix[j][k];
      }
      int cur = SubArrayMaxSum(tmp);
      res = std::max(res, cur);
    }
  }
  return res;
}

int SubMatrixMaxSum2(const vector<vector<int>>& matrix)
{
  if (matrix.empty() || matrix[0].empty())
  {
    return 0;
  }
  int max = 0x80000000;
  for (int i = 0; i < matrix.size(); ++i)
  {
    vector<int> s(matrix[0].size(), 0);
    for (int j = i; j < matrix.size(); ++j)
    {
      int cur = 0;
      for (int k = 0; k < matrix[0].size(); ++k)
      {
        s[k] += matrix[j][k];
        cur += s[k];
        max = std::max(max, cur);
        cur = cur < 0 ? 0 : cur;
      }
    }
  }
  return max;
}

int main(void)
{
  vector<vector<int>> matrix = { { -90, 48, 78 }, 
                                { 64, -40, 64 }, 
                                { -81, -7, 66 } };
  std::cout << SubMatrixMaxSum(matrix) << std::endl;
  std::cout << SubMatrixMaxSum2(matrix) << std::endl;

  return 0;
}
