class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        if (nums1.empty() && nums2.empty()) {
            return 0.0;
        }
        vector<int>& more = nums1;
        vector<int>& less = nums2;
        if (nums1.size() < nums2.size()) {
            std::swap(more, less);
        }
        int l = 0;
        int r = less.size();
        int half = (more.size() + less.size() + 1) / 2;
        while (l <= r) {
            int i = (l + r) / 2;
            int j = half - i;
            if (i > l && less[i - 1] > more[j]) {
                r = i - 1;
            } else if (i < r && more[j - 1] > less[i]) {
                l = i + 1;
            } else {
                int maxLeft;
                if (i == 0) {
                    maxLeft = more[j - 1];
                } else if (j == 0) {
                    maxLeft = less[i - 1];
                } else {
                    maxLeft = std::max(less[i - 1], more[j - 1]);
                }
                if (((more.size() + less.size()) & 0x01) == 0x01) {
                    return maxLeft;
                }
                int minRight;
                if (i == less.size()) {
                    minRight = more[j];
                } else if (j == more.size()) {
                    minRight = less[i];
                } else {
                    minRight = std::min(less[i], more[j]);
                }
                return (maxLeft + minRight) / 2.0;
            }
        }
        return 0.0;
    }
};
