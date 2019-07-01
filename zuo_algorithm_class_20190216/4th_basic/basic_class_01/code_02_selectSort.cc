#include <iostream>
#include <vector>

using std::vector;

void SelectSort(vector<int>& a)
{
  if (a.size() < 2)
  {
    return;
  }
  for (int i = 0; i < a.size(); ++i)
  {
    for (int j = i + 1; j < a.size(); ++j)
    {
      if (a[j] < a[i])
      {
        std::swap(a[i], a[j]);
      }
    }
  }
}

void PrintVector(const vector<int>& v)
{
  for(int i : v)
  {
    std::cout << i << " ";
  }
  std::cout << std::endl;
}

int main(void)
{
  vector<int> test = {4, 2, 5, 1, 3};
  SelectSort(test);
  PrintVector(test);

  return 0;
}
