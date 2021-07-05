字符串中的第一个唯一字符
给定一个字符串，找到它的第一个不重复的字符，并返回它的索引。如果不存在，则返回 -1。

 

示例：

s = "leetcode"
返回 0

s = "loveleetcode"
返回 2
 

提示：你可以假定该字符串只包含小写字母。

相关标签
队列
哈希表
字符串
计数


作者：力扣 (LeetCode)
链接：https://leetcode-cn.com/leetbook/read/hash-table/xxx94s/
来源：力扣（LeetCode）
著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。

class Solution {
public:
	int firstUniqChar(string s) {
		if (s.empty())
		{
			return -1;
		}
		vector<int> charToIds(256, -1);
		for (int i = 0; i < s.size(); ++i)
		{
			charToIds[s[i]] = charToIds[s[i]] == -1 ? i : -2;
		}
		int first = 0x7fffffff;
		for (int id : charToIds)
		{
			if (id != -1 && id != -2)
			{
				first = std::min(first, id);
			}
		}
		return first == 0x7fffffff ? -1 : first;
	}
};
