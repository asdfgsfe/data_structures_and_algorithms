vector<vector<string>> FindWordLadder(const string& beginWord, 
									  const string& endWord, 
									  const list<string>& wordList)
{
	unordered_map<string, vector<string>> nexts = Nexts(wordList);
	unordered_map<string, int> distances = Distances(beginWord, nexts);
	vector<string> paths;
	vector<vector<string>> res;
	ShortPaths(beginWord, endWord, nexts, distances, paths, res);
}

unordered_map<string, vector<string>> Nexts(const vector<string>& words)
{
	unordered_map<string, vector<string>> nexts;
	set<string> dic(words.begin(), words.end());
	for (string& word : words)
	{
		nexts[word] = Next(word, dic);
	}
}

vector<string> Next(string& word, set<string>& dic)
{
	vector<string> next;
	for (char cur = 'a'; cur <= 'z'; ++cur)
	{
		for (int i = 0; i < word.size(); ++i)
		{
			if (word[i] != cur)
			{
				std::swap(word[i], cur);
				if (dis.find(word) != dic.end())
				{
					next.push_back(word);
				}
				std::swap(word[i], cur);
			}
		}
	}
	return next;
}

unordered_map<string, int> Distances(const string& begin, const unordered_map<string, vector<string>>& nexts)
{
	unordered_map<string, int> distances;
	distances[begin] = 0;
	queue<string> words;
	words.push(begin);
	set<string> uniqueWords;
	uniqueWords.push(begin);
	while (!words.empty())
	{
		string cur = words.front();
		for (const string& next : nexts[cur])
		{
			if (uniqueWords.find(next) == uniqueWords.end())
			{
				distances[next] = distances[cur] + 1;
				words.push_back(next);
				uniqueWords.push_back(next);
			}
		}
	}
	return distances;
}

void ShortPaths(const string& cur, 
				const string& end, 
				const unordered_map<string, vector<string>>& nexts
				const unordered_map<string, int>& distances
				vector<string>& solution,
				vector<vector<string>>& res)
{
	solution.push_back(cur);
	if (cur == end)
	{
		res.push_back(solution);
	}
	else
	{	assert(nexts.find(cur) != nexts.end());
		for (const string& next : nexts[cur])
		{
			if (distances[next] == distances[cur] + 1)
			{
				ShortPaths(next, end, nexts, distances, solution, res);
			}
		}
	}
	solution.pop_back();
}