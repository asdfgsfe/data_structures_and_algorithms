class Solution {
public:
    struct Node
    {
        vector<Node*> nexts;
        Node()
            : nexts(26, nullptr)
            {}
    };
    class TrieTree
    {
    public:
        TrieTree()
            : root_(new Node)
            {}
        
        void Insert(const string& word)
        {
            Node* cur = root_;
            for (char ch : word)
            {
                if (!cur->nexts[ch - 'a'])
                {
                    cur->nexts[ch - 'a'] = new Node;
                }
                cur = cur->nexts[ch - 'a'];
            }
        }
        
        int PrefixNum(const string& word)
        {
            int prefix = 0;
            Node* cur = root_;
            for (char ch : word)
            {
                if (cur->nexts[ch - 'a'])
                {
                    ++prefix;
                }
                else
                {
                    cur->nexts[ch - 'a'] = new Node;
                }
                cur = cur->nexts[ch - 'a'];
            }
            return prefix;
        }
        
        
    private:
        Node* root_;
    };
    string longestCommonPrefix(vector<string>& strs) {
        if (strs.empty())
        {
            return string();
        }
        if (strs.size() == 1)
        {
            return strs[0];
        }
        TrieTree sTrie;
        sTrie.Insert(strs[0]);
        int lcsPre = 0x7fffffff;
        for (const auto& str : strs)
        {
            lcsPre = std::min(lcsPre, sTrie.PrefixNum(str));
            sTrie.Insert(str);
        }
        return lcsPre == 0 ? string() : strs[0].substr(0, lcsPre);
    }
};
