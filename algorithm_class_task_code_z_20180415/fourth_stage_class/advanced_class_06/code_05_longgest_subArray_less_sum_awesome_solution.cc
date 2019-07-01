#include <iostream>
#include <vector>

using std::vector;

int MaxLengthAwesome(const vector<int>& arr, int aim)
{
  if (arr.empty())
  {
    return 0;
  }
  vector<int> sums(arr.size());
  vector<int> ends(arr.size());
  sums[arr.size() - 1] = arr.back();
  ends[arr.size() - 1] = arr.size() - 1;//已这个id结尾的情况下累加和是多少
  for (int i = arr.size() - 2; i >= 0; --i)
  {
    if (sums[i + 1] < 0)
    {
      sums[i] = arr[i] + sums[i + 1];
      ends[i] = ends[i + 1];
    }
    else
    {
      sums[i] = arr[i];
      ends[i] = i;
    }
  }

  int r = 0;
  int res = 0;
  int sum = 0;
  for (int l = 0; l < arr.size(); ++l)
  {
    while (r < arr.size() && sum + sums[r] <= aim)
    {
      sum += sums[r];
      r = ends[r] + 1;
    }
    sum -= r > l ? arr[l] : 0;
    res = std::max(res, r - l);
    r = std::max(r, l + 1);
  }
  return res;
}

int main(void)
{
  vector<int> arr = {1, -3, 4, -5, 7, 3, -6, 9};
  int aim = 6;
  std::cout << MaxLengthAwesome(arr, aim) << std::endl;

  return 0;
}
