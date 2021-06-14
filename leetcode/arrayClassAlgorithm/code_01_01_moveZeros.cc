//移动零
//给定一个数组 nums，编写一个函数将所有 0 移动到数组的末尾，同时保持非零元素的相对顺序。
class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        if (nums.size() < 1) {
            return;
        }
        int l = 0;
        int r = 0;
        while (r < nums.size()) {
            if (nums[r] != 0) {
                std::swap(nums[l++], nums[r]);
            }
            ++r;
        }
    }
};

class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        if (nums.empty()) {
            return;
        }
        int p = 0;
        while (p < nums.size()) {
            while (p < nums.size() && nums[p] != 0) {
                ++p;
            }
            int n = p + 1;
            while (n < nums.size() && nums[n] == 0) {
                ++n;
            }
            if (n < nums.size() && p < nums.size()) {
                std::swap(nums[p], nums[n]);
            }
            ++p;
        }
    }
};
