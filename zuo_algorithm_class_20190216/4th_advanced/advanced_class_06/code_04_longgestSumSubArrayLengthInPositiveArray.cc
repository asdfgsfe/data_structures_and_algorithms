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

//ͨ�õĽⷨ�ʺ� ���ֿ�Ϊ����Ϊ�� �ռ�o(n)
int LonggestSubArraySumAim(const vector<int>& numbers, int aim)
{
	if (numers.empty() || aim < 1)
	{
		return 0;
	}
	unordered_map<int, int> sumToIdxs;
	int longggest = 0;
	int sum = 0;
	for (int i = 0; i < numbers.size(); ++i)
	{
		sum += numbers[i];
		auto idx = sumToIdxs.find(sum - aim);
		if (idx != sumToIdxs.end())
		{
			longgest = std::max(longgest, i - idx);
		}
		idx = sumToIdxs.find(sum);
		if (idx == sumToIdxs.find(sum))
		{
			sumToIdxs.insert(pair<int, int>(sum, i));
		}
	}
	return longgest;
}

int main(void)
{
  vector<int> numbers = {1, 3, 5, 4, 9, 3, 12};
  std::cout << MaxLength(numbers, 12) << std::endl;

  return 0;
}
