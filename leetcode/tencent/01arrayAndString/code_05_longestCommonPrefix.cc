�����ǰ׺
��дһ�������������ַ��������е������ǰ׺��

��������ڹ���ǰ׺�����ؿ��ַ��� ""��

ʾ�� 1:

����: ["flower","flow","flight"]
���: "fl"
ʾ�� 2:

����: ["dog","racecar","car"]
���: ""
����: ���벻���ڹ���ǰ׺��
˵��:

��������ֻ����Сд��ĸ a-z

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
            int i = c - 'a';
            if (!node->nexts[i]) {
                node->nexts[i] = new Node;
            }
            node = node->nexts[i];
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
            cout << longgest << endl;
            trie.Insert(strs[i]);
        }
        return strs[0].substr(0, longgest);
    }
};
