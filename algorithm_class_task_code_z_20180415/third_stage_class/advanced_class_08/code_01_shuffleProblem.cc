#include <iostream>
#include <vector>
#include <string>

using std::vector;
using std::string;

template<typename T>
void PrintVector(const vector<T>& v)
{
  std::cout << "arr: " << std::endl;
  for (int i = 0; i < v.size(); ++i)
  {
    std::cout << v[i] << " ";
  }
  std::cout << std::endl;
}


template<typename T>
void Reverse(vector<T>& arr, int l, int r)
{
  while (l < r)
  {
    T tmp = arr[l];
    arr[l++] = arr[r];
    arr[r--] = tmp;
  }
}

template<typename T>
void Rotate(vector<T>& arr, int l, int m, int r)
{
  Reverse(arr, l, m);
  Reverse(arr, m + 1, r);
  Reverse(arr, l, r);
}

template<typename T>
void Cycles(vector<T>& arr, int base, int bloom, int k)
{
  //k表示有几个触发点 k从1开始
  for (int i = 0, trigger = 1; i < k; ++i, trigger *= 3)
  {
    int next = (2 * trigger) % bloom;
    int cur = next;
    T record = arr[next + base];
    arr[next + base] = arr[trigger + base];
    while (cur != trigger)
    {
      next = (2 * cur) % bloom;
      T tmp = arr[next + base];
      arr[next + base] = record;
      cur = next;
      record = tmp;
    }
  }
}

template<typename T>
void ShuffleProcess(vector<T>& arr, int l, int r)
{
  while (r - l + 1 > 0)
  {
    int lenAndOne = r - l + 2;
    int bloom = 3;
    int k = 1;
    while (bloom <= lenAndOne / 3)
    {
      bloom *= 3;
      ++k;
    }
    int mid = (r + l) / 2;
    int m =(bloom - 1) / 2; //等价于bloom / 2
    //[l+m, mid) [mid, mid + m) 交换
    Rotate(arr, l + m, mid, mid + m);
    //k的目的是为了找齐所有的触发点
    Cycles(arr, l - 1, bloom, k);
    //l向右移动bloom - 1的位置
    l = l + (bloom - 1);
  }
}

template <typename T>
void Shuffle(vector<T>& arr)
{
  if (!arr.empty() && (arr.size() & 1) == 0)
  {
    ShuffleProcess(arr, 0, arr.size() - 1);
  }
}


int main(void)
{
  vector<string> arr = {"l1", "l2", "l3", "l4", "l5", "r1", "r2", "r3", "r4", "r5"};
  Shuffle(arr);
  PrintVector(arr);

  vector<int> arr1 = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
  Shuffle(arr1);
  PrintVector(arr1);

  return 0;
}
