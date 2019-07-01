#include <iostream>
#include <vector>

using std::vector;

int OneOddNumTimes1(const vector<int>& v)
{
  if (v.empty())
  {
    return 0;
  }
  int e = 0;
  for (int i = 0; i < v.size(); ++i)
  {
    e ^= v[i];
  }
  int times = 0;
  for (int i = 0; i < v.size(); ++i)
  {
    times = v[i] == e ? ++times : times;
  }
  return times;
}

int main(void)
{
  vector<int> v = {1, 1, 1, 2, 2, 3, 3, 4, 4, 5, 5};
  std::cout << OneOddNumTimes1(v) << std::endl;
  std::cout << OneOddNumTimes2(v) << std::endl;

  return 0;
}
