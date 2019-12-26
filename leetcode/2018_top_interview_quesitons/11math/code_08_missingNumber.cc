class Solution {
public:
    int missingNumber(vector<int>& nums) {
        if (nums.empty())
        {
            return 0;
        }
        int miss = nums.size();//这里很重要
        int i = 0;
        while (i < nums.size())
        {
            if (nums[i] >= nums.size() || nums[i] < 0)
            {
                miss = i++;
            }
            else if (nums[i] == nums[nums[i]])
            {
                ++i;
            }
            else
            {
                std::swap(nums[i], nums[nums[i]]);
            }
        }
        return miss;
    }
};