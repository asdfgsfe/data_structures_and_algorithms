658. 找到 K 个最接近的元素
给定一个排序好的数组 arr ，两个整数 k 和 x ，从数组中找到最靠近 x（两数之差最小）的 k 个数。返回的结果必须要是按升序排好的。

整数 a 比整数 b 更接近 x 需要满足：

|a - x| < |b - x| 或者
|a - x| == |b - x| 且 a < b
 

示例 1：

输入：arr = [1,2,3,4,5], k = 4, x = 3
输出：[1,2,3,4]
示例 2：

输入：arr = [1,2,3,4,5], k = 4, x = -1
输出：[1,2,3,4]
 

提示：

1 <= k <= arr.length
1 <= arr.length <= 104
数组里的每个元素与 x 的绝对值不超过 104

class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        if (k < 1 || arr.size() < k) {
            return {};
        }
        if (arr[0] >= x) {
            return vector<int>(arr.begin(), arr.begin() + k);
        }
        if (arr.back() <= x) {
            return vector<int>(arr.end() - k, arr.end());
        }
        int i = FindRightFirstMax(arr, x);
        int l = std::max(0, i - k);
        int r = std::min((int)arr.size() - 1, i + k);
        while (r - l + 1 > k) {
            if (std::abs(x - arr[l]) > std::abs(x - arr[r])) {
                ++l;
            } else {
                --r;
            }
        }
        return vector<int> (arr.begin() + l, arr.begin() + r + 1);
    }

    int FindRightFirstMax(const vector<int>& nums, int x) {
        int l = 0;
        int r = nums.size();
        while (l < r) {
            int m = l + (r - l) / 2;
            if (nums[m] > x) {
                r = m;
            } else {
                l = m + 1;
            }
        }
        return r;
    }
};
