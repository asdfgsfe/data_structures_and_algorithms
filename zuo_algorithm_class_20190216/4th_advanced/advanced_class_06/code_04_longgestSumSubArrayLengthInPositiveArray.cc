#include <iostream>
#include <vector>

using std::vector;

//由于全是整数 可以用滑动窗口模型(单调队列的简化版) 空间要求o(1) 所以只能用滑动窗口模型
int MaxLength(const vector<int>& numbers, int aim)
{
  if (numbers.empty() || aim < 1)
  {
    return 0;
  }
  int l = 0;
  int r = 0;
  int curSum  = 0;
  int maxLen = 0;
  while (r < numbers.size())
  {
    if (curSum >= aim)
    {
      maxLen = (curSum == aim) && (maxLen < r - l) ? r - l : maxLen;
      curSum -= numbers[l++];
      continue;
    }
    curSum += numbers[r++];
  }
  return maxLen;
}

//4总解法
//1.滑动窗口模型 n 有使用条件限制 目前看只是适用于符号相同的 或者有条件限制的
//2.域处理数组累加和 然后n*n的遍历数组 其实就是以每个位置开头的情况下怎么怎么样 
//3.map缓存发 利用map记录sum对应的位置 来求取累加和等于aim的一段距离 时间复杂度n 空间复杂度n 
//4.以为个位置开头去累加出aim 递归和dp的通用解法 n*n