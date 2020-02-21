class Solution {
public:
    void wiggleSort(vector<int>& nums) {
        nth_element(nums.begin(), nums.begin() + nums.size() / 2, nums.end());


        // 荷兰国旗问题将和中位数相等的数值全部集中在数组中间，否则组合之后会产生相邻元素相等的情况
        int l = 0, r = nums.size() - 1;
        int i = 0, pivot = *(nums.begin() + nums.size() / 2);
        while (i <= r) {
            if (nums[i] < pivot) {
                swap(nums[i], nums[l]);
                l++; i++;
            } else if (nums[i] == pivot) {
                i++;
            } else {
                swap(nums[i], nums[r]);
                r--;
            }
        }

        vector<int> tmp;
        int pos1 = (nums.size() % 2  == 0) ? nums.size() / 2 - 1 : nums.size() / 2;
        int pos2 = nums.size() - 1;

        for (int i = 0; i < nums.size(); i++) {
            if (i % 2 == 0) {
                tmp.push_back(nums[pos1--]);
            } else {
                tmp.push_back(nums[pos2--]);
            }
        }

        std::copy(tmp.begin(), tmp.end(), nums.begin());
    }
};

作者：hao-shou-bu-juan
链接：https://leetcode-cn.com/problems/wiggle-sort-ii/solution/c-ji-bai-100yong-hu-by-hao-shou-bu-juan/
来源：力扣（LeetCode）
著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。
