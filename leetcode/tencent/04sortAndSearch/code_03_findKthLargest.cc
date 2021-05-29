class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        if (nums.empty()) {
            return 0x7fffffff;
        }
        vector<int> topK(k, 0x80000000);
        for (int i = 0; i < nums.size(); ++i) {
            if (nums[i] > topK[0]) {
                topK[0] = nums[i];
                Percdown(topK, 0, k);
            }
        }
        return topK[0];
    }

    void Percdown(vector<int>& nums, int i, int n) {
        int child = 2 * i + 1;
        while (child < n) {
            if (child + 1 < n && nums[child + 1] < nums[child]) {
                ++child;
            }
            if (nums[child] > nums[i]) {
                return;
            }
            std::swap(nums[child], nums[i]);
            i = child;
            child = 2 * i + 1;
        }
    }
};

数组中的第K个最大元素
在未排序的数组中找到第 k 个最大的元素。请注意，你需要找的是数组排序后的第 k 个最大的元素，而不是第 k 个不同的元素。

示例 1:

输入: [3,2,1,5,6,4] 和 k = 2
输出: 5
示例 2:

输入: [3,2,3,1,2,4,5,5,6] 和 k = 4
输出: 4
说明:

你可以假设 k 总是有效的，且 1 ≤ k ≤ 数组的长度。

相关标签
堆
分治算法


作者：力扣 (LeetCode)
链接：https://leetcode-cn.com/leetbook/read/tencent/x5txi7/
来源：力扣（LeetCode）
著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。
