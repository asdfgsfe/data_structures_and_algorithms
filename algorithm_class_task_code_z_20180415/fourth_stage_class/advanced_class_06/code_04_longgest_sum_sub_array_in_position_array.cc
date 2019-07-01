#include <iostream>
#include <vector>

using std::vector;

int LonggestSumSubArrayLenInPositionArray(const vector<int>& arr, int aim)
{
  if (arr.empty() || aim < 1)
  {
    return 0;
  }
  int sum = arr[0];
  int l = 0;
  int r = 0;
  int maxLen = 0;
  while (r < arr.size())
  {
    if (sum == aim)
    {
      maxLen = std::max(maxLen, r - l + 1);
      sum -= arr[l++];
    }
    else if (sum < aim)
    {
      ++r;
      if (r < arr.size())
      {
        sum += arr[r];
      }
    }
    else
    {
      sum -= arr[l++];
    }
  }
  return maxLen;
}

//you bug
int LonggestSumSubArrayLenInPositionArray2(const vector<int>& arr, int aim)
{
  if (arr.empty() || aim < 1)
  {
    return 0;
  }
  int l = 0;
  int r = 0;
  int sum = 0;
  int maxLen = 0;
  while (r <= arr.size())
  {
    if (sum == aim)
    {
      maxLen = std::max(maxLen, r - l);
      sum -= arr[l++];
    }
    else if (sum < aim)
    {
      sum += arr[r++];
    }
    else
    {
      sum -= arr[l++];
    }
  }
  return maxLen;
}

int main(void)
{
  vector<int> arr = {3, 2, 1, 5, 1, 1, 1, 1, 1};
  int aim = 6;
  std::cout << LonggestSumSubArrayLenInPositionArray(arr, aim) << std::endl;
  std::cout << LonggestSumSubArrayLenInPositionArray2(arr, aim) << std::endl;

  return 0;
}
