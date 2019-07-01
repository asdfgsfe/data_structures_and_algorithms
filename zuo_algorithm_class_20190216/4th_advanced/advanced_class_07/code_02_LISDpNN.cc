#include <iostream>
#include <vector>

using std::vector;

vector<int> generateLIS(const vector<int>& arr, const vector<int>& dp);
vector<int> getdp1(const vector<int>& arr);
void PrintVector(const vector<int>& values);

vector<int> lis1(const vector<int>& arr) 
{
  if (arr.empty()) 
  {
    return vector<int>();
  }
  vector<int> dp = getdp1(arr);
  PrintVector(dp);
  return generateLIS(arr, dp);
}

//o(n * n) 利用ends数组可以将内部的for查找 优化到二分查找
vector<int> getdp1(const vector<int>& arr) 
{
  vector<int> dp(arr.size());
  for (int i = 0; i < arr.size(); i++) 
  {
    dp[i] = 1;
    for (int j = 0; j < i; j++) 
    {
      if (arr[i] > arr[j]) 
      {
        dp[i] = std::max(dp[i], dp[j] + 1);
      }
    }
  }
  return dp;
}

//找出组成这个最长的子序列值有那写
vector<int> generateLIS(const vector<int>& arr, const vector<int>& dp) 
{
  int maxLen = 0; //已经是最长的子序列 全局最长
  int index = 0;
  for (int i = 0; i < dp.size(); i++) 
  {
    if (dp[i] > maxLen) 
    {
      maxLen = dp[i];
      index = i;
    }
  }
  vector<int> lis(len);
  lis[--len] = arr[index];
  for (int i = index; i >= 0; i--) 
  {
    if (arr[i] < arr[index] && dp[i] == dp[index] - 1) //反着去取递增的子序列
    {
      lis[--len] = arr[i];
      index = i;
    }
  }
  return lis;
}

void PrintVector(const vector<int>& values)
{
  for (const auto& val : values)
  {
    std::cout << val << " ";
  }
  std::cout << std::endl;
}

int main(void)
{
  vector<int> test = { 2, 1, 5, 3, 6, 4, 8, 9, 7 };
  PrintVector(lis1(test));

  return 0;
}
