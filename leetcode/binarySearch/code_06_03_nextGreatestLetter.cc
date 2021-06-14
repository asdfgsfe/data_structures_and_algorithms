寻找比目标字母大的最小字母
给你一个排序后的字符列表 letters ，列表中只包含小写英文字母。另给出一个目标字母 target，请你寻找在这一有序列表里比目标字母大的最小字母。

在比较时，字母是依序循环出现的。举个例子：

如果目标字母 target = 'z' 并且字符列表为 letters = ['a', 'b']，则答案返回 'a'
 

示例：

输入:
letters = ["c", "f", "j"]
target = "a"
输出: "c"

输入:
letters = ["c", "f", "j"]
target = "c"
输出: "f"

输入:
letters = ["c", "f", "j"]
target = "d"
输出: "f"

输入:
letters = ["c", "f", "j"]
target = "g"
输出: "j"

输入:
letters = ["c", "f", "j"]
target = "j"
输出: "c"

输入:
letters = ["c", "f", "j"]
target = "k"
输出: "c"
 

提示：

letters长度范围在[2, 10000]区间内。
letters 仅由小写字母组成，最少包含两个不同的字母。
目标字母target 是一个小写字母。


作者：力扣 (LeetCode)
链接：https://leetcode-cn.com/leetbook/read/binary-search/xeiuui/
来源：力扣（LeetCode）
著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。

//可以考虑leetcode的简单放发
class Solution {
public:
	char nextGreatestLetter(vector<char>& letters, char target) {
		if (letters.empty())
		{
			return 'a';
		}
		int l = 0;
		int r = letters.size() - 1;
		int tail = -1;
		while (l <= r)
		{
			int m = l + (r - l) / 2;
			if (letters[m] <= target)
			{

				l = m + 1;
			}
			else
			{
				tail = m;
				r = m - 1;
			}
		}
		tail = tail == -1 ? 0 : tail;
		int more = letters[tail] == target ? tail + 1 : tail;
		more = more == letters.size() ? 0 : more;
		return letters[more];
	}
};

class Solution {
public:
    char nextGreatestLetter(vector<char>& letters, char target) {
        if (letters.empty()) {
            return '0';
        }
        int l = 0;
        int r = letters.size();
        while (l < r) {
            int m = l + (r - l) / 2;
            if (letters[m] > target) {
                r = m;
            } else {
                l = m + 1;
            }
        }
       if (l == letters.size()) {
           return letters[0];
       }
       return letters[r];
    }
};
