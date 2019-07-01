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

int SubArrayMaxSum2(const vector<int>& arr)
{
  if (arr.empty())
  {
    return 0;
  }
  int cur = 0;
  int max = 0x80000000;
  for (int i = 0; i < arr.size(); ++i)
  {
    cur = cur < 0 ? arr[i] : cur + arr[i];
    max = std::max(cur, max);
  }
  return max;
}

int main(void)
{
  vector<int> arr1 = { -2, -3, -5, 40, -10, -10, 100, 1 };
  std::cout << SubArrayMaxSum(arr1) << std::endl;
  std::cout << SubArrayMaxSum2(arr1) << std::endl;

  vector<int> arr2 = { -2, -3, -5, 0, 1, 2, -1 };
  std::cout << SubArrayMaxSum(arr2) << std::endl;
  std::cout << SubArrayMaxSum2(arr2) << std::endl;

  vector<int> arr3 = { -2, -3, -5, -1 };
  std::cout << SubArrayMaxSum(arr3) << std::endl;
  std::cout << SubArrayMaxSum2(arr3) << std::endl;

  return 0;
}
