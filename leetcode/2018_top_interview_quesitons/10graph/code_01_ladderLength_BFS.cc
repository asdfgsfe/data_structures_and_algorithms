 class Solution {
 public:
	 int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
		 if (beginWord.empty() || endWord.empty() || wordList.empty())
		 {
			 return 0;
		 }
		 unordered_set<string> wordDict(wordList.begin(), wordList.end());
		 unordered_set<string> visited;
		 queue<pair<string, int>> paths;
		 paths.emplace(beginWord, 0);
		 while (!paths.empty())
		 {
			 pair<string, int> begin = std::move(paths.front());
			 paths.pop();
			 visited.emplace(begin.first);
			 if (begin.first == endWord)
			 {
				 return begin.second + 1;
			 }
			 for (int i = 0; i < begin.first.size(); ++i)
			 {
				 for (char c = 'a'; c <= 'z'; ++c)
				 {
					 std::swap(begin.first[i], c);
					 if (wordDict.count(begin.first) && !visited.count(begin.first))
					 {
						 paths.emplace(begin.first, begin.second + 1);
						 visited.emplace(begin.first);
					 }
					 std::swap(begin.first[i], c);
				 }
			 }
		 }
		 return 0;
	 }
 };

 //有个优化解法 使用双向bfs可以减少内存和时间复杂度