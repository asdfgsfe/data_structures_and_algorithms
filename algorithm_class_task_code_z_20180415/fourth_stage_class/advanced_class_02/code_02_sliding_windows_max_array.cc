#include <iostream>
#include <vector>
#include <deque>

using std::vector;
using std::deque;

void PrintVector(const vector<int>& v)
{
  std::cout << "vector:" << std::endl;
  for (auto i : v)
  {
    std::cout << i << " ";
  }
  std::cout << std::endl;
}

vector<int> SlidingWindowsMaxArray(const vector<int>& v, int w)
{
  if (v.empty() || w < 1 || v.size() < w)
  {
    return vector<int>();
  }  
  deque<int> qmax;
  vector<int> res;
  for (int i = 0; i < v.size(); ++i)
  {
    while (!qmax.empty() && v[qmax.back()] <= v[i])
    {
      qmax.pop_back();
    }
    qmax.push_back(i);
    if (qmax.front() == i - w)
    {
      qmax.pop_front();
    }
    if (i >= w - 1)
    {
      res.push_back(v[qmax.front()]);
    }
  }
  return res;
}

int main(void)
{
  vector<int> v =  { 4, 3, 5, 4, 3, 3, 6, 7 };
  int w = 3;
  PrintVector(SlidingWindowsMaxArray(v, w));
  return 0;
}
