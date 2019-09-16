#include <iostream>
#include <vector>
#include <set>

using std::vector;
using std::set;

//找出所有重复的数字
set<int> DuplicateNumbers(vector<int>& numbers)
{
  if (numbers.size() < 2)
  {
    return set<int>();
  }
  for (int number : numbers)
  {
    if (number < 0 || number > numbers.size() - 1)
    {
      return set<int>();
    }
  }
  set<int> result;
  for (int i = 0; i < numbers.size(); ++i)
  {
    while (numbers[i] != i)
    {
      if (numbers[i] == numbers[numbers[i]])
      {
        result.insert(numbers[i]);
        break;
      }
      std::swap(numbers[i], numbers[numbers[i]]);
    }
  }
  return result;
}

void PrintSet(const set<int>& values)
{
  for (int val : values)
  {
    std::cout << val << " ";
  }
  std::cout << std::endl;
}

int main(void)
{
  vector<int> numbers = {2, 3, 1, 0, 2, 5, 3, 3, 3, 3, 3};
  PrintSet(DuplicateNumbers(numbers));

  return 0;
}
