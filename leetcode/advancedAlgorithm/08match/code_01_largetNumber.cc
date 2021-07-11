class Solution {
public:
    string largestNumber(vector<int>& nums) {
        if (nums.empty()) {
            return "";
        }
        std::sort(nums.begin(), nums.end(), [](int l, int r) {
            string lhs = std::to_string(l);
            string rhs = std::to_string(r);
            return lhs + rhs > rhs + lhs;
        });
        string num;
        for (int n : nums) {
            num += std::to_string(n);
        }
        return num[0] == '0' ? "0" : num;
    }最大数
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
贪心
字符串
排序
本节内容是否对您有帮助？
1


作者：力扣 (LeetCode)
链接：https://leetcode-cn.com/leetbook/read/top-interview-questions-hard/xd3jrg/
来源：力扣（LeetCode）
著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。
};


