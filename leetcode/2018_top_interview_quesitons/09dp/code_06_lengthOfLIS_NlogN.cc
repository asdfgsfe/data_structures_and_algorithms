class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        if (nums.size() < 2)
        {
            return nums.size();
        }
        int right = 0;
        int longgest = 1;
        vector<int> ends(nums.size(), 0);
        ends[0] = nums[0];
        for (int i = 1; i < nums.size(); ++i)
        {
            int l = 0;
            int r = right;
            while (l <= r)
            {
                int m = l + (r - l) / 2;
                if (nums[i] > ends[m])
                {
                    l = m + 1;
                }
                else
                {
                    r = m - 1;
                }
            }
            ends[l] = nums[i];
            right = std::max(right, l);
            longgest = std::max(longgest, l + 1);
        }
        return longgest;
    }
};