#include <iostream>
#include <vector>

using std::vector;

void Paritition1(vector<int>& v, int num)
{
  if (v.empty())
  {
    return;
  }
  int less = -1;
  int curr = 0;
  while(curr < v.size())
  {
    if (v[curr] > num)
    {
      ++curr;
    }
    else
    {
      std::swap(v[curr++], v[++less]);
    }  
  }
}

void Paritition2(vector<int>& v, int l, int r, int num)
{
  if (v.empty())
  {
    return;
  }
  int less = l - 1;
  int more = r;
  while (l < more)
  {
    if (v[l] == num)
    {
      ++l;
    }
    else if (v[l] < num)
    {
      std::swap(v[l++], v[++less]);
    }
    else
    {
      std::swap(v[l], v[--more]);
    }
  }
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
  vector<int> test = {8, 4, 3, 0, 6, 9, 1};
  Paritition1(test, 5);
  PrintVector(test);

  test = {5, 5, 8, 4, 3, 0, 6, 9, 1};
  Paritition2(test, 0, test.size(), 5);
  PrintVector(test);
  return 0;
}
