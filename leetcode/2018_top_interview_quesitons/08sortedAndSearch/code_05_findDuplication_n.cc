class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        if (nums.size() < 2)
        {
            return 0;
        }
        int i = 0;
        while (i < nums.size())
        {
            if (nums[i] == i + 1)
            {
                ++i;
            }
            else if (nums[nums[i] - 1] != nums[i])
            {
                std::swap(nums[i], nums[nums[i] - 1]);
            }
            else
            {
                return nums[i];
            }
        }
        return 0;
    }
};
