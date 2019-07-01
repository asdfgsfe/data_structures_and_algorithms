#include <iostream>
#include <vector>

using std::vector;

int Bucket(long num, long min, long max, long len)
{
  return ((num - min) * len) / (max - min);
}

int MaxGap(const vector<int>& v)
{
  if (v.empty())
  {
    return 0;
  }
  int min = v[0];
  int max = v[0];
  for (int i : v)
  {
    min = std::min(min, i);
    max = std::max(max, i);
  }
  if (min == max)
  {
    return 0;
  }
  vector<bool> hasNum(v.size() + 1, false);
  vector<int> maxs(v.size() + 1);
  vector<int> mins(v.size() + 1);
  for (int i : v)
  {
    int bid = Bucket(i, min, max, v.size());
    mins[bid] = hasNum[bid] ? std::min(mins[bid], i) : i;
    maxs[bid] = hasNum[bid] ? std::max(maxs[bid], i) : i;
    hasNum[bid] = true;
  }
  int maxGap = 0;
  int last = maxs[0];
  for (int i = 1; i < hasNum.size(); ++i)
  {
    if (hasNum[i])
    {
      maxGap = std::max(maxGap, mins[i] - last);
      last = maxs[i];
    }
  }
  return maxGap;
}

int main(void)
{
  vector<int> v = {1, 2, 4, 5, 6};
  std::cout << MaxGap(v) << std::endl;

  return 0;
}
