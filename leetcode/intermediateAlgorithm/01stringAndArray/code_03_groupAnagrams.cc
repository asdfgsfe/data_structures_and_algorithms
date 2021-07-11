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
相关标签
哈希表
字符串
排序

作者：力扣 (LeetCode)
链接：https://leetcode-cn.com/leetbook/read/top-interview-questions-medium/xvaszc/
来源：力扣（LeetCode）
著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        if (strs.empty()) {
            return {};
        }
        unordered_map<string, vector<string>> groupWords;
        for (string& s : strs) {
            vector<int> build(26, 0);
            for (char c : s) {
                ++build[c - 'a'];
            }
            string key;
            for (int i = 0; i < build.size(); ++i) {
                key.push_back(i + 'a');
                key += std::to_string(build[i]) + "_";
            }
            groupWords[key].emplace_back(s);
        }
        vector<vector<string>> ret;
        for (auto& word : groupWords) {
            ret.emplace_back(word.second.begin(), word.second.end());
        }
        return ret;
    }
};
