 class Solution {
 public:
	 int titleToNumber(string s) {
		 unordered_map<char, int> charToNums;
		 for (int i = 0; i < 26; ++i)
		 {
			 charToNums['A' + i] = i + 1;
		 }
		 long long num = 0;
		 for (char ch : s)
		 {
			 num = num * 26 + charToNums[ch];
		 }
		 return (int)num;
	 }
 };

class Solution {
public:
    int titleToNumber(string columnTitle) {
        if (columnTitle.empty()) {
            return 0;
        }
        //不采用hash表 直接算
        int n = 0;
        for (char ch : columnTitle) {
            n = n * 26 + (ch - 'A' + 1);
        }
        return n;
    }
};

Excel表列序号
给定一个Excel表格中的列名称，返回其相应的列序号。

例如，

    A -> 1
    B -> 2
    C -> 3
    ...
    Z -> 26
    AA -> 27
    AB -> 28
    ...
示例 1:

输入: "A"
输出: 1
示例 2:

输入: "AB"
输出: 28
示例 3:

输入: "ZY"
输出: 701

作者：力扣 (LeetCode)
链接：https://leetcode-cn.com/leetbook/read/top-interview-questions/xa6dkt/
来源：力扣（LeetCode）
著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。
