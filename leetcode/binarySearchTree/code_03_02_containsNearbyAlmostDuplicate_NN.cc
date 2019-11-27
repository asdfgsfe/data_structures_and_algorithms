class Solution {
public:
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) {
        if (nums.size() < 2)
        {
			return false;
        }
		for (int i = 0; i < nums.size(); ++i)
		{
			for (int j = i + 1; j < nums.size(); ++j)
			{
				if (std::abs((long long)nums[i] - (long long)nums[j]) <= t && std::abs(i - j) <= k)
				{
					return true;
				}
			}
		}
		return false;
    }
};