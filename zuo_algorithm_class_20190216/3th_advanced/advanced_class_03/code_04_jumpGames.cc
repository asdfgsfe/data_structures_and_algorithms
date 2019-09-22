#include <iostream>
#include <vector>

using std::vector;

//向右滚动的跳 以每个位置开始能向右跳的最大距离让next记录下来
//i表示向右遍历每个位置 目的是取到以每个位置向右跳的距离
//cur表示当前所处位置 当cur小于i时向右跳 一次就跳到向右的最大位置 其实就是上次跳跃后的最大距离 就死上次的next
//由于遍历i每个位置 所以任何一个位置的信息都不会丢
int JumpGames1(const vector<int>& steps)
{
  if (steps.empty())
  {
    return 0;
  }
  int cur = 0;	//表示目前实际跳到的位置
  int next = 0;	//next表示到目前为止能跳到右边的最远距离
  int jumpTimes = 0;
  for (int i = 0; i < steps.size(); ++i)
  {
    if (cur < i)
    {
      ++jumpTimes;
      cur = next;
    }
    std::cout << "i=" << i << " cur=" << cur << " nex=t" << next << std::endl;
    next = std::max(next, i + steps[i]);
  }
  return jumpTimes;
}

int JumpProcess(const vector<int>& steps, int index)
{
  if (index >= steps.size())
  {
    return -1;
  }
  int jump = 0x7fffffff;
  for (int i = 1; i <= steps[index]; ++i)
  {
    jump = std::min(jump, JumpProcess(steps, index + i) + 1);
  }
  return jump;
}

int JumpGames2(const vector<int>& steps)
{
  if (steps.empty())
  {
    return 0;
  }
  return JumpProcess(steps, 0);
}

int JumpGames3(const vector<int>& steps)
{
  if (steps.empty())
  {
    return 0;
  }
  vector<int> dp(steps.size(), 0x7fffffff);
  dp[dp.size() - 1] = 0;
  for (int i = dp.size() - 2; i >= 0; --i)
  {
    for (int j = 1; j <= steps[i]; ++j)
    {
      if (i + j < dp.size())
      {
        dp[i] = std::min(dp[i], dp[i + j] + 1);
      }
    }
  }
  return dp[0];
}

int main(void)
{
  vector<int> steps = {3, 2, 3, 1, 1, 4};
  std::cout << JumpGames1(steps) << std::endl;
  std::cout << JumpGames2(steps) << std::endl;
  std::cout << JumpGames3(steps) << std::endl;

  return 0;
}
