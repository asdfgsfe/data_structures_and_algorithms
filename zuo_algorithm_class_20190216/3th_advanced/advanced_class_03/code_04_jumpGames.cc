#include <iostream>
#include <vector>

using std::vector;

//���ҹ������� ��ÿ��λ�ÿ�ʼ������������������next��¼����
//i��ʾ���ұ���ÿ��λ�� Ŀ����ȡ����ÿ��λ���������ľ���
//cur��ʾ��ǰ����λ�� ��curС��iʱ������ һ�ξ��������ҵ����λ�� ��ʵ�����ϴ���Ծ��������� �����ϴε�next
//���ڱ���iÿ��λ�� �����κ�һ��λ�õ���Ϣ�����ᶪ
int JumpGames1(const vector<int>& steps)
{
  if (steps.empty())
  {
    return 0;
  }
  int cur = 0;	//��ʾĿǰʵ��������λ��
  int next = 0;	//next��ʾ��ĿǰΪֹ�������ұߵ���Զ����
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
