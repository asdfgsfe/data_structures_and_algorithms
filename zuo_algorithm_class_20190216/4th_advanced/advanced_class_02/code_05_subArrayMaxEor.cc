#include <iostream>
#include <vector>

using std::vector;

//返回以每个位置结尾的情况下最大异或和 这个递归其实就是for
int EorProcess(const vector<int>& numbers, int i)
{
  if (i == 0)
  {
    return numbers[i];
  }
  return std::max(numbers[i], EorProcess(numbers, i - 1) ^ numbers[i]);
}

int SubArrayMaxEor(const vector<int>& numbers)
{
  if (numbers.empty())
  {
    return 0;
  }
  int max = 0;
  for (int i = numbers.size() - 1; i >= 0; --i)
  {
    max = std::max(max, EorProcess(numbers, i));
  }
  return max;
}

//dp不可以省略 因为只要一个值就行 O(n)
int SubArrayMaxEorDp(const vector<int>& numbers)
{
  if (numbers.empty())
  {
    return 0;
  }
  vector<int> dp(numbers.size());
  dp[0] = numbers[0];
  for (int i = 1; i < numbers.size(); ++i)
  {
    dp[i] = std::max(numbers[i], dp[i - 1] ^ numbers[i]);
  }
  int maxEor = 0x80000000;
  for (int eor : dp)
  {
    maxEor = eor > maxEor ? eor : maxEor;
  }
  return maxEor;
}

int SubArrayMaxEorDp2(const vector<int>& numbers)
{
  if (numbers.empty())
  {
    return 0;
  }
  vector<int> dp(numbers.size());
  dp[0] = numbers[0];
  int maxEor = numbers[0];
  for (int i = 1; i < numbers.size(); ++i)
  {
    dp[i] = std::max(numbers[i], dp[i - 1] ^ numbers[i]);
    maxEor = std::max(maxEor, dp[i]);
  }
  return maxEor;
}

//空间优化
int MaxEorDp3(const vector<int>& numbers)
{
	int maxEor = 0;
	int curMaxEor = 0;
	for (int number : numbers)
	{
		curMaxEor ^= number;
		curMaxEor = std::max(curMaxEor, number)
		maxEor = std::max(maxEor, curMaxEor);
	}
	return maxEor;
}



//offer方法 异或和和累加和有本质区别 所有不能简单的用0去判断
//留着 作为一个错误的例子
int SubArrayMaxEor2(const vector<int>& numbers)
{
  if (numbers.empty())
  {
    return 0;
  }
  int maxEor = 0x80000000;
  int curEor = 0;
  for (int number : numbers)
  {
    curEor = curEor <= 0 ? number : curEor ^ number;
    maxEor = curEor > maxEor ? curEor : maxEor;
  }
  return maxEor;
}


int main(void)
{
  vector<int> numbers = {1, 3, 2, 4,  5};
  std::cout << SubArrayMaxEor(numbers) << std::endl;
  std::cout << SubArrayMaxEor2(numbers) << std::endl; //错误的解法
  std::cout << SubArrayMaxEorDp(numbers) << std::endl;
  std::cout << SubArrayMaxEorDp2(numbers) << std::endl;
  std::cout << MaxEorDp3(numbers) << std::endl;

  return 0;
}
