#include <iostream>
#include <vector>

using std::vector;

bool g_InvaildInput = false;
int GreaterSumOfSubArray(const vector<int>& numbers)
{
  g_InvaildInput = false;
  if (numbers.empty())
  {
    g_InvaildInput = true;
    return 0;
  }
  int sum = 0x80000000;
  int curSum = 0;
  for (int number : numbers)
  {
    if (curSum <= 0)
    {
      curSum = number;
    }
    else
    {
      curSum += number;
    }
    sum = std::max(sum, curSum);
  }
  return sum;
}

int Process(const vector<int>& numbers, int left, int right)
{
  if (left >= numbers.size() || right <= 0)
  {
    return 0;
  }
  if (left == right)
  {
    return numbers[left];
  }
  int sum1 = Process(numbers, left, right - 1);
  int sum2 = Process(numbers, left + 1, right);
  int sum3 = Process(numbers, left + 1, right - 1);
  int sum4 = Process(numbers, left + 1, right - 1) + numbers[left] + numbers[right];
  return std::max(std::max(sum1, sum2), std::max(sum3, sum4));
}

int GreaterSumOfSubArray2(const vector<int>& numbers)
{
  g_InvaildInput = false;
  if (numbers.empty())
  {
    g_InvaildInput = true;
    return 0;
  }
  return Process(numbers, 0, numbers.size());
}

int main(void)
{
  vector<int> numbers = {1, -2, 3, 10, -4, 7, 2, -5};
  std::cout << GreaterSumOfSubArray(numbers) << std::endl;
  std::cout << GreaterSumOfSubArray2(numbers) << std::endl;

  return 0;
}
