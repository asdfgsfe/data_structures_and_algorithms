 class Solution {
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
		 void Insert(string word) {
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
		 bool Search(string word) {
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
		 bool Prefix(string prefix) {
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
		 Node * root_;
	 };
 public:
	 vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
		 if (board.empty() || words.empty())
		 {
			 return {};
		 }
		 Trie trie;
		 for (const string& word : words)
		 {
			 trie.Insert(word);
		 }

		 unordered_set<string> processed;
		 vector<string> existed;
		 for (int i = 0; i < board.size(); ++i)
		 {
			 for (int j = 0; j < board[0].size(); ++j)
			 {
				 vector<vector<bool>> visited(board.size(), vector<bool>(board[0].size(), false));
				 string word;
				 ExistProcess(word, board, i, j, visited, existed, processed, trie);
			 }
		 }
		 return existed;
	 }

	 void ExistProcess(string& word,
					   const vector<vector<char>>& board, int r, int c,
					   vector<vector<bool>>& visited,
					   vector<string>& existed,
					   unordered_set<string>& processed,
					   Trie& trie)
	 {
		 if (!word.empty() && !processed.count(word) && trie.Search(word))
		 {
			 existed.emplace_back(word);
			 processed.emplace(word);
			 return;
		 }
		 if (!word.empty() && !trie.Prefix(word))
		 {
			 return;
		 }
		 if (r < 0 || r >= board.size() || c < 0 || c >= board[0].size() || visited[r][c])
		 {
			 return;
		 }
		 visited[r][c] = true;
		 word.push_back(board[r][c]);
		 ExistProcess(word, board, r + 1, c, visited, existed, processed, trie);
		 ExistProcess(word, board, r, c + 1, visited, existed, processed, trie);
		 ExistProcess(word, board, r - 1, c, visited, existed, processed, trie);
		 ExistProcess(word, board, r, c - 1, visited, existed, processed, trie);
		 visited[r][c] = false;
		 word.pop_back();
	 }
 };