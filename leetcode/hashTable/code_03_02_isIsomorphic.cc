class Solution {
public:
	bool isIsomorphic(string s, string t) {
		if (s.empty())
		{
			return t.empty();
		}
		if (t.empty())
		{
			return s.empty();
		}
		if (s.size() != t.size())
		{
			return false;
		}
		vector<int> sTot(256, -1);
		vector<int> tTos(256, -1);
		int i = 0;
		int j = 0;
		while (i < s.size() && j < t.size())
		{
			if (sTot[s[i]] == -1 && tTos[t[j]] == -1)
			{
				sTot[s[i]] = t[j];
				tTos[t[j++]] = s[i++];
				continue;
			}
			if (sTot[s[i]] == -1 || tTos[t[j]] == -1)
			{
				return false;
			}
			if (sTot[s[i]] != t[j] || tTos[t[j]] != s[i])
			{
				return false;
			}
			++i;
			++j;
		}
		return true;
	}
};