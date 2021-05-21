class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        if (nums.empty()) {
            return 0x7fffffff;
        }
        std::sort(nums.begin(), nums.end());
        int closeNum = 0x7fffffff;
        for (int i = 0; i < nums.size(); ++i) {
            if (i > 0 && nums[i] == nums[i - 1]) {
                continue;
            }
            int l = i + 1;
            int r = nums.size() - 1;
            while (l < r) {
                int sum = nums[i] + nums[l] + nums[r];
                int curDiff = std::abs(target - sum);
                int preDiff = closeNum == 0x7fffffff ? 0x7fffffff : std::abs(target - closeNum);
                if (curDiff < preDiff) {
                    closeNum = sum;
                }
                if (sum == target) {
                    return target;
                } else if (target < sum) {
                    --r;
                    while (l < r && nums[r] == nums[r + 1]) {
                        --r;
                    }
                } else {
                    ++l;
                    while (l < r && nums[l] == nums[l - 1]) {
                        ++l;
                    }
                }
            }
        }
        return closeNum;
    }
};

最接近的三数之和
给定一个包括 n 个整数的数组 nums 和 一个目标值 target。找出 nums 中的三个整数，使得它们的和与 target 最接近。返回这三个数的和。假定每组输入只存在唯一答案。

 

示例：

输入：nums = [-1,2,1,-4], target = 1
输出：2
解释：与 target 最接近的和是 2 (-1 + 2 + 1 = 2) 。
 

提示：

3 <= nums.length <= 10^3
-10^3 <= nums[i] <= 10^3
-10^4 <= target <= 10^4
相关标签
数组
双指针

作者：力扣 (LeetCode)
链接：https://leetcode-cn.com/leetbook/read/tencent/xx4l3g/
来源：力扣（LeetCode）
著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。
