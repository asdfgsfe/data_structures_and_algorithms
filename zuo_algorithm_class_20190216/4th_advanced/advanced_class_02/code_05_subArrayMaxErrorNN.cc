#include <iostream>
#include <vector>

using std::vector;

int MaxEor(const vector<int>& nums)
{
	if (nums.empty())
	{
		return 0;
	}
	vector<int> eors(nums.size(), 0);
	eors[0] = nums[0];
	for (int i = 1; i < nums.size(); ++i)
	{
		eors[i] = nums[i] ^ eors[i - 1];
	}
	int maxEor = 0x80000000;
	for (int i = 0; i < nums.size(); ++i)
	{
		for (int j = 0; j < nums.size(); ++j)
		{
			maxEor = std::max(maxEor, eors[i] ^ eors[j]);
		}
	}
	return maxEor;
}

int main(void)
{
  vector<int> numbers = {1, 3, 2, 4,  5};
  std::cout << MaxEor(numbers) << std::endl;

  return 0;
}
