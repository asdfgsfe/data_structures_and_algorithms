#include <iostream>
#include <vector>

using std::vector;

void PrintVector(const vector<int>& v)
{
  for (int i = 0; i < v.size(); ++i)
  {
    std::cout << v[i] << " ";
  }
  std::cout << std::endl;
}

vector<int> SubArrayMaxSum(const vector<int>& arr, bool flag)
{
  int cur = 0;
  int max = 0x80000000;
  vector<int> records(arr.size());
  if (flag)
  {
    int p = 0;
    for (int i = 0; i <= arr.size(); ++i)
    {
      cur += arr[i];
      max = std::max(cur, max);
      cur = cur < 0 ? 0 : cur;
      records[p++] = max;
    }
  }
  else
  {
    int p = arr.size() - 1;
    for (int i = arr.size() - 1; i >= 0; --i)
    {
      cur += arr[i];
      max = std::max(cur, max);
      cur = cur < 0 ? 0 : cur;
      records[p--] = max;
    }
  }
  return records;
}

int TwoSubArrayMaxSum(const vector<int>& arr)
{
  if (arr.empty())
  {
    return 0;
  }
  int max = 0x80000000;
  vector<int> arrL = SubArrayMaxSum(arr, true);
  vector<int> arrR = SubArrayMaxSum(arr, false);
  //PrintVector(arrL);
  //PrintVector(arrR);
  for (int i = 1; i < arr.size(); ++i)
  {
    int cur = arrL[i-1] + arrR[i];
    max = std::max(cur, max);
  }
  return max;
}

int main(void)
{
  vector<int> v = {-3, 4, 1, 3, -3};
  std::cout << TwoSubArrayMaxSum(v) << std::endl;

  return 0;
}
