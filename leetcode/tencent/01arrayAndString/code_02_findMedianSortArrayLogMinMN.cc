class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int size = nums1.size() + nums2.size();
        if (size == 0)
        {
            return 0.0;
        }
        if (nums1.empty())
        {
            return (size & 1) == 1 ? nums2[size / 2] : (nums2[size / 2 - 1] + nums2[size / 2]) / 2.0;
        }
        if (nums2.empty())
        { 
            return (size & 1) == 1 ? nums1[size / 2] : (nums1[size / 2 - 1] + nums1[size / 2]) / 2.0;
        }
        vector<int> less = nums1;
        vector<int> more = nums2;
        if (nums2.size() < nums1.size())
        {
            less = nums2;
            more = nums1;
        }
        int m = less.size();
        int n = more.size();
        int l = 0;
        int r = m;
        int half = (m + n + 1) / 2;
        while (l <= r)
        {
            int i = (l + r) / 2;
            int j = half - i;
            if (i < r && more[j - 1] > less[i])
            {
                l = i + 1;
            }
            else if (i > l && less[i - 1] > more[j])
            {
                r = i - 1;
            }
            else
            {
                int maxLeft = 0;
                if (i == 0)
                {
                    maxLeft = more[j - 1];
                }
                else if (j == 0)
                {
                    maxLeft = less[i - 1];
                }
                else
                {
                    maxLeft = std::max(less[i - 1], more[j - 1]);
                }
                if ((size & 1) == 1)
                {
                    return maxLeft;
                }
                int minRight = 0;
                if (i == m)
                {
                    minRight = more[j];
                }
                else if (j == n)
                {
                    minRight = less[i];
                }
                else
                {
                    minRight = std::min(more[j], less[i]);
                }
                return (maxLeft + minRight) / 2.0;
            }
        }
        return 0.0;
    }
};
