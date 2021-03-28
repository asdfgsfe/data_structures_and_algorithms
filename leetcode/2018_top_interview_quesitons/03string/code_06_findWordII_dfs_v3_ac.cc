struct TireNode{
    TireNode* children[26];
    string word;

    TireNode() {
        for( int i=0; i<26; i++ )
            children[i] = nullptr;
    }

    void add( string s ){
        TireNode *tirePtr = this;
        for( char c : s ){
            if( tirePtr->children[c-'a'] == nullptr )
                tirePtr->children[c-'a'] = new TireNode();
            tirePtr = tirePtr->children[c-'a'];
        }
        tirePtr->word = s; //word互不相同
    }

    void find( vector<vector<char>>& board, vector<vector<bool>> &mark, pair<int,int> pos, 
    TireNode *tirePtr, vector<string> &ans ){
        int x=pos.first, y=pos.second;
        if( x<0 || x>=board.size() || y<0 || y>=board[0].size() || mark[x][y] || 
            tirePtr->children[board[x][y]-'a']==nullptr )
            return;
        
        tirePtr = tirePtr->children[board[x][y]-'a'];
        mark[x][y] = true;

        if( tirePtr->word.size() ){
            ans.push_back(tirePtr->word);
            tirePtr->word = ""; //避免插入重复字符
        }

        find(board, mark, pair<int,int>{x-1,y}, tirePtr, ans);
        find(board, mark, pair<int,int>{x+1,y}, tirePtr, ans);
        find(board, mark, pair<int,int>{x,y-1}, tirePtr, ans);
        find(board, mark, pair<int,int>{x,y+1}, tirePtr, ans);

        mark[x][y] = false;
    }
};

class Solution {
public:
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        vector<string> ans;
        TireNode *root = new TireNode();        
        
        for( string word : words )
            root->add(word);

        int x=board.size(), y=board[0].size();
        vector<vector<bool>> mark(x, vector<bool>(y, false));
        for( int i=0; i<x; i++ ){
            for( int j=0; j<y; j++ ){
                root->find(board, mark, pair<int,int>{i,j}, root, ans);
            }
        }

        return ans;
    }
};

//之前自己写的trie树的不能ac
