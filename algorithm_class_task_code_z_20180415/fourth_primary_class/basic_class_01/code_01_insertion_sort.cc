#include <iostream>
#include <vector>

using std::vector;

void InsertionSort(vector<int>& v)
{
  if (v.empty() || v.size() < 2)
  {
    return;
  }

  for (int p = 1; p < v.size(); ++p)
  {
    for (int i = p - 1; i >= 0 && v[i] > v[i+1]; --i)
    {
      std::swap(v[i], v[i+1]);
    }
  }
}

void PrintVector(const vector<int>& v)
{
  std::cout << " vector: " << std::endl;
  for (int i : v)
  {
    std::cout << i << " ";
  }
  std::cout << std::endl;
}

int main(void)
{
  vector<int> test = {1, 3, 6, 4};
  InsertionSort(test);
  PrintVector(test);

  return 0;
}
