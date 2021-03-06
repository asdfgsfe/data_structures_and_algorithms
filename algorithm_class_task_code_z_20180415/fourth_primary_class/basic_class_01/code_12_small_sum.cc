#include <iostream>
#include <vector>

using std::vector;

int Merge(vector<int>& v, int l, int m, int r)
{
  vector<int> help(r - l + 1);
  int i = 0;
  int ls = l;
  int rs = m + 1;
  int res = 0;
  while (ls <= m && rs <= r)
  {
    res += v[ls] < v[rs] ? (r - rs + 1) * v[ls] : 0;
    help[i++] = v[ls] < v[rs] ? v[ls++] : v[rs++];
  }
  while (ls <= m)
  {
    help[i++] = v[ls++];
  }
  while (rs <= r)
  {
    help[i++] = v[rs++];
  }
  for (int i = 0; i < help.size(); ++i)
  {
    v[l + i] = help[i];
  }
  return res;
}

int Process(vector<int>& v, int l, int r)
{
  if (l == r)
  {
    return 0;
  }
  int mid = l + ((r - l) >> 1);
  return Process(v, l, mid) + Process(v, mid + 1, r) + Merge(v, l, mid, r);
}

int SmallSum(vector<int>& v)
{
  if (v.empty())
  {
    return 0;
  }

  return Process(v, 0, v.size() - 1);
}

int main(void)
{
  vector<int> test = {1, 3, 4, 2, 5};
  std::cout << SmallSum(test) << std::endl;
  
  return 0;
}
