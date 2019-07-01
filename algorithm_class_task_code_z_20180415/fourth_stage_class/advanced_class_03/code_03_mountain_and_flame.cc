#include <iostream>
#include <vector>
#include <stack>

using std::vector;
using std::stack;

struct Pair
{
  int val;
  int times;
  Pair(int v)
    : val(v), times(1)
  {}
};

long InternalSum(int n)
{
  return n == 1L ? 0L : (long)n * (long)(n-1) / 2L;
}

int NextIndex(int size, int i)
{
  return i < (size - 1) ? (i + 1) : 0;
}

long Communications(const vector<int>& mountains)
{
  if (mountains.empty() || mountains.size() == 1)
  {
    return 0;
  }
  int maxIndex = 0;
  for (int i = 0; i < mountains.size(); ++i)
  {
    maxIndex = mountains[maxIndex] < mountains[i] ? i : maxIndex;
  }
  int index = NextIndex(mountains.size(), maxIndex);
  stack<Pair> pairs;
  pairs.push(Pair(mountains[maxIndex]));
  long res = 0;
  while (index != maxIndex)
  {
    while (!pairs.empty() && pairs.top().val < mountains[index])
    {
      int times = pairs.top().times;
      pairs.pop();
      res += InternalSum(times) + 2 * times;
      //此处栈不肯能为空 因为是从最大值开始的
      //res += InternalSum(times);    
      //res += pairs.empty() ? 0 : times;
    }
    if (!pairs.empty() && pairs.top().val == mountains[index])
    {
      ++pairs.top().times;
    }
    else
    {
      pairs.push(Pair(mountains[index]));
    }
    index = NextIndex(mountains.size(), index);
  }
  while (!pairs.empty())
  {
    int times = pairs.top().times;
    pairs.pop();
    res += InternalSum(times);
    if (!pairs.empty())
    {
      res += times;
      if (pairs.size() > 1)
      {
        res += times;
      }
      else
      {
        res += pairs.top().times > 1 ? times : 0;
      }
    }
  }
  return res;
}

int main(void)
{
  vector<int> mountains = {1, 2, 4, 5, 3, 3};
  std::cout << Communications(mountains) << std::endl;
  return 0;
}
