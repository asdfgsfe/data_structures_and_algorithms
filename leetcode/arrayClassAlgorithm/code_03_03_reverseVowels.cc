class Solution {
public:
	string reverseVowels(string s) {
		if (s.empty())
		{
			return s;
		}
		static const unordered_set<char> yuanYin{ 'a', 'u', 'o', 'i', 'e', 'A', 'U', 'O', 'I', 'E'};
		int l = 0;
		int r = s.size() - 1;
		while (1)
		{
			while (l < s.size() && !yuanYin.count(s[l]))
			{
				++l;
			}
			while (r >= 0 && !yuanYin.count(s[r]))
			{
				--r;
			}
			if (l >= r)
			{
				break;
			}
			std::swap(s[l++], s[r--]);
		}
		return s;
	}
};