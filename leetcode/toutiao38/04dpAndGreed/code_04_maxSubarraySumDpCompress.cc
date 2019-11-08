class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        if (nums.empty())
        {
            return 0;
        }
        int pre = nums[0];
        int sum = nums[0];
        for (int i = 1; i < nums.size(); ++i)
        {
            pre = std::max(nums[i], pre + nums[i]);
            sum = std::max(sum, pre);
        }
        return sum;
    }
};
