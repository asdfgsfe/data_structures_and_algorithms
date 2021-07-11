class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        if (nums.empty()) {
            return {};
        }
        vector<vector<int>> all;
        PermuteProcess(nums, 0, all);
        return all;
    }

    void PermuteProcess(vector<int>& nums, int i, vector<vector<int>>& all) {
        if (i == nums.size()) {
            all.emplace_back(nums);
            return;
        }
        unordered_set<int> visited;
        for (int s = i; s < nums.size(); ++s) {
            if (!visited.count(nums[s])) {
                visited.emplace(nums[s]);
                std::swap(nums[i], nums[s]);
                PermuteProcess(nums, i + 1, all);
                std::swap(nums[i], nums[s]);
            }
        }
    }
};

全排列
给定一个不含重复数字的数组 nums ，返回其 所有可能的全排列 。你可以 按任意顺序 返回答案。

 

示例 1：

输入：nums = [1,2,3]
输出：[[1,2,3],[1,3,2],[2,1,3],[2,3,1],[3,1,2],[3,2,1]]
示例 2：

输入：nums = [0,1]
输出：[[0,1],[1,0]]
示例 3：

输入：nums = [1]
输出：[[1]]
 

提示：

1 <= nums.length <= 6
-10 <= nums[i] <= 10
nums 中的所有整数 互不相同
相关标签
数组
回溯


作者：力扣 (LeetCode)
链接：https://leetcode-cn.com/leetbook/read/top-interview-questions-medium/xvqup5/
来源：力扣（LeetCode）
著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。
