#include <iostream>
#include <vector>

using std::vector;

//题目：
//给定一个整形数组arr，其中只含有1、2和3，代表所有圆盘目前的状态。
//1代表左柱，2代表中柱，3代表右柱，arr[i]代表第i+1个圆盘的位置。
//比如，arr=[3,3,2,1]，代表第一个盘子在右柱上，第二个盘子在右柱上，第三个圆盘在中柱上，第四个圆盘在左柱上。
//如果arr代表的状态是最优移动轨迹过程中出现的状态，返回arr这种状态是最优移动轨迹中的第几个状态。
//如果arr代表的状态不是最优移动轨迹过程中出现的状态，则返回-1.

//思路：
//首先设from柱子上的圆盘为1~i-1，如果移动到to上的最少步骤数，假设为S(i-1)。
//根据此前汉诺塔的解题步骤可得，S(i)=步骤1的步骤总数+1+步骤3的步骤总数= S(i-1)+1+S(i-1),由于S(1)=1.
//所以S(i)+1 = 2(S(i-1)+1)，根据等比数列的求和公式可得S(i)+1 = 2^i，所以S(i)=2^i-1.

//在arr数组中，N-1的位置至关重要。要分几种情况进行考虑：n-1表示最后一个元素
//第N-1个圆盘在from柱子上，则需要考虑1~N-2个柱子的情况。
//如果第N-1个圆盘在mid柱子上，则返回-1.因为按照汉诺塔的最佳移动方式，最后一个圆盘是不可能出现在中间的。
//如果第N-1个圆盘出现在to柱子上，则有两种可能，
//1~N-2个圆盘都在mid柱子上，或者在mid到to的过程中。
//此时的柱子最少已经走完了2^i-1步。
//由于from上的最后一个圆盘转移到了to柱子上因此还需要+1，则最少走完的步数为2^i.之后需要考虑1~N-2个圆盘的情况。
//

//1==from 2 == mid 3 == to


int MoveProcess(const vector<int>& steps, int i, int from, int mid, int to)
{
  if (i < 0)
  {
    return 0;
  }
  if (steps[i] == mid)
  {
    return -1;
  }
  if (steps[i] == from)
  {
    return MoveProcess(steps, i - 1, from, to, mid);//还未开始移动的情况 将1~n-2从form借助to移动到mid
  }
  int res = MoveProcess(steps, i - 1, mid, to, from);//在to柱子上的情况
  if (res == -1)
  {
    return -1;
  }
  return (1 << i) + res;
}

int Step1(const vector<int>& steps)
{
  if (steps.empty())
  {
    return 0;
  }
  return MoveProcess(steps, steps.size() - 1, 1, 2, 3);
}

int Step2(const vector<int>& steps)
{
  if (steps.empty())
  {
    return 0;
  }
  int from = 1;
  int mid = 2;
  int to = 3;
  int i = steps.size() - 1;
  int res = 0;
  while (i >= 0)
  {
    if (steps[i] == mid)
    {
      return -1;
    }
    if (steps[i] == from)
    {
      std::swap(to, mid);
    }
    else
    {
      res += (1 << i);
      std::swap(mid, from);
    }
    --i;
  }
  return res;
}

int main(void)
{
  vector<int> steps = {3, 2, 1};
  std::cout << Step1(steps) << std::endl;
  std::cout << Step2(steps) << std::endl;

  return 0;
}
