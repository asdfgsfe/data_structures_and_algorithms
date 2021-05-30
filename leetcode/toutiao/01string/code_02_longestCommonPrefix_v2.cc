class Solution {
struct Trie {
    struct Node {
        int path;
        int end;
        vector<Node*> nexts;
        Node() : path(0), end(0), nexts(26, nullptr) {}
    };
    Trie() : root(new Node) {}

    void Insert(const string& word) {
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
            int id = word[i] - 'a';
            if (!node->nexts[id]) {
                return i;
            }
            node = node->nexts[id];
        }
        return word.size();
    }

    Node* root;
};

public:
    string longestCommonPrefix(vector<string>& strs) {
        if (strs.empty()) {
            return "";
        }
        Trie trie;
        trie.Insert(strs[0]);
        int longgest = strs[0].size();
        for (int i = 1; i < strs.size(); ++i) {
            longgest = std::min(longgest, trie.Prefix(strs[i]));
            trie.Insert(strs[i]);
        }
        return strs[0].substr(0, longgest);
    }
};

//14. 最长公共前缀
