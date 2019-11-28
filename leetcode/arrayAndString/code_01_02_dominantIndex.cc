class Solution {
public:
    int dominantIndex(vector<int>& nums) {
        if (nums.empty())
        {
            return -1;
        }
        int maxId = -1;
        int maxN = 0x80000000;
        for (int i = 0; i < nums.size(); ++i)
        {
            if (nums[i] > maxN)
            {
                maxN = nums[i];
                maxId = i;
            }
        }
        for (int num : nums)
        {
            if (num != maxN && num * 2 > maxN)
            {
                return -1;
            }
        }
        return maxId;
    }
};