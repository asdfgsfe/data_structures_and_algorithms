class Solution {
public:
	int removeDuplicates(vector<int>& nums) {
		if (nums.empty())
		{
			return 0;
		}
		int p = 0;
		int n = 0;
		while (n < nums.size())
		{
			int times = 1;
			while (n + 1 < nums.size() && nums[n] == nums[n + 1])
			{
				++times;
				++n;
			}
			times = times >= 2 ? 2 : 1;
			if (times == 1)
			{
				nums[p++] = nums[n++];
			}
			else
			{
				nums[p++] = nums[n];
				nums[p++] = nums[n++];
			}
		}
		return p;
	}
};