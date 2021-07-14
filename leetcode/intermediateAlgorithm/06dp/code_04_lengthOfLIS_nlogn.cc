class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        if (nums.size() < 2) {
            return nums.size();
        }
        int longest = 1;
        int right = 0;
        vector<int> ends(nums.size(), 0);
        ends[0] = nums[0];
        for (int i = 1; i < nums.size(); ++i) {
            int l = 0;
            int r = right;
            while (l <= r) {
                int m = (l + r) / 2;
                if (nums[i] > ends[m]) {
                    l = m + 1;
                } else {
                    r = m - 1;
                }
            }
            longest = std::max(longest, l + 1);
            right = std::max(right, l);
            ends[l] = nums[i];

        }
        return longest;
    }
};
