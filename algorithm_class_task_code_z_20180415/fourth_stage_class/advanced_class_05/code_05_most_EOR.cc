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
  vector<int> dp(v.size());//0~i����������г���������Ϊ0�������������� 
  unordered_map<int, int> xorPosition; //0~i���eor��λ�� i
  xorPosition[0] = -1;
  for (int i = 0; i < v.size(); ++i)
  {
    xOR ^= v[i];
    if (xorPosition.find(xOR) != xorPosition.end())
    {
      int pre = xorPosition[xOR];
      dp[i] = pre == -1 ? 1 : (dp[pre] + 1); //��i��β�����������Ϊ0������������� ��i��ǰ�ҵ����������һ������Ϊ0�� 
    }
    if (i > 0)
    {
    	//0~i����������г���������Ϊ0�������������� 
	//ѡȡҪ��i��β����λ��ǲ�Ҫ 
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
