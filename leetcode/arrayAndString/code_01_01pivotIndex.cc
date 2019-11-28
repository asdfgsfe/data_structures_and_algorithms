class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        if (nums.empty())
        {
			return -1;
        }
		vector<int> sums(nums.size());
		sums[0] = nums[0];
		for (int i = 1; i < nums.size(); ++i)
		{
			sums[i] = sums[i - 1] + nums[i];
		}
		for (int i = 0; i < nums.size(); ++i)
		{
			if (i == 0 && sums.back() - sums[0] == 0)
			{
				return 0;
			}
			if (i > 0 && sums[i - 1] == sums[sums.size() - 1] - sums[i])
			{
				return i;
			}
		}
		return -1;
    }
};