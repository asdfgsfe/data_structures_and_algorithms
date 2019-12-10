class Solution {
public:
    void sortColors(vector<int>& nums) {
        if (nums.empty())
        {
            return;
        }
        int times[3] = {0, 0, 0};
        for (int num : nums)
        {
            ++times[num];
        }
        int p = 0;
        for (int i = 0; i < 3; ++i)
        {
            while (times[i]--)
            {
                nums[p++] = i;
            }
        }
    }
};