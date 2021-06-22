剑指 Offer 38. 字符串的排列
输入一个字符串，打印出该字符串中字符的所有排列。

 

你可以以任意顺序返回这个字符串数组，但里面不能有重复元素。

 

示例:

输入：s = "abc"
输出：["abc","acb","bac","bca","cab","cba"]
 

限制：

1 <= s 的长度 <= 8



//不重复的全排列
class Solution {
public:
    vector<string> permutation(string s) {
        if (s.empty()) {
            return {};
        }
        vector<string> ret;
        permutationProcess(s, 0, ret);
        return ret;
    }

    void permutationProcess(string& s, int i, vector<string>& ret) {
        if (i == s.size()) {
            ret.emplace_back(s);
            return;
        }
        //去重逻辑 如果这个字符和后面交换过了 就不用在交换了
        vector<int> visited(26, 0);
        for (int k = i; k < s.size(); ++k) {
            if (visited[s[k] - 'a'] == 0) {
                std::swap(s[i], s[k]);
                permutationProcess(s, i + 1, ret);
                std::swap(s[i], s[k]);
                visited[s[k] - 'a'] = 1;
            }
        }
    }
};
