class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        if (k < 1 || nums.empty() || k == nums.size())
        {
            return;
        }
        k = k % nums.size();
        Reverse(nums, 0, nums.size() - 1);
        if (k != nums.size())
        {
            Reverse(nums, 0, k - 1);
            Reverse(nums, k, nums.size() - 1);
        }
    }
    
    void Reverse(vector<int>& nums, int l, int r)
    {
        if (l >= r)
        {
            return;
        }
        while (l < r)
        {
            std::swap(nums[l++], nums[r--]);
        }
    }
};