class Solution {
public:
	int firstUniqChar(string s) {
		if (s.empty())
		{
			return -1;
		}
		vector<int> charToIds(256, -1);
		for (int i = 0; i < s.size(); ++i)
		{
			charToIds[s[i]] = charToIds[s[i]] == -1 ? i : -2;
		}
		int first = 0x7fffffff;
		for (int id : charToIds)
		{
			if (id != -1 && id != -2)
			{
				first = std::min(first, id);
			}
		}
		return first == 0x7fffffff ? -1 : first;
	}
};