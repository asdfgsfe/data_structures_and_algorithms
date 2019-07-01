#include <iostream>
#include <vector>

using std::vector;

int GetNeedNum(const vector<int>& v, int limit)
{
  int res = 1;
  int stepNum = 0;
  for (int i : v)
  {
    if (i > limit)
    {
      return 0x7fffffff;
    }
    stepNum += i;
    if (stepNum > limit)
    {
      ++res;
      stepNum = i;
    }
  }
  return res;
}

int MinTime(const vector<int>& taskTime, int painterNums)
{
  if (taskTime.empty() || painterNums < 1)
  {
    return -1;
  }
  
  if (taskTime.size() < painterNums)
  {
    int max = 0x8fffffff;
    for (int i : taskTime)
    {
      max = std::max(max, i);
    }
    return max;
  }
  int minSum = 0;
  int maxSum = 0;
  for (int i : taskTime)
  {
    maxSum += i;
  }
  while (minSum != maxSum - 1)
  {
    int mid = (maxSum + minSum) / 2;
    if (GetNeedNum(taskTime, mid) > painterNums)
    {
      minSum = mid;
    }
    else
    {
      maxSum = mid;
    }
  }
  return maxSum;
}

int main(void)
{
  vector<int> test = {3, 1, 4};
  int painterNums = 2;
  std::cout << MinTime(test, painterNums) << std::endl;

  test = {1, 1, 1, 4, 3};
  painterNums = 3;
  std::cout << MinTime(test, painterNums) << std::endl;

  return 0;
}
