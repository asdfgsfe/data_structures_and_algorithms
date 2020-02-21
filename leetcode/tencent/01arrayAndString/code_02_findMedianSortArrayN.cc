class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int m = nums1.size() + nums2.size();
        if (m == 0)
        {
            return 0;
        }
        if (nums1.empty())
        {
            return (m & 1) == 1 ? nums2[m / 2] : (nums2[m / 2 - 1] + nums2[m / 2]) / 2.0;
        }
        if (nums2.empty())
        {
            return (m & 1) == 1 ? nums1[m / 2] : (nums1[m / 2 - 1] + nums1[m / 2]) / 2.0;
        }
        //结束条(i+j+ 1) <= m / 2 + 1很重要 由于下表从0开始 所以加1
        int i = 0;
        int j = 0;
        int first = 0;
        int second = 0;
        while (i < nums1.size() && j < nums2.size() && (i + j + 1) <= m / 2 + 1)
        {
            second = first;
            first = nums1[i] < nums2[j] ? nums1[i++] : nums2[j++];
        }
        while (i < nums1.size() && (i + j + 1) <= m / 2 + 1)
        {
            second = first;
            first = nums1[i++];
        }
        while (j < nums2.size() && (i + j + 1) <= m / 2 + 1)
        {
            second = first;
            first = nums2[j++];
        }
        //std::cout << "f=" << first << " s=" << second << std::endl;
        return (m & 1) == 1 ? first : (first + second) / 2.0;
    }
};
