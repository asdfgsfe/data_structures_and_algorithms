class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        if (nums.size() < 2)
        {
            return nums.size();
        }
        int longgest = 1;
        vector<int> dp(nums.size(), 1);
        for (int i = 1; i < nums.size(); ++i)
        {
            for (int j = i - 1; j >= 0; --j)
            {
                if (nums[i] > nums[j])
                {
                    dp[i] = std::max(dp[i], dp[j] + 1);
                }
            }
            longgest = std::max(longgest, dp[i]);
        }
        return longgest;
    }
};