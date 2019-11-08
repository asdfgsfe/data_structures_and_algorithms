全排列
给定一个没有重复数字的序列，返回其所有可能的全排列。

示例:

输入: [1,2,3]
输出:
[
  [1,2,3],
  [1,3,2],
  [2,1,3],
  [2,3,1],
  [3,1,2],
  [3,2,1]
]

class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        if (nums.empty())
        {
            return {{}};
        }
        vector<vector<int>> permutetions;
        PermuteProcess(nums, 0, permutetions);
        return permutetions;
    }
    
    void PermuteProcess(vector<int>& nums, int i, vector<vector<int>>& permutetions)
    {
        if (i == nums.size())
        {
            permutetions.emplace_back(nums);
            return;
        }
        for (int s = i; s < nums.size(); ++s)
        {
            std::swap(nums[s], nums[i]);
            PermuteProcess(nums, i + 1, permutetions);
            std::swap(nums[s], nums[i]);
        }
    }
};