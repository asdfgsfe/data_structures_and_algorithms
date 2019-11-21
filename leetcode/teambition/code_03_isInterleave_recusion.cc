class Solution {
public:
	bool isInterleave(string s1, string s2, string s3) {
		if (s1.empty())
		{
			return s2 == s3;
		}
		if (s2.empty())
		{
			return s1 == s3;
		}
		if (s1.size() + s2.size() != s3.size())
		{
			return false;
		}
		return InterleaveProcess(s1, s2, s3, 0, 0);
	}

	bool InterleaveProcess(const string& s1, const string& s2, const string& s3, int i, int j)
	{
		if (i == s1.size() && j == s2.size())
		{
			return true;
		}
		if ((j == s2.size() || s2[j] != s3[i + j]) && s1[i] == s3[i + j])
		{
			return InterleaveProcess(s1, s2, s3, i + 1, j);
		}
		if ((i == s1.size() || s1[i] != s3[i + j]) && s2[j] == s3[i + j])
		{
			return InterleaveProcess(s1, s2, s3, i, j + 1);
		}
		if (s1[i] == s3[i + j] && s2[j] == s3[i + j])
		{
			return InterleaveProcess(s1, s2, s3, i + 1, j) || InterleaveProcess(s1, s2, s3, i, j + 1);
		}
		return false;
	}
};