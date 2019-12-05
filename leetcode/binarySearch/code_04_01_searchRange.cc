class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        if (nums.empty())
        {
            return {-1, -1};
        }
        int l = 0;
        int r = nums.size() - 1;
        int left = -1;
        while (l <= r)
        {
            int m = l + (r - l) / 2;
            if (nums[m] >= target)
            {
                left = nums[m] == target ? m : left;
                r = m - 1;
            }
            else
            {
                l = m + 1;
            }
        }
        l = 0;
        r = nums.size() - 1;
        int right = -1;
        while (l <= r)
        {
            int m = l + (r - l) / 2;
            if (nums[m] <= target)
            {
                right = nums[m] == target ? m : target;
                l = m + 1;
            }
            else
            {
                r = m - 1;
            }
        }
        if (left == -1 || right == -1)
        {
            return {-1, -1};
        }
        return {left, right};
    }
};