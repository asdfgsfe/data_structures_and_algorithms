#include <iostream>
#include <vector>

using std::vector;

void SelectSort(vector<int>& v)
{
  if (v.empty() || v.size() < 2)
  {
    return;
  }

  for (int i = 0; i < v.size(); ++i)
  {
    int minId = i;
    for (int j = i + 1; j < v.size(); ++j)
    {
      minId = v[j] < v[minId] ? j : minId;
    }
    std::swap(v[i], v[minId]);
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
