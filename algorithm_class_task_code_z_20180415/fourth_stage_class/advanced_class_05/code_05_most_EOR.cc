#include <iostream>
#include <vector>
#include <unordered_map>

using std::vector;
using std::unordered_map;

int MostEOR(const vector<int>& v)
{
  if (v.empty())
  {
    return 0;
  }
  int ans = 0;
  int xOR = 0;
  vector<int> dp(v.size());//0~i这段子数组切出来的异或和为0子数组最多的数量 
  unordered_map<int, int> xorPosition; //0~i这段eor的位置 i
  xorPosition[0] = -1;
  for (int i = 0; i < v.size(); ++i)
  {
    xOR ^= v[i];
    if (xorPosition.find(xOR) != xorPosition.end())
    {
      int pre = xorPosition[xOR];
      dp[i] = pre == -1 ? 1 : (dp[pre] + 1); //以i结尾的情况下异或和为0的子数组的数量 从i向前找到离他最近的一段异或和为0的 
    }
    if (i > 0)
    {
    	//0~i这段子数组切出来的异或和为0子数组最多的数量 
	//选取要以i结尾的这段还是不要 
      dp[i] = std::max(dp[i-1], dp[i]);
    }
    xorPosition[xOR] = i;
    ans = std::max(ans, dp[i]);
  }
  return ans;
}

//book p104
int main(void)
{
  vector<int> v = {3, 2, 1, 0, 1, 2, 3, 0};
  std::cout << MostEOR(v) << std::endl;

  return 0;
}
