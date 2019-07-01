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

//通用的解法适合 数字可为正可为负 空间o(n)
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
