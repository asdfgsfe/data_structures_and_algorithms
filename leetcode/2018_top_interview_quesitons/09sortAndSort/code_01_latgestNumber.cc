最大数
给定一组非负整数 nums，重新排列每个数的顺序（每个数不可拆分）使之组成一个最大的整数。

注意：输出结果可能非常大，所以你需要返回一个字符串而不是整数。

 

示例 1：

输入：nums = [10,2]
输出："210"
示例 2：

输入：nums = [3,30,34,5,9]
输出："9534330"
示例 3：

输入：nums = [1]
输出："1"
示例 4：

输入：nums = [10]
输出："10"
 

提示：

1 <= nums.length <= 100
0 <= nums[i] <= 109
相关标签
排序


作者：力扣 (LeetCode)
链接：https://leetcode-cn.com/leetbook/read/top-interview-questions/xa1401/
来源：力扣（LeetCode）
著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。

class Solution {
public:
    string largestNumber(vector<int>& nums) {
        if (nums.empty()) {
            return "";
        }
        std::sort(nums.begin(), nums.end(), [](int lhs, int rhs) {
            string l = std::to_string(lhs) + std::to_string(rhs);
            string r = std::to_string(rhs) + std::to_string(lhs);
            return l > r;
        });
        string maxNum;
        for (int n : nums) {
            maxNum += std::to_string(n);
        }
        return maxNum[0] == '0' ? "0" : maxNum;
    }
};

//贪心算法 就是找到一种排列组合方式 使得组合出来的数字最大
//可以用对数器证明是否 正确， 绝对正确的对数器就是找到全排列 找到一种最大的排列
//感觉是一个贪心的算法 贪心算法的解法就是排序和堆 堆其实也是局部排序的一种
