class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        if (nums1.empty() || nums2.empty())
        {
            return {};
        }
        unordered_set<int> visited;
        for (int num : nums1)
        {
            visited.emplace(num);
        }
        unordered_set<int> processed;
        vector<int> nums;
        for (int num : nums2)
        {
            if (processed.count(num))
            {
                continue;
            }
            processed.emplace(num);
            if (visited.count(num))
            {
                nums.emplace_back(num);
            }
        }
        return nums;
    }
};