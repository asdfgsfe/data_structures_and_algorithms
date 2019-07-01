#include <iostream>
#include <vector>

using std::vector;

vector<int> KSysNumFromNum(int val, int k)
{
  vector<int> kSysNum(32, 0);
  int id = 0;
  while (val != 0)
  {
    kSysNum[id++] = val % k;
    val /= k;
  }
  return kSysNum;
}

int NumFromKSysNum(const vector<int>& e0, int k)
{
  int num = 0;
  for (int i = e0.size() - 1; i >= 0; --i)
  {
    num = num * k + e0[i];
  }
  return num;
}

void SetExclusiveOr(vector<int>& e0, int val, int k)
{
  vector<int> curKSysNum = KSysNumFromNum(val, k);
  for (int i = 0; i < e0.size(); ++i)
  {
    e0[i] = (curKSysNum[i] + e0[i]) % k;
  }
}

int OnceNum(const vector<int>& v, int k)
{
  if (v.empty() || k < 0)
  {
    return 0;
  }
  vector<int> e0(32, 0);
  for (int i = 0; i < v.size(); ++i)
  {
    SetExclusiveOr(e0, v[i], k);
  }
  return NumFromKSysNum(e0, k);
}

int main(void)
{
  vector<int> test1 = { 1, 1, 1, 2, 6, 6, 2, 2, 10, 10, 10, 12, 12, 12, 6, 9 };
  std::cout << OnceNum(test1, 3) << std::endl;

  vector<int> test2 = { -1, -1, -1, -1, -1, 2, 2, 2, 4, 2, 2 };
  std::cout << OnceNum(test2, 5) << std::endl;

  return 0;
}
