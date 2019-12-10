class Solution {
public:
	void sortColors(vector<int>& nums) {
		if (nums.empty())
		{
			return;
		}
		int less = -1;
		int more = nums.size();
		int i = 0;
		while (i < more)
		{
			if (nums[i] < 1)
			{
				std::swap(nums[i++], nums[++less]);
			}
			else if (nums[i] > 1)
			{
				std::swap(nums[i], nums[--more]);
			}
			else
			{
				++i;
			}
		}
	}
};