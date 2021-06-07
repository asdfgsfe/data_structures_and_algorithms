class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        if (nums.size() < 2) {
            return false;
        }
        unordered_map<int, int> sumToIds;
        sumToIds[0] = -1;
        int sum = 0;
        for (int i = 0; i < nums.size(); ++i) {
            //当 prefixSums[q]−prefixSums[p] 为 k 的倍数时
            //prefixSums[p] 和prefixSums[q] 除以 kk 的余数相同。
            //因此只需要计算每个下标对应的前缀和除以 kk 的余数即可，使用哈希表存储每个余数第一次出现的下标。

            sum = (sum + nums[i]) % k;
            if (sumToIds.count(sum)) {
                int pre = sumToIds[sum];
                if (i - pre >= 2) {
                    return true;
                }
                continue;
            }
            //注意这里 由于有子数组长度大于2的限制，
            //类似于找最长的子串 所以这里已经添加过了该sum的最左边的i了， 就不用在添加了了
            sumToIds[sum] = i;
        }
        return false;
    }
};

523. 连续的子数组和
给你一个整数数组 nums 和一个整数 k ，编写一个函数来判断该数组是否含有同时满足下述条件的连续子数组：

子数组大小 至少为 2 ，且
子数组元素总和为 k 的倍数。
如果存在，返回 true ；否则，返回 false 。

如果存在一个整数 n ，令整数 x 符合 x = n * k ，则称 x 是 k 的一个倍数。



示例 1：

输入：nums = [23,2,4,6,7], k = 6
输出：true
解释：[2,4] 是一个大小为 2 的子数组，并且和为 6 。
示例 2：

输入：nums = [23,2,6,4,7], k = 6
输出：true
解释：[23, 2, 6, 4, 7] 是大小为 5 的子数组，并且和为 42 。
42 是 6 的倍数，因为 42 = 7 * 6 且 7 是一个整数。
示例 3：

输入：nums = [23,2,6,4,7], k = 13
输出：false


提示：

1 <= nums.length <= 105
0 <= nums[i] <= 109
0 <= sum(nums[i]) <= 231 - 1
1 <= k <= 231 - 1

