#include <iostream>
#include <vector>

using std::vector;

//����ȫ������ �����û�������ģ��(�������еļ򻯰�) �ռ�Ҫ��o(1) ����ֻ���û�������ģ��
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

//4�ܽⷨ
//1.��������ģ�� n
//2.�������� n*n
//3.map���淢 n*n
//4.��Ϊ��λ�ÿ�ͷȥ�ۼӳ�aim �ݹ��dp��ͨ�ýⷨ n*n