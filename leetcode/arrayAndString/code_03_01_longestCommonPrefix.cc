最长公共前缀
编写一个函数来查找字符串数组中的最长公共前缀。

如果不存在公共前缀，返回空字符串 ""。

 

示例 1：

输入：strs = ["flower","flow","flight"]
输出："fl"
示例 2：

输入：strs = ["dog","racecar","car"]
输出：""
解释：输入不存在公共前缀。
 

提示：

0 <= strs.length <= 200
0 <= strs[i].length <= 200
strs[i] 仅由小写英文字母组成


作者：力扣 (LeetCode)
链接：https://leetcode-cn.com/leetbook/read/array-and-string/ceda1/
来源：力扣（LeetCode）
著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。

class Solution {
struct Node {
    int path;
    int end;
    vector<Node*> nexts;

    Node() : path(0), end(0), nexts(26, nullptr) {}
};

struct TrieNode {
    Node* root;

    TrieNode() : root(new Node) {}

    void AddNode(const string& word) {
        if (word.empty()) {
            return;
        }
        Node* node = root;
        for (char c : word) {
            if (!node->nexts[c - 'a']) {
                node->nexts[c - 'a'] = new Node;
            }
            node = node->nexts[c - 'a'];
            ++node->path;
        }
        ++node->end;
    }

    int Prefix(const string& word) {
        Node* node = root;
        for (int i = 0; i < word.size(); ++i) {
            int idx = word[i] - 'a';
            if (!node->nexts[idx]) {
                return i;
            }
            node = node->nexts[idx];
        }
        return word.size();
    }
};

public:
    string longestCommonPrefix(vector<string>& strs) {
        if (strs.empty() || strs[0].empty()) {
            return "";
        }
        TrieNode trie;
        trie.AddNode(strs[0]);
        int prefix = strs[0].size();
        for (int i = 1; i < strs.size(); ++i) {
            prefix = std::min(prefix, trie.Prefix(strs[i]));
            trie.AddNode(strs[i]);
        }
        return strs[0].substr(0, prefix);
    }
};
