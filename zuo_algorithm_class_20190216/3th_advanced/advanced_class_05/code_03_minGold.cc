#include <iostream>
#include <vector>
#include <algorithm>

using std::vector;

int MaxLeftMost(const vector<int>& sortedKnights, int dragon)
{
  int l = 0;
  int r = sortedKnights.size() - 1;
  int target = -1;
  while (l <= r)
  {
    int mid = (l + r) / 2;
    if (sortedKnights[mid] < dragon)
    {
      l = mid + 1;
    }
    else
    {
      target = mid;
      r = mid - 1;
    }
  }
  return target == -1 ? 0x7fffffff : sortedKnights[target];
}

int MinGold1(vector<int>& knights, vector<int>& dragons)
{
  if (knights.empty() || dragons.empty())
  {
    return 0;
  }
  std::sort(knights.begin(), knights.end());
  int res = 0;
  for (int dragon : dragons)
  {
    int gold = MaxLeftMost(knights, dragon);
    if (gold == 0x7fffffff)
    {
      return 0x7fffffff;
    }
    res += gold;
  }
  return res;
}

//不是进阶题目的堆解法 时间复杂度也是n*log(n)
int MidGold2(vector<int>& knights, vector<int>& dragons)
{
  if (knights.empty() || dragons.empty())
  {
    return 0;
  }
  for (int i = 0; i < knights.size(); ++i)
  {
    //HeapInsert(knights, i);
  }
  for (int i = 0; i < dragons.size(); ++i)
  {
    //HeapInsert(dragons, i);
  }
  int res = 0;
  while (!dragons.empty() && dragons.empty())
  {
    while (!knights.empty() && knights.front() >= dragons.front())
    {
      res += knights.front();
      std::swap(dragons.front(), dragons.back());
      dragons.pop_back();
      //Heapify(dragons, 0, dragons.size());
    }
    if (!knights.empty())
    {
      std::swap(knights.front(), knights.back());
      knights.pop_back();
      //Heapify(knights, 0, knights.size());
    }
  }
  return res;
}

int main(void)
{
  vector<int> knights2 = {2, 10, 5};
  vector<int> dragons2 = { 3, 8, 6 };
  std::cout << StageMinGold(dragons2, knights2) << std::endl;
  std::cout << StageMinGoldDp(dragons2, knights2) << std::endl;
  
  return 0;
}
