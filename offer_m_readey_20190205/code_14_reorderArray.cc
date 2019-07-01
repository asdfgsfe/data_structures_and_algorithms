#include <iostream>
#include <vector>

using std::vector;

void ReorderArrayOddEven(vector<int>& arr)
{
  if (arr.size() < 2)
  {
    return;
  }
  int left = 0;
  int right = arr.size() - 1;
  while (left < right)
  {
    while (left < right && (arr[left++] & 0x1) == 1)
    {}
    while (left < right && (arr[right--] & 0x1) == 0)
    {}
    if (left < right)
    {
      std::swap(arr[left], arr[right]);
    }
  }
}

void ReorderArrayOddEven2(vector<int>& arr, bool (*func)(int))
{
  if (arr.size() < 2)
  {
    return;
  }
  int left = 0;
  int right = arr.size() - 1;
  while (left < right)
  {
    while (left < right && func(arr[left]))
    {
      ++left;
    }
    while (left < right && !func(arr[right]))
    {
      --right;
    }
    if (left < right)
    {
      std::swap(left, right);
    }
  }
}

bool IsOdd(int num)
{
  return (num & 0x1) == 1;
}

void ReorderArrayOddEven3(vector<int>& arr, bool (*func)(int))
{
  if (arr.size() < 2 || func == nullptr)
  {
    return;
  }
  for (int p = 1; p < arr.size(); ++p)
  {
    for (int i = p; i > 0 && !func(arr[i - 1]) && func(arr[i]); --i)
    {
      std::swap(arr[i], arr[i - 1]);
    }
  }
}

void PrintVector(const vector<int>& v)
{
  for (int val : v)
  {
    std::cout << val << " ";
  }
  std::cout << std::endl;
}
int main(void)
{
  vector<int> arr = {1, 2, 3, 4, 5};
  //ReorderArrayOddEven(arr);
  ReorderArrayOddEven3(arr, IsOdd);
  PrintVector(arr);

  return 0;
}
