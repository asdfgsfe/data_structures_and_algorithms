class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        if (nums.empty()) {
            return {};
        }
        vector<int> one;
        vector<vector<int>> all;
        SubProcess(nums, 0, one, all);
        return all;
    }

    void SubProcess(const vector<int>& nums, int i, vector<int>& one, vector<vector<int>>& all) {
        if (i == nums.size()) {
            all.emplace_back(one);
            return;
        }
        SubProcess(nums, i + 1, one, all);
        one.push_back(nums[i]);
        SubProcess(nums, i + 1, one, all);
        one.pop_back();
    }
};

子集
给你一个整数数组 nums ，数组中的元素 互不相同 。返回该数组所有可能的子集（幂集）。

解集 不能 包含重复的子集。你可以按 任意顺序 返回解集。

 

示例 1：

输入：nums = [1,2,3]
输出：[[],[1],[2],[1,2],[3],[1,3],[2,3],[1,2,3]]
示例 2：

输入：nums = [0]
输出：[[],[0]]
 

提示：

1 <= nums.length <= 10
-10 <= nums[i] <= 10
nums 中的所有元素 互不相同
相关标签
位运算
数组
回溯

作者：力扣 (LeetCode)
链接：https://leetcode-cn.com/leetbook/read/top-interview-questions-medium/xv67o6/
来源：力扣（LeetCode）
著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。
