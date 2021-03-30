class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        if (nums.empty() || k < 1 || k > nums.size())
        {
            return 0x7fffffff;
        }
        for (int i = k / 2; i >= 0; --i)
        {
            PercDown(nums, i, k);
        }
        for (int i = k; i < nums.size(); ++i)
        {
            if (nums[i] > nums[0])
            {
                std::swap(nums[0], nums[i]);
                PercDown(nums, 0, k);
            }
        }
        return nums[0];
    }
    
    void PercDown(vector<int>& nums, int i, int n)
    {
        int child = 2 * i + 1;
        while (child < n)
        {
            if (child + 1 < n && nums[child + 1] < nums[child])
            {
                ++child;
            }
            if (nums[i] < nums[child])
            {
                break;
            }
            std::swap(nums[i], nums[child]);
            i = child;
            child = 2 * i + 1;
        }
    }
};


215. 数组中的第K个最大元素
在未排序的数组中找到第 k 个最大的元素。请注意，你需要找的是数组排序后的第 k 个最大的元素，而不是第 k 个不同的元素。

示例 1:

输入: [3,2,1,5,6,4] 和 k = 2
输出: 5
示例 2:

输入: [3,2,3,1,2,4,5,5,6] 和 k = 4
输出: 4
说明:

你可以假设 k 总是有效的，且 1 ≤ k ≤ 数组的长度。
