#include <iostream>
#include <vector>

using std::vector;

void PrintVector(const vector<int>& values)
{
  for (int val : values)
  {
    std::cout << val << " ";
  }
  std::cout << std::endl;
}

//book p110
vector<int> LISsDp(const vector<int>& numbers)
{
  if (numbers.empty())
  {
    return vector<int>();
  }
  vector<int> dp(numbers.size());
  dp[0] = 1;
  vector<int> ends(numbers.size());
  ends[0] = numbers[0];
  int right = 0;
  for (int i = 1; i < numbers.size(); ++i)
  {
    int l = 0;
    int r = right;
    while (l <= r)
    {
      int m = (l + r) / 2;
      if (numbers[i] > ends[m])
      {
        l = m + 1;
      }
      else
      {
        r = m - 1;
      }
    }
    std::cout << "right=" << right << " l=" << l << std::endl;
    right = std::max(right, l);
    //找到了就替换 找不到就插入 找不到l和right应该相等
    ends[l] = numbers[i];
    dp[i] = l + 1;
  }
  //1 1 2 2 3 3 4 5 4
  PrintVector(dp);
  //1 3 4 7 9 0 0 0 0
  PrintVector(ends);
  return dp;
}

vector<int> LIS(const vector<int>& numbers)
{
  if (numbers.empty())
  {
    return vector<int>();
  }
  vector<int> dp = LISsDp(numbers);
  int maxLen = 0;
  int index = 0;
  for (int i = 0; i < dp.size(); ++i)
  {
    if (maxLen < dp[i])
    {
      maxLen = dp[i];
      index = i;
    }
  }
  vector<int> lIS(maxLen);
  lIS[--maxLen] = numbers[index];
  for (int i = index; i >= 0; --i)
  {
    if (numbers[i] < numbers[index] && dp[index] - 1 == dp[i])
    {
      lIS[--maxLen] = numbers[i];
      index = i;
    }
  }
  return lIS;
}

int main(void)
{
  vector<int> numbers = {2, 1, 5, 3, 6, 4, 8, 9, 7};
  PrintVector(LIS(numbers));

  return 0;
}
