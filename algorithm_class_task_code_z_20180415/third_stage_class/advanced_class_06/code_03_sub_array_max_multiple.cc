#include <iostream>
#include<vector>

using std::vector;

double SubArrayMaxMutiple(const vector<double>& arr)
{
  if (arr.empty())
  {
    return 0.0;
  }
  double curMax = arr[0];
  double curMin = arr[0];
  double max = arr[0];
  for (int i = 1; i < arr.size(); ++i)
  {
    double maxEnd = curMax * arr[i];
    double minEnd = curMin * arr[i];
    curMax = std::max(std::max(maxEnd, minEnd), arr[i]);
    curMin = std::min(std::min(maxEnd, minEnd), arr[i]);
    max = std::max(curMax, max);
  }
  return max;
}

int main(void)
{
  vector<double> v = { -2.5, 4, 0, 3, 0.5, 8, -1 };
  std::cout << SubArrayMaxMutiple(v) << std::endl;

  return 0;
}

