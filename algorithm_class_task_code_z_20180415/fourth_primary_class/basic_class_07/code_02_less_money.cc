#include <iostream>
#include <vector>
#include <algorithm>

using std::vector;

void PrintVetor(const vector<int>& v)
{
  std::cout << "vector:" << std::endl;
  for (auto i : v)
  {
    std::cout << i << " ";
  }
  std::cout << std::endl;
}

int LessMoney1(vector<int>& v)
{
  if (v.empty())
  {
    return 0;
  }
  std::make_heap(v.begin(), v.end(), std::greater<int>());
  while (v.size() > 1)
  {
    int tmpMoney = 0;
    for (int i = 0; i < 2; ++i)
    {
      std::pop_heap(v.begin(), v.end(), std::greater<int>());
      tmpMoney += v.back();
      v.pop_back();
    }
    v.push_back(tmpMoney);
    std::push_heap(v.begin(), v.end(), std::greater<int>());
  }
  return v.back();
}

int LessMoney2(const vector<int>& v)
{
  if (v.empty())
  {
    return 0;
  }
  vector<int> minHeap;
  for (auto val : v)
  {
    minHeap.push_back(val);
    std::push_heap(minHeap.begin(), minHeap.end(), std::greater<int>());
  }
  while (minHeap.size() > 1)
  {
    int tmpMoney = 0;
    for (int i = 0; i < 2; ++i)
    {
      std::pop_heap(minHeap.begin(), minHeap.end(), std::greater<int>());
      tmpMoney += minHeap.back();
      minHeap.pop_back();
    }
    minHeap.push_back(tmpMoney);
    std::push_heap(minHeap.begin(), minHeap.end(), std::greater<int>());
  }
  return minHeap.back();
}

int main(void)
{
  vector<int> v = { 6, 7, 8, 9 };
  std::cout << LessMoney1(v) << std::endl;
  vector<int> v1 = { 6, 7, 8, 9 };
  std::cout << LessMoney2(v1) << std::endl;

  vector<int> v2 = {10, 20, 30};
  std::cout << LessMoney1(v2) << std::endl;
  vector<int> v3 = {10, 20, 30};
  std::cout << LessMoney2(v3) << std::endl;

  return 0;
}
