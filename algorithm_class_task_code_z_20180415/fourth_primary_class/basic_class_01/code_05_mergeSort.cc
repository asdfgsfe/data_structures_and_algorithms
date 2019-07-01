#include <iostream>
#include <vector>

using std::vector;

void Merge(vector<int>& v, int l, int m, int r)
{
  vector<int> help(r - l + 1);
  int i = 0;
  int ls = l;
  int rs = m + 1;
  while (ls <= m && rs <= r)
  {
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
}

void mSort(vector<int>& v, int l, int r)
{
  if (l == r)
  {
    return;
  }
  int mid = l + ((r - l) >> 1);
  mSort(v, l, mid);
  mSort(v, mid + 1, r);
  Merge(v, l, mid, r);
}

void MergeSort(vector<int>& v)
{
  if (v.empty())
  {
    return;
  }
  mSort(v, 0, v.size() - 1);
}

void PrintVector(const vector<int>& v)
{
  for (int i : v)
  {
    std::cout << i << " ";
  }
  std::cout << std::endl;
}

int main(void)
{
  vector<int> test = {5, 3, 4, 1, 2};
  MergeSort(test);
  PrintVector(test);

  return 0;
}
