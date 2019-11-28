class Solution {
public:
    int strStr(string haystack, string needle) {
        if (needle.empty())
        {
			return 0;
        }
		if (haystack.empty())
		{
			return -1;
		}
		vector<int> nexts = GenNexts(needle);
		int i = 0;
		int j = 0;
		while (i < haystack.size() && j < needle.size())
		{
			if (haystack[i] == needle[j])
			{
				++i;
				++j;
			}
			else if (nexts[j] != -1)
			{
				j = nexts[j];
			}
			else
			{
				++i;
			}
		}
		return j == needle.size() ? i - j : -1;
    }

	vector<int> GenNexts(const string& str)
	{
		if (str.size() < 2)
		{
			return str.empty() ? vector<int>() : vector<int>(1, -1);
		}
		vector<int> nexts(str.size());
		nexts[0] = -1;
		nexts[1] = 0;
		int i = 2;
		int cn = 0;
		while (i < str.size())
		{
			if (str[i - 1] == str[cn])
			{
				nexts[i++] = ++cn;
			}
			else if (cn > 0)
			{
				cn = nexts[cn];
			}
			else
			{
				nexts[i++] = 0;
			}
		}
		return nexts;
	}
};