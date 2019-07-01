#include <iostream>
#include <vector>
#include <unordered_map>

using std::vector;
using std::unordered_map;

int LonggestSumSubArrayLength(const vector<int>& numbers, int aim)
{
  if (numbers.empty())
  {
    return 0;
  }
  unordered_map<int, int> sumToIds;
  sumToIds[0] = -1;
  int maxLen = 0;
  int curSum = 0;
  for (int i = 0; i < numbers.size(); ++i)
  {
    curSum += numbers[i];
    auto it = sumToIds.find(curSum - aim);
    if (it != sumToIds.end())
    {
      maxLen = std::max(maxLen, i - it->second);
    }
    if (sumToIds.find(curSum) == sumToIds.end())
    {
      sumToIds[curSum] = i;
    }
  }
  return maxLen;
}

void PrintVector(const vector<int>& numbers)
{
  for (int number : numbers)
  {
    std::cout << number << " ";
  }
  std::cout << std::endl;
}

//book p103
int main(void)
{
  vector<int> numbers = {7, 3, 2, 1, 1, 7, 7, 7};
  std::cout << LonggestSumSubArrayLength(numbers, 7) << std::endl;

  return 0;
}
