三数之和
给定一个包含 n 个整数的数组 nums，判断 nums 中是否存在三个元素 a，b，c ，使得 a + b + c = 0 ？
找出所有满足条件且不重复的三元组。

注意：答案中不可以包含重复的三元组。

例如, 给定数组 nums = [-1, 0, 1, 2, -1, -4]，

满足要求的三元组集合为：
[
  [-1, 0, 1],
  [-1, -1, 2]
]

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        if (nums.size() < 3)
        {
            return vector<vector<int>>();
        }
        std::sort(nums.begin(), nums.end());
        vector<vector<int>> sums;
        //固定a数字 在排序数字中找b+c
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
