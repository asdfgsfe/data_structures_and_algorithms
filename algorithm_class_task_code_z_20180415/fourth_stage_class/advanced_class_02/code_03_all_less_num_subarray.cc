#include <iostream>
#include <vector>
#include <deque>

using std::vector;
using std::deque;

int AllLessNumSubarray(const vector<int>& arr, int num)
{
  if (arr.empty())
  {
    return 0;
  }
  deque<int> qmin;
  deque<int> qmax;
  int l = 0;
  int r = 0;
  int res = 0;
  while (l < arr.size())
  {
    while (r < arr.size())
    {
      while (!qmax.empty() && arr[qmax.back()] <= arr[r])
      {
        qmax.pop_back();
      }
      qmax.push_back(r);
      while (!qmin.empty() && arr[qmin.back()] >= arr[r])
      {
        qmin.pop_back();
      }
      qmin.push_back(r);
      if (arr[qmax.front()] - arr[qmin.front()] > num)
      {
        break;
      }
      ++r;
    }
    if (qmax.front() == l)
    {
      qmax.pop_front();
    }
    if (qmin.front() == l)
    {
      qmin.pop_front();
    }
    res += r - l;
    ++l;
  }
  return res;
}

int main(void)
{
  vector<int> v = { 4, 3, 5, 4, 3, 3, 6, 7 };
  std::cout << AllLessNumSubarray(v, 3) << std::endl;
  
  return 0;
}
