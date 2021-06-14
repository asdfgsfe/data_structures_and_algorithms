数组中的第K个最大元素
在未排序的数组中找到第 k 个最大的元素。请注意，你需要找的是数组排序后的第 k 个最大的元素，而不是第 k 个不同的元素。



class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        if (nums.empty() || k < 0 || k > nums.size()) {
            return 0x80000000;
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
