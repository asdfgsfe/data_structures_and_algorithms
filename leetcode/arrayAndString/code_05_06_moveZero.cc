class Solution {
public:
	void moveZeroes(vector<int>& nums) {
		if (nums.empty())
		{
			return;
		}
		int p = 0;
		int n = 0;
		while (n < nums.size())
		{
			while (n < nums.size() && nums[n] == 0)
			{
				++n;
			}
			while (n < nums.size() && nums[n] != 0)
			{
				if (p != n)
				{
					std::swap(nums[p], nums[n]);
				}
				++p;
				++n;
			}
		}
	}
};