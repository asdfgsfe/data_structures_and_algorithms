#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>

int LessMoney(std::vector<int>& bullionPool)
{
  if (bullionPool.empty())
  {
    return -1;
  }
  if (bullionPool.size() == 1)
  {
    return bullionPool[0];
  }

  std::make_heap(bullionPool.begin(), bullionPool.end(), std::greater<int>());
  
  int money = 0;
  while (bullionPool.size() != 1)
  {
    int bullion = bullionPool[0];
    std::pop_heap(bullionPool.begin(), bullionPool.end(), std::greater<int>());
    bullionPool.pop_back();

    bullion += bullionPool[0];
    std::pop_heap(bullionPool.begin(), bullionPool.end(), std::greater<int>());
    bullionPool.pop_back();

    bullionPool.push_back(bullion);
    std::push_heap(bullionPool.begin(), bullionPool.end(), std::greater<int>());

    money += bullion;
  }
  return money; 
}

void PrintVector(const std::vector<int>& v)
{
  std::vector<int>::const_iterator it = v.begin();
  std::cout << "[";
  while (it != v.end())
  {
    std::cout << *it << " " ;
    ++it;
  }
  std::cout << "]" << std::endl;
}

int main(void)
{
  std::vector<int> v;
  for (int i = 6; i < 10; ++i)
  {
    v.push_back(i);
  }
  PrintVector(v);
  std::cout << LessMoney(v) << std::endl;  

  v.clear();
  for (int i = 1; i < 4; ++i)
  {
    v.push_back(i * 10);
  }
  std::cout << LessMoney(v) << std::endl;

  int a[] = { 3, 5, 2, 7, 0, 1, 6, 4 };
  std::vector<int> v1(a, a + 8);
  PrintVector(v1);
  std::cout << LessMoney(v1) << std::endl;

  return 0;
}
