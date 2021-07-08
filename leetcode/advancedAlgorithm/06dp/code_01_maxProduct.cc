乘积最大子数组
给你一个整数数组 nums ，请你找出数组中乘积最大的连续子数组（该子数组中至少包含一个数字），并返回该子数组所对应的乘积。

 

示例 1:

输入: [2,3,-2,4]
输出: 6
解释: 子数组 [2,3] 有最大乘积 6。
示例 2:

输入: [-2,0,-1]
输出: 0
解释: 结果不能为 2, 因为 [-2,-1] 不是子数组。
相关标签
数组
动态规划

作者：力扣 (LeetCode)
链接：https://leetcode-cn.com/leetbook/read/top-interview-questions-hard/xdwst3/
来源：力扣（LeetCode）
著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。

class Solution {
public:
    int maxProduct(vector<int>& nums) {
        if (nums.empty()) {
            return 0x80000000;
        }
        int preMax = nums[0];
        int preMin = nums[0];
        int product = nums[0];
        for (int i = 1; i < nums.size(); ++i) {
            int curMax = std::max(nums[i], std::max(nums[i] * preMin, nums[i] * preMax));
            int curMin = std::min(nums[i], std::min(nums[i] * preMin, nums[i] * preMax));
            preMax = curMax;
            preMin = curMin;
            product = std::max(preMax, product);
        }
        return product;
    }
};
