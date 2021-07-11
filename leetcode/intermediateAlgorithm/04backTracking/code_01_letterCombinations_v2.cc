电话号码的字母组合
给定一个仅包含数字 2-9 的字符串，返回所有它能表示的字母组合。答案可以按 任意顺序 返回。

给出数字到字母的映射如下（与电话按键相同）。注意 1 不对应任何字母。



 

示例 1：

输入：digits = "23"
输出：["ad","ae","af","bd","be","bf","cd","ce","cf"]
示例 2：

输入：digits = ""
输出：[]
示例 3：

输入：digits = "2"
输出：["a","b","c"]
 

提示：

0 <= digits.length <= 4
digits[i] 是范围 ['2', '9'] 的一个数字。
相关标签
哈希表
字符串
回溯

作者：力扣 (LeetCode)
链接：https://leetcode-cn.com/leetbook/read/top-interview-questions-medium/xv8ka1/
来源：力扣（LeetCode）
著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。

class Solution {
public:
    vector<string> letterCombinations(string digits) {
        if (digits.empty()) {
            return {};
        }
        const static unordered_map<char, vector<char>> dict {{'2', {'a', 'b', 'c'}}, //注意这里val可以用字符串
                                                             {'3', {'d', 'e', 'f'}},
                                                             {'4', {'g', 'h', 'i'}},
                                                             {'5', {'j', 'k', 'l'}},
                                                             {'6', {'m', 'n', 'o'}},
                                                             {'7', {'p', 'q', 'r', 's'}},
                                                             {'8', {'t', 'u', 'v'}},
                                                             {'9', {'w', 'x', 'y', 'z'}}};
        string one;
        vector<string> all;
        ReplaceProcess(digits, 0, one, all, dict);
        return all;
    }

     void ReplaceProcess(const string& s, int i, string& one, vector<string>& all, const unordered_map<char, vector<char>>& dict) {
        if(i == s.size()) {
            all.emplace_back(one);
            return;
        }
        auto it = dict.find(s[i]);
        if (it == dict.end()) {
            return;
        }
        for (char c : it->second) {
            one.push_back(c);
            ReplaceProcess(s, i + 1, one, all, dict);
            one.pop_back();
        }
     }
};
