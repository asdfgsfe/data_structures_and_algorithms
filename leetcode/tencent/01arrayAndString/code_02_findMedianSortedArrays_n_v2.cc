class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int first;
        int second;
        int k = -1;
        int i = 0;
        int j = 0;
        int n = nums1.size() + nums2.size();
        while (i < nums1.size() && j < nums2.size()) {
            first = second;
            if (nums1[i] <= nums2[j]) {
                second = nums1[i++];
            } else {
                second = nums2[j++];
            }
            if (++k == n / 2) {
                break;
            }
        }
        while (i < nums1.size() && k != n / 2) {
            first = second;
            second = nums1[i++];
            ++k;
        }
        while (j < nums2.size() && k != n / 2) {
            first = second;
            second = nums2[j++];
            ++k;
        //注意这里 除2.0容易写成2
        return n % 2 == 0 ? (first + second) / 2.0 : second;
    }
};
