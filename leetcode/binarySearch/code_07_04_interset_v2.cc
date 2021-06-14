//两个数组的交集 II

class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        if (nums1.empty() || nums2.empty()) {
            return {};
        }
        unordered_map<int, int> numTimes;
        for (int n : nums1) {
            ++numTimes[n];
        }
        vector<int> ret;
        for (int n : nums2) {
            auto times = numTimes.find(n);
            if (times != numTimes.end() && times->second > 0) {
                --times->second;
                ret.push_back(n);
            }
        }
        return ret;
    }
};
