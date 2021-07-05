//两个数组的交集
//
//hash
class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
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
                times->second = 0;
                ret.push_back(n);
            }
        }
        return ret;
    }
};

//排序
class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        if (nums1.empty() || nums2.empty()) {
            return {};
        }
        vector<int>& l = nums1;
        vector<int>& r = nums2;
        if (l.size() < r.size()) {
            l = nums2;
            r = nums1;
        }
        std::sort(l.begin(), l.end());
        unordered_set<int> ans;
        for (int n : r) {
            int i = FindCurNum(l, n);
            if (i != -1) {
                ans.emplace(n);
            }
        }
        return vector<int>(ans.begin(), ans.end());
    }

    int FindCurNum(const vector<int>& nums, int t) {
        int l = 0;
        int r = nums.size() - 1;
        while (l <= r) {
            int m = l + (r - l) / 2;
            if (nums[m] == t) {
                return m;
            } else if (nums[m] > t) {
                r = m - 1;
            } else {
                l = m + 1;
            }
        }
        return -1;
    }
};
