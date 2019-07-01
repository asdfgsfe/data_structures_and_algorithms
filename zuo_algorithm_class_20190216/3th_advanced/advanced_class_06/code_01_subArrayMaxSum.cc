#include <iostream>
#include <vector>

using std::vector;

int SubArrayMaxSum(const vector<int>& numbers)
{
  if (numbers.empty())
  {
    return 0;
  }
  int cur = 0;
  int max = 0x80000000;
  for (int i = 0; i < numbers.size(); ++i)
  {
    cur = cur <= 0 ? numbers[i] : cur + numbers[i];
    max = std::max(cur, max);
  }
  return max;
}

int SubArrayMaxSum4(const vector<int>& numbers)
{
  if (numbers.empty())
  {
    return 0;
  }
  int cur = 0;
  int max = 0x80000000;
  for (int i = 0; i < numbers.size(); ++i)
  {
    if (cur <= 0)
    {
      cur = numbers[i];
    }
    else
    {
      cur += numbers[i];
    }
    max = std::max(cur, max);
  }
  return max;
}

//错误的递归 其实只是计算出了以每个位置结尾的情况下 最大和
//并非所有的最大和 要求所有的最大和还必须遍历每个位置选出最大的一个
//这个递归也有利用价值 
int Process(const vector<int>& numbers, int i)
{
  if (i == 0)
  {
    return numbers[i];
  }
  return std::max(numbers[i], Process(numbers, i - 1) + numbers[i]);
}

int SubArrayMaxSum2(const vector<int>& numbers)
{
  if (numbers.empty())
  {
    return 0;
  }
  int maxSum = 0x80000000;
  for (int i = numbers.size() - 1; i >= 0; --i)
  {
    maxSum = std::max(maxSum, Process(numbers, i));
  }
  return maxSum;
}

//数学归纳法 或者数组压缩 利用递推公式  
//错误
int SubArrayMaxSum3(const vector<int>& numbers)
{
  if (numbers.empty())
  {
    return 0;
  }

  int maxSum = 0x80000000;
  for (int j = 0; j < numbers.size(); ++j)
  {
    int f1 = numbers[0];
    int f2 = 0x80000000;
    for (int i = 0; i <= j; ++i)
    {
      f2 = std::max(numbers[i], f1 + numbers[i]);
      f1 = f2;
    }
    maxSum = std::max(f2, maxSum);
  }
  return maxSum;
}

int main(void)
{
  vector<int> test = {-2, -3, -5, 40, -10 -10, 100, 1};
  std::cout << SubArrayMaxSum(test) << std::endl;
  std::cout << SubArrayMaxSum2(test) << std::endl;
  std::cout << SubArrayMaxSum3(test) << std::endl;
  std::cout << SubArrayMaxSum4(test) << std::endl;
  
  std::cout << std::endl;
  test = {1, -2, 3, 10, -4, 7, 2, -5};
  std::cout << SubArrayMaxSum(test) << std::endl;
  std::cout << SubArrayMaxSum2(test) << std::endl;
  std::cout << SubArrayMaxSum3(test) << std::endl;
  std::cout << SubArrayMaxSum4(test) << std::endl;
  
  return 0;
}
