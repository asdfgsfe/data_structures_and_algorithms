#include <iostream>
#include <vector>

using std::vector;

void PrintVector(const vector<int>& values);

int LISProcess(const vector<int>& numbers, int i)
{
  if (i == 0)
  {
    return 1;
  }
  int curLIS = 1; 
  for (int j = i - 1; j >= 0; --j) //这个地方必须向前遍历到零 而不能单纯的遍历到第一个
  {
    if (numbers[i] > numbers[j])
    {
		curLIS = std::max(curLIS, LISProcess(numbers, j) + 1);
    }
  }
  return curLIS;
}

//o(n*n)
vector<int> LISsDp(const vector<int>& numbers)
{
  if (numbers.empty())
  {
    return vector<int>();
  }
  vector<int> dp(numbers.size());
  for (int i = 0; i < dp.size(); ++i)
  {
    dp[i] = 1;
    for (int j = i - 1; j >= 0; --j) 
    {
      dp[i] = std::max(dp[i], dp[j] + 1);
    }
  }
  return lISs;
}

vector<int> LIS(const vector<int>& numbers)
{
  if (numbers.empty())
  {
    return vector<int>();
  }
  int maxLen = 0;
  int index = -1;
  vector<int> lISs(numbers.size());
  //o(n*递归代价)
  for (int i = numbers.size() - 1; i >= 0; --i)
  {
    lISs[i] = LISProcess(numbers, i);
	if (maxLen < lISs[i])
    {
      maxLen = lISs[i];
      index = i;
    }
  }
  //挑出最长递增的子序列
  vector<int> lIS(maxLen);
  lIS[--maxLen] = numbers[index];
  for (int i = index; i >= 0; --i)
  {
    if (numbers[index] > numbers[i] && lISs[index] - 1 == lISs[i])
    {
      lIS[--maxLen] = numbers[i];
      index = i;
    }
  }
  return lIS;
}

void PrintVector(const vector<int>& values)
{
  for (int val : values)
  {
    std::cout << val << " ";
  }
  std::cout << std::endl;
}

int main(void)
{
  vector<int> numbers = { 2, 1, 5, 3, 6, 4, 8, 9, 7 };
  //PrintVector(LIS(numbers));
  PrintVector(LISs(numbers));

  return 0;
}
