缺失的第一个正数
给你一个未排序的整数数组 nums ，请你找出其中没有出现的最小的正整数。

请你实现时间复杂度为 O(n) 并且只使用常数级别额外空间的解决方案。
 

示例 1：

输入：nums = [1,2,0]
输出：3
示例 2：

输入：nums = [3,4,-1,1]
输出：2
示例 3：

输入：nums = [7,8,9,11,12]
输出：1
 

提示：

1 <= nums.length <= 5 * 105
-231 <= nums[i] <= 231 - 1
相关标签
数组
哈希表

作者：力扣 (LeetCode)
链接：https://leetcode-cn.com/leetbook/read/top-interview-questions-hard/xwkftg/
来源：力扣（LeetCode）
著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。

class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        bool isMissOne = true;
        //检查数组中是否包含1 如果未包含直接返回 否则将<=0 和 > nums.size()的数字换为1， 因为1已经出现过 换了不妨碍
        //这样转换完之后 数组中就全部是正数了
        for (int i = 0; i < nums.size(); ++i) {
            if (nums[i] == 1) {
                isMissOne = false;
            }
            if (nums[i] <= 0 || nums[i] > nums.size()) {
                nums[i] = 1;
            }
        }
        if (isMissOne) {
            return 1;
        }
        //使用索引和数字符号作为检查器
        //例如，如果 nums[1] 是负数表示在数组中出现了数字 `1`
        //如果 nums[2] 是正数 表示数字 2 没有出现
        for (int i = 0; i < nums.size(); ++i) {
            //如果发现了一个数字a 改变第a个元素的符号， 把元素设置为负数 表示已经出现过
            //注意重复元素只需操作一次
            int a = std::abs(nums[i]);
            if (a == nums.size()) { //由于第一个位置一定放1， 而且1之前已经出现过 所以这个位置可以重复利用 不影响1的结论
                nums[0] = -std::abs(nums[0]);
            } else {
                nums[a] = -std::abs(nums[a]); //等于将a放到nums[a]位置 nums[i] = nums[nums[i]]
            }
        }
        //如果这个位置未被设置 那么必然是答案 未出现
        for (int i = 1; i < nums.size(); ++i) {
            if (nums[i] > 0) {
                return i;
            }
        }
        //0设置的是 nums.size()
        if (nums[0] > 0) {
            return nums.size();
        }
        //全部出现
        return nums.size() + 1;
    }
};
