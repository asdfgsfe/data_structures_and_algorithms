#include <iostream>
#include <vector>
#include <unordered_map>

using std::vector;
using std::unordered_map;

int LongestSumSubArrayLength(const vector<int>& v, int k)
{
  if (v.empty())
  {
    return 0;
  }
  unordered_map<int, int> sumPosition;
  sumPosition[0] = 1;
  int sum = 0;
  int len = 0;
  for (int i = 0; i < v.size(); ++i)
  {
    sum += v[i];
    if (sumPosition.find(sum - k) != sumPosition.end())
    {
      len = std::max(len, i - sumPosition[sum - k]);
    }
    if (sumPosition.find(sum) == sumPosition.end())
    {
      sumPosition[sum] = i;
    }
  }
  return len;
}

int main(void)
{
  vector<int> v = {7, 3, 2, 1, 1, 7, -6, -1, 7};
  std::cout << LongestSumSubArrayLength(v, 7) << std::endl;

  return 0;
}
