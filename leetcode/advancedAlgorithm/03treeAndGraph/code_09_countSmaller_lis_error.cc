
//这道题目不能用最长递增子序列模型来做 因为最长递增子序列一定是全部递增的
//比如【2， 0， 1】最长递增子序列是：【1， 0，0】
//而右侧比我小的是 [2, 0, 0] 原因是右侧比我小的可以乱序 但是最长递增 子序列一定是有序的 全部递增
class Solution {
public:
    vector<int> countSmaller(vector<int>& nums) {
        if (nums.empty()) {
            return {};
        }
        if (nums.size() < 2) {
            return {0};
        }
        vector<int> dp(nums.size());
        vector<int> ends(nums.size());
        ends[0] = nums.back();
        int right = 0;
        for (int i = nums.size() - 1; i >= 0; --i) {
            int l = 0;
            int r = right;
            while (l <= r) {
                int m = (l + r) / 2;
                if (ends[m] < nums[i]) {
                    l = m + 1;
                } else {
                    r = m - 1;
                }
            }
            right = std::max(l, right);
            ends[l] = nums[i];
            dp[i] = l;
        }
        return dp;
    }
};
