同构字符串
给定两个字符串 s 和 t，判断它们是否是同构的。

如果 s 中的字符可以按某种映射关系替换得到 t ，那么这两个字符串是同构的。

每个出现的字符都应当映射到另一个字符，同时不改变字符的顺序。不同字符不能映射到同一个字符上，相同字符只能映射到同一个字符上，字符可以映射到自己本身。

 

示例 1:

输入：s = "egg", t = "add"
输出：true
示例 2：

输入：s = "foo", t = "bar"
输出：false
示例 3：

输入：s = "paper", t = "title"
输出：true
 

提示：

可以假设 s 和 t 长度相同。

作者：力扣 (LeetCode)
链接：https://leetcode-cn.com/leetbook/read/hash-table/xhjvbj/
来源：力扣（LeetCode）
著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。

class Solution {
public:
	bool isIsomorphic(string s, string t) {
		if (s.empty())
		{
			return t.empty();
		}
		if (t.empty())
		{
			return s.empty();
		}
		if (s.size() != t.size())
		{
			return false;
		}
		vector<int> sTot(256, -1);
		vector<int> tTos(256, -1);
		int i = 0;
		int j = 0;
		while (i < s.size() && j < t.size())
		{
			if (sTot[s[i]] == -1 && tTos[t[j]] == -1)
			{
				//由于要保持字符串的相对顺序 s[i]对于的位置 只能通过t[j] 替换 而且i==j
				sTot[s[i]] = t[j];
				tTos[t[j++]] = s[i++];
				continue;
			}
			if (sTot[s[i]] == -1 || tTos[t[j]] == -1)
			{
				return false;
			}
			if (sTot[s[i]] != t[j] || tTos[t[j]] != s[i])
			{
				return false;
			}
			++i;
			++j;
		}
		return true;
	}
};
