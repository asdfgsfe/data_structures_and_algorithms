//o(n*n)
vector<vector<string>> GroupAnagram(const vector<string>& words)
{
	if (words.empty())
	{
		return vector<vector<string>>();
	}
	unordered_map<string, vector<string>> wordGroups;
	for (const string& word : words)
	{
		vector<int> builder(26, 0);
		for (char ch : word)
		{
			++builder[ch - 'a']; 
		}
		string key;
		for (int i = 0; i < builder.size(); ++i)
		{
			key += std::to_string(i + 'a') + "_" + std::to_string(builder[i]) + "_";
		}
		wordGroups[key].emplace_back(word);
	}
	vector<vector<string>> groups;
	for (auto wordGroup : wordGroups)
	{
		groups.emplace_back(std::move(wordGrop.second));
	}
	return groups;
}