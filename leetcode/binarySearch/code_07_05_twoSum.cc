//两数之和 II - 输入有序数组

class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        if (numbers.size() < 2) {
            return {};
        }
        int l = 0;
        int r = numbers.size() - 1;
        while (l < r) {
            int m = numbers[l] + numbers[r];
            if (m == target) {
                return vector<int> {l + 1, r + 1};
            } else if (m > target) {
                --r;
            } else {
                ++l;
            }
        }
        return {};
    }
};
