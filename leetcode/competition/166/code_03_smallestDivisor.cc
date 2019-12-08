class Solution {
public:
    int smallestDivisor(vector<int>& nums, int threshold) {
        if (nums.empty() || threshold < 1 || nums.size() > threshold)
        {
            return 0;
        }
        int l = 1;
        int r = nums[0];
        for (int num : nums)
        {
            r = std::max(r, num);
        }
        int target = -1;
        while (l <= r)
        {
            int m = l + (r - l) / 2;
            int sum = 0;
            for (int i = 0; i < nums.size(); ++i)
            {
                int rest = nums[i] % m;
                sum += nums[i] / m;
                sum += rest == 0 ? 0 : 1;
            }
            if (sum > threshold)
            {
                l = m + 1;
            }
            else
            {
                target = m;
                r = m - 1;
            }
        }
        return target;
    }
};