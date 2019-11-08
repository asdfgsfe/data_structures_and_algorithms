class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        if (nums.size() < 3)
        {
            return vector<vector<int>>();
        }
        std::sort(nums.begin(), nums.end());
        vector<vector<int>> sums;
        for (int i = 0; i < nums.size() - 2; ++i)
        {
            if (nums[i] > 0)
            {
                break;
            }
            if (i > 0 && nums[i - 1] == nums[i])
            {
                continue;
            }
            int l = i + 1;
            int r = nums.size() - 1;
            //为什么只取i以后的区间来计算这个值 其思想就是以数组中每个位置开头的情况下 统计三数之和等于0的 以每个位置开头 所有的必会都统计到
            while (l < r)
            {
                int sum = nums[i] + nums[l] + nums[r];
                if (sum == 0)
                {
                    vector<int> tmp{nums[i], nums[l++], nums[r--]};
                    sums.emplace_back(std::move(tmp));
                    while (l < r && nums[l] == nums[l - 1]) { ++l; }
                    while (l < r && nums[r] == nums[r + 1]) { --r; }
                }
                else if (sum < 0)
                {
                    ++l;
                    while (l < r && nums[l] == nums[l - 1]) { ++l; }
                }
                else
                {
                    --r;
                    while (l < r && nums[r] == nums[r + 1]) { --r; }
                }
            }
        }
        return sums;
    }
};
