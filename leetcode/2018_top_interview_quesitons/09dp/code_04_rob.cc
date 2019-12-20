class Solution {
public:
    int rob(vector<int>& nums) {
        if (nums.empty())
        {
			return 0;
        }
		int f1 = 0;
		int f2 = nums.back();
		int f3 = nums.back();
		for (int i = nums.size() - 2; i >= 0; --i)
		{
			f3 = std::max(nums[i] + f1, f2);
			f1 = f2;
			f2 = f3;
		}
		return f3;
    }
};