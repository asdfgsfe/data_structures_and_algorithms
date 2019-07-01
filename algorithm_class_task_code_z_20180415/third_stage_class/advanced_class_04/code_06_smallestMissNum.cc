#include <iostream>
#include <vector>

using std::vector;

int SmallestMissNum(vector<int>& arr)
{ 
  int l = 0;
  int r = arr.size();
  while (l != r)
  {
    if (arr[l] == l+1)
    {
      ++l;
    }
    else if (arr[l] <= l || arr[l] > r || arr[arr[l] - 1] == arr[l])
    {
      arr[l] = arr[--r];
    }
    else
    {
      std::swap(arr[l], arr[arr[l] - 1]);
    }
  }
  return r+1;
}

int main(void)
{
  vector<int> arr = { -1, 0, 2, 1, 3, 5 };
  std::cout << SmallestMissNum(arr) << std::endl;
  return 0;
}
