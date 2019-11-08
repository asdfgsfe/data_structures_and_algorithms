子集
给定一组不含重复元素的整数数组 nums，返回该数组所有可能的子集（幂集）。

说明：解集不能包含重复的子集。

示例:

输入: nums = [1,2,3]
输出:
[
  [3],
  [1],
  [2],
  [1,2,3],
  [1,3],
  [2,3],
  [1,2],
  []
]

class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        if (nums.empty())
        {
            return {{}};
        }
        vector<vector<int>> subsequences;
        vector<int> oneSequence;
        SequenceProcess(nums, 0, oneSequence, subsequences);
        return subsequences;
    }
    
    void SequenceProcess(const vector<int>& nums, int i, vector<int>& oneSequence, vector<vector<int>>& subsequences)
    {
        if (i == nums.size())
        {
            subsequences.emplace_back(oneSequence);
            return;
        }
        SequenceProcess(nums, i + 1, oneSequence, subsequences);
        oneSequence.emplace_back(nums[i]);
        SequenceProcess(nums, i + 1, oneSequence, subsequences);
        oneSequence.pop_back();
    }
};