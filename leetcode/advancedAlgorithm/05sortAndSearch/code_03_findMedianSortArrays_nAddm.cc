寻找两个正序数组的中位数
给定两个大小分别为 m 和 n 的正序（从小到大）数组 nums1 和 nums2。请你找出并返回这两个正序数组的 中位数 。

 

示例 1：

输入：nums1 = [1,3], nums2 = [2]
输出：2.00000
解释：合并数组 = [1,2,3] ，中位数 2
示例 2：

输入：nums1 = [1,2], nums2 = [3,4]
输出：2.50000
解释：合并数组 = [1,2,3,4] ，中位数 (2 + 3) / 2 = 2.5
示例 3：

输入：nums1 = [0,0], nums2 = [0,0]
输出：0.00000
示例 4：

输入：nums1 = [], nums2 = [1]
输出：1.00000
示例 5：

输入：nums1 = [2], nums2 = []
输出：2.00000
 

提示：

nums1.length == m
nums2.length == n
0 <= m <= 1000
0 <= n <= 1000
1 <= m + n <= 2000
-106 <= nums1[i], nums2[i] <= 106
 

进阶：你能设计一个时间复杂度为 O(log (m+n)) 的算法解决此问题吗？

相关标签
数组
二分查找
分治

作者：力扣 (LeetCode)
链接：https://leetcode-cn.com/leetbook/read/top-interview-questions-hard/xdvy3h/
来源：力扣（LeetCode）
著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int first;
        int second;
        int n = (nums1.size() + nums2.size());
        int p = 0;
        int i = 0;
        int j = 0;
        while (i < nums1.size() && j < nums2.size() && p <= n / 2) {
            second = first;
            ++p;
            if (nums1[i] < nums2[j]) {
                first = nums1[i++];
            } else {
                first = nums2[j++];
            }
        }
        while (i < nums1.size() && p <= n / 2) {
            second = first;
            first = nums1[i++];
            ++p;
        }
        while (j < nums2.size() && p <= n / 2) {
            second = first;
            first = nums2[j++];
            ++p;
        }
        return n % 2 == 0 ? (second + first) / 2.0 : first;
    }
};class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int first;
        int second;
        int n = (nums1.size() + nums2.size());
        int p = 0;
        int i = 0;
        int j = 0;
        while (i < nums1.size() && j < nums2.size() && p <= n / 2) {
            second = first;
            ++p;
            if (nums1[i] < nums2[j]) {
                first = nums1[i++];
            } else {
                first = nums2[j++];
            }
        }
        while (i < nums1.size() && p <= n / 2) {
            second = first;
            first = nums1[i++];
            ++p;
        }
        while (j < nums2.size() && p <= n / 2) {
            second = first;
            first = nums2[j++];
            ++p;
        }
        return n % 2 == 0 ? (second + first) / 2.0 : first;
    }
};
