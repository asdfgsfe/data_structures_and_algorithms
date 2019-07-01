#include <iostream>
#include <vector>

using std::vector;

void BubbleSort(vector<int>& v)
{
  if (v.empty() || v.size() < 2)
  {
    return;
  }

  for (int i = v.size() - 1; i > 0; --i)
  {
    for (int j = 0; j < i; ++j)
    {
      if (v[j] > v[j+1])
      {
        std::swap(v[j], v[j+1]);
      }
    }
  }
}

void PrintVector(const vector<int>& v)
{
  for (int i = 0; i < v.size(); ++i)
  {
    std::cout << v[i] << " ";
  }
  std::cout << std::endl;
}

int main(void)
{
  vector<int> test = {4, 2, 5, 1, 3};
  BubbleSort(test);
  PrintVector(test);

  return 0;
}
