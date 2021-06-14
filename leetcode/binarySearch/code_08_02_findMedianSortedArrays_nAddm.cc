寻找两个正序数组的中位数
给定两个大小分别为 m 和 n 的正序（从小到大）数组 nums1 和 nums2。请你找出并返回这两个正序数组的 中位数 。

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        if (nums1.empty() && nums2.empty()) {
            return 0x80000000;
        }
        int n = nums1.size() + nums2.size();
        int first;
        int second;
        int p = 0;
        int i = 0;
        int j = 0;
		//p <= n / 2很重要
        while (i < nums1.size() && j < nums2.size() && p <= n / 2) {
             first = second;
            if (nums1[i] < nums2[j]) {
                second = nums1[i];
                ++i;
            } else {
                second = nums2[j];
                ++j;
            }
            ++p;
        }
        while (i < nums1.size() && p <= n / 2) {
            first = second;
            second = nums1[i++];
            ++p;
        }
        while (j < nums2.size() && p <= n / 2) {
            first = second;
            second = nums2[j++];
            ++p;
        }
        return n % 2 == 0 ? (first + second) / 2.0 : second;
    }
};
