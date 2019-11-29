class Solution {
public:
	int minSubArrayLen(int s, vector<int>& nums) {
		if (nums.empty() || s < 1)
		{
			return 0;
		}
		int len = 0x7fffffff;
		int l = 0;
		int f = 0;
		int sum = 0;
		while (f <= nums.size())
		{
			if (sum < s)
			{
				sum += nums[f++];
			}
			else
			{
	
				len = std::min(len, f - l);
				sum -= nums[l++];
			}
			if (sum < s && f == nums.size())
			{
				break;
			}
		}
		return len == 0x7fffffff ? 0 : len;
	}
};
