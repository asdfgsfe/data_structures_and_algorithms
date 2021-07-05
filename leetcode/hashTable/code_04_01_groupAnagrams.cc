字母异位词分组
给定一个字符串数组，将字母异位词组合在一起。字母异位词指字母相同，但排列不同的字符串。

示例:

输入: ["eat", "tea", "tan", "ate", "nat", "bat"]
输出:
[
  ["ate","eat","tea"],
  ["nat","tan"],
  ["bat"]
]
说明：

所有输入均为小写字母。
不考虑答案输出的顺序。

作者：力扣 (LeetCode)
链接：https://leetcode-cn.com/leetbook/read/hash-table/xxo631/
来源：力扣（LeetCode）
著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。

class Solution {
public:
	vector<vector<string>> groupAnagrams(vector<string>& strs) {
		if (strs.empty())
		{
			return {};
		}
		unordered_map<string, vector<string>> records;
		for (const string& str : strs)
		{
			int build[26];
            memset(build, 0, sizeof build);
			for (char ch : str)
			{
				++build[ch - 'a'];
			}
			string pattern;
			for (int i = 0; i < 26; ++i)
			{
				pattern += "_" + std::to_string(build[i]);
				//不知道为啥不能过 可能是内存超出限制了
				//pattern += (i + 'a ') + "_" + std::to_string(build[i]) + "_";
			}
			records[pattern].emplace_back(str);
		}
		vector<vector<string>> groups;
		for (auto& record : records)
		{
			groups.emplace_back(std::move(record.second));
		}
		return groups;
	}
};

//可以ac版本
class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        if (strs.empty()) {
            return {};
        }
        unordered_map<string, vector<string>> words;
        for (const auto& str : strs) {
            vector<int> builder(26, 0);
            for (char c : str) {
                ++builder[c - 'a'];
            }
            string tmp;
            for (int i = 0; i < builder.size(); ++i) {
                tmp.push_back(builder[i] + 'a');
                tmp.push_back('_');
            }
            words[std::move(tmp)].emplace_back(str);
        }
        vector<vector<string>> rets;
        for (auto& word : words) {
            rets.emplace_back(std::move(word.second));
        }
        return rets;
    }
};
