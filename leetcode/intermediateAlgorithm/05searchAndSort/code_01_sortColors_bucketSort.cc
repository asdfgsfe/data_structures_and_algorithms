class Solution {
public:
    void sortColors(vector<int>& nums) {
        if (nums.size() < 2) {
            return;
        }
        vector<int> bucket(3, 0);
        for (int n : nums) {
            ++bucket[n];
        }
        int p = 0;
        for (int i = 0; i < bucket.size(); ++i) {
            for (int j = 0; j < bucket[i]; ++j) {
                nums[p++] = i;
            }
        }
    }
};
