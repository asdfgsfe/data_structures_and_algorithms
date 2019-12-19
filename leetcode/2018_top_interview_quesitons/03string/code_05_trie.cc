class Trie {
    struct Node
    {
        int path = 0;
        int end = 0;
        vector<Node*> nexts;
        Node() : path(0), end(0), nexts(26, nullptr) {}
    };
public:
    /** Initialize your data structure here. */
    Trie() 
        : root_(new Node)
    {
        
    }
    
    /** Inserts a word into the trie. */
    void insert(string word) {
        if (word.empty())
        {
            return;
        }
        Node* node = root_;
        for (char ch : word)
        {
            int id = ch - 'a';
            if (!node->nexts[id])
            {
                node->nexts[id] = new Node;
            }
            node = node->nexts[id];
            ++node->path;
        }
        ++node->end;
    }
    
    /** Returns if the word is in the trie. */
    bool search(string word) {
        if (word.empty())
        {
            return false;
        }
        Node* node = root_;
        for (char ch : word)
        {
            int id = ch - 'a';
            if (!node->nexts[id])
            {
                return false;
            }
            node = node->nexts[id];
        }
        return node->end > 0;
    }
    
    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
        if (prefix.empty())
        {
            return false;
        }
        Node* node = root_;
        for (char ch : prefix)
        {
            int id = ch - 'a';
            if (!node->nexts[id])
            {
                return false;
            }
            node = node->nexts[id];
        }
        return true;
    }
private:
    Node* root_;
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */