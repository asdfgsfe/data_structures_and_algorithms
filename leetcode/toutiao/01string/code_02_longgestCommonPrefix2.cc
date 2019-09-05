//第二种方式是预先把所有的字符串建到前缀树中 然后拿数组中任意一个串去做遍历 要想是公共前缀则这条路上的path必然等于数组的总长度
//第一种方式是 先把第一个串建立到前缀树中 然后遍历数组的其他串做前缀匹配 记录前缀是多少 然后将自己在插入到树里面 最后所有前缀取最小值 就是答案
class Solution {
public:
    struct Node
    {
        Node() : nexts(26, nullptr) {}
        vector<Node*> nexts;
        int path = 0;
    };
    
    class TrieTree
    {
    public:
        TrieTree() : root_(new Node) {}
        void Insert(const string& str)
        {
            Node* cur = root_;
            for (char ch : str)
            {
                if (!cur->nexts[ch - 'a'])
                {
                    cur->nexts[ch - 'a'] = new Node;
                }
                cur = cur->nexts[ch - 'a'];
                ++cur->path;
            }
        }
            
        string Prefix(const string& str, int len) const
        {
            Node* cur = root_;
            int dep = 0;
            for (char ch : str)
            {
                if (!cur->nexts[ch - 'a'] || cur->nexts[ch - 'a']->path != len)
                {
                    break;
                }
                ++dep;
                cur = cur->nexts[ch - 'a'];
            }
            std::cout << dep << std::endl;
            return str.substr(0, dep);
        }
            
    private:
        Node* root_;
    };

    string longestCommonPrefix(vector<string>& strs) {
        if (strs.empty())
        {
            return string();
        }
        TrieTree tree;
        for (const string& str : strs)
        {
            tree.Insert(str);
        }
        return tree.Prefix(strs[0], strs.size());
    }
};
