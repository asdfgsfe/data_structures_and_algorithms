class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        if (nums.empty()) {
            return {-1, -1};
        }
        int l = searchLeft(nums, target);
        int r = searchRight(nums, target);
        return {l, r};
    }

    int searchLeft(vector<int>& nums, int t) {
        int l = 0;
        int r = nums.size() - 1;
        int i = -1;
        while (l <= r) {
            int m = (l + r) / 2;
            if (nums[m] >= t) {
                i = nums[m] == t ? m : i;
                r = m - 1;
            } else {
                l = m + 1;
            }
        }
        return i;
    }

    int searchRight(vector<int>& nums, int t) {
        int l = 0;
        int r = nums.size() - 1;
        int i = -1;
        while (l <= r) {
            int m = (l + r) / 2;
            if (nums[m] <= t) {
                i = nums[m] == t ? m : i;
                l = m + 1;
            } else {
                r = m - 1;
            }
        }
        return i;
    }
};

在排序数组中查找元素的第一个和最后一个位置
给定一个按照升序排列的整数数组 nums，和一个目标值 target。找出给定目标值在数组中的开始位置和结束位置。

如果数组中不存在目标值 target，返回 [-1, -1]。

进阶：

你可以设计并实现时间复杂度为 O(log n) 的算法解决此问题吗？
 

示例 1：

输入：nums = [5,7,7,8,8,10], target = 8
输出：[3,4]
示例 2：

输入：nums = [5,7,7,8,8,10], target = 6
输出：[-1,-1]
示例 3：

输入：nums = [], target = 0
输出：[-1,-1]
 

提示：

0 <= nums.length <= 105
-109 <= nums[i] <= 109
nums 是一个非递减数组
-109 <= target <= 109
相关标签
数组
二分查找


作者：力扣 (LeetCode)
链接：https://leetcode-cn.com/leetbook/read/top-interview-questions-medium/xv4bbv/
来源：力扣（LeetCode）
著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。
