#include <iostream>
#include <vector>
#include <unordered_map>

using std::vector;
using std::unordered_map;

unordered_map<int, int> TwoOddNums(const vector<int>& v)
{
  if (v.empty())
  {
    return unordered_map<int, int>();
  }
  int e0 = 0;
  for (int i = 0; i < v.size(); ++i)
  {
    e0 ^= v[i];
  }
  //n & (~n + 1)剩下左到右的第一个1 其余全部为1
  int e1 = e0 & (~e0 + 1);
  int e2 = 0;
  for (int i = 0; i < v.size(); ++i)
  {
    if ((v[i] & e1) != 0)
    {
      e2 ^= v[i];
    }
  }
  unordered_map<int, int> res;
  res[e0 ^ e2] = 0;
  res[e2] = 0;
  for (int i = 0; i < v.size(); ++i)
  {
    if (res.find(v[i]) != res.end())
    {
      ++res[v[i]];
    }
  }
  return res;
}

void PrintVector(const vector<int>& v)
{
  std::cout << "vector: " << std::endl;
  for (int i = 0; i < v.size(); ++i)
  {
    std::cout << v[i] << " ";
  }
  std::cout << std::endl;
}

void PrintMap(const unordered_map<int, int>& m)
{
  std::cout << "map:" << std::endl;
  for (auto it = m.begin(); it != m.end(); ++it)
  {
    std::cout << it->first << "->" << it->second << std::endl;
  }
}

int main(void)
{
  vector<int> v = {2, 4, 3, 6, 3, 2, 5, 5, 4, 4, 6, 6};
  unordered_map<int, int> res = TwoOddNums(v);
  PrintMap(res);

  return 0;
}
