#include <iostream>
#include <vector>

using std::vector;

//类似于找零钱有多少种方法
//去尝试 对于数组中的每一个值可以选择要他与不要他 去累加这个这个aim
//如果不要当前值 尝试其他的值去累加是否可以累加出来
//如果必须要当前值 在这个基础上在去选择数据中的其他值去累加

bool SumProcess(const vector<int>& numbers, int index, int sum, int aim)
{
  if (sum == aim)
  {
    return true;
  }
  if (index == numbers.size())
  {
    return false;
  }
  return SumProcess(numbers, index + 1, sum, aim) || SumProcess(numbers, index + 1, sum + numbers[index], aim);
}

bool IsSumEqualAim(const vector<int>& numbers, int aim)
{
  if (numbers.empty())
  {
    return false;
  }
  return SumProcess(numbers, 0, 0, aim);
}

bool SumProcess2(const vector<int>& numbers, int index, int aim)
{
  if (aim == 0)
  {
    return true;
  }
  if (index == numbers.size())
  {
    return false;
  }
  return SumProcess2(numbers, index + 1, aim) || SumProcess2(numbers, index + 1, aim - numbers[index]);
}

bool IsSumEqualAim2(const vector<int>& numbers, int aim)
{
  if (numbers.empty())
  {
    return false;
  }
  return SumProcess2(numbers, 0, aim);
}



bool IsSumEqualAim3(const vector<int>& numbers, int aim)
{
  if (numbers.empty())
  {
    return false;
  }
  vector<vector<bool>> dp(numbers.size() + 1, vector<bool>(aim + 1, false));
  for (int i = 0; i < dp.size(); ++i)
  {
    dp[i][0] = true;
  }
  for (int i = dp.size() - 2; i >= 0; --i)
  {
    for (int j = 1; j < dp[0].size(); ++j)
    {
      //j == aim -> aim - numbers[i] == j - numbers[i]
      if (j - numbers[i] >= 0)
      {
        dp[i][j] = dp[i + 1][j] || dp[i + 1][j - numbers[i]];
      }
    }
  }
  return dp[0][aim];
}

int main(void)
{
  vector<int> arr = {1, 4, 8};
  int aim = 12;
  std::cout << IsSumEqualAim(arr, aim) << std::endl;
  std::cout << IsSumEqualAim2(arr, aim) << std::endl;
  std::cout << IsSumEqualAim3(arr, aim) << std::endl;

  return 0;
}

