#include <iostream>
#include <vector>

using std::vector;

int Process(const vector<int>& v, int l, int r)
{
  if (l == r)
  {
    return v[l];
  }
  //int mid = l + ((r - l) << 2);
  int mid = (r + l) / 2;
  int maxLeft = Process(v, l, mid);
  int maxRight = Process(v, mid+1, r);
  return std::max(maxLeft, maxRight);
}

int MaxVal(const vector<int>& v)
{
  return Process(v, 0, v.size() - 1);  
}

int main(void)
{
  vector<int> test = {4, 2, 3, 1};
  std::cout << MaxVal(test) << std::endl;

  return 0;
}
