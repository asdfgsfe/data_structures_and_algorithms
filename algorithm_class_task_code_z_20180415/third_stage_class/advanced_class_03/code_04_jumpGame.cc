#include <iostream>
#include <vector>

using std::vector;

int Jump(const vector<int>& steps)
{
  if (steps.empty())
  {
    return 0;
  }
  int cur = 0;
  int next = 0;
  int jump = 0;
  for (int i = 0; i < steps.size(); ++i)
  {
    if (cur < i)
    {
      ++jump;
      cur = next;
    }
    next = std::max(next, i + steps[i]);
  }
  return jump;
}

int main(void)
{
  vector<int> steps = {3, 2, 3, 1, 1, 4};
  std::cout << Jump(steps) << std::endl;

  return 0;
}

