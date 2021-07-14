class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        if (nums.empty() || k < 0 || k > nums.size()) {
            return 0x7fffffff;
        }
        for (int i = k / 2; i >= 0; --i) {
            Percdown(nums, i, k);
        }
        for (int i = k; i < nums.size(); ++i) {
            if (nums[i] > nums[0]) {
                std::swap(nums[i], nums[0]);
                Percdown(nums, 0, k);
            }
        }
        return nums[0];
    }

    void Percdown(vector<int>& nums, int i, int n) {
        int child = 2 * i + 1;
        while (child < n) {
            if (child + 1 != n && nums[child + 1] < nums[child]) {
                ++child;
            }
            if (nums[i] < nums[child]) {
                break;
            }
            std::swap(nums[i], nums[child]);
            i = child;
            child = 2 * i + 1;
        }
    }
};

数组中的第K个最大元素
给定整数数组 nums 和整数 k，请返回数组中第 k 个最大的元素。

请注意，你需要找的是数组排序后的第 k 个最大的元素，而不是第 k 个不同的元素。

 

示例 1:

输入: [3,2,1,5,6,4] 和 k = 2
输出: 5
示例 2:

输入: [3,2,3,1,2,4,5,5,6] 和 k = 4
输出: 4
 

提示：

1 <= k <= nums.length <= 104
-104 <= nums[i] <= 104
相关标签
数组
分治
快速选择
排序
堆（优先队列）

作者：力扣 (LeetCode)
链接：https://leetcode-cn.com/leetbook/read/top-interview-questions-medium/xvsehe/
来源：力扣（LeetCode）
著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。
