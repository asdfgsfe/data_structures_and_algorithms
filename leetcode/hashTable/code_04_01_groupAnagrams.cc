class Solution {
public:
	vector<vector<string>> groupAnagrams(vector<string>& strs) {
		if (strs.empty())
		{
			return {};
		}
		unordered_map<string, vector<string>> records;
		for (const string& str : strs)
		{
			int build[26];
            memset(build, 0, sizeof build);
			for (char ch : str)
			{
				++build[ch - 'a'];
			}
			string pattern;
			for (int i = 0; i < 26; ++i)
			{
				pattern += "_" + std::to_string(build[i]);
				//��֪��Ϊɶ���ܹ� �������ڴ泬��������
				//pattern += (i + 'a ') + "_" + std::to_string(build[i]) + "_";
			}
			records[pattern].emplace_back(str);
		}
		vector<vector<string>> groups;
		for (auto& record : records)
		{
			groups.emplace_back(std::move(record.second));
		}
		return groups;
	}
};