class Solution {
public:
	string addBinary(string a, string b) {
		if (a.empty())
		{
			return b;
		}
		if (b.empty())
		{
			return a;
		}
        const string& l = a.size() > b.size() ? a : b;
        const string& s = a.size() > b.size() ? b : a;
		string sum("0");
		sum += l;
		int i = sum.size() - 1;
		int j = s.size() - 1;
		while (i >= 0 && j >= 0)
		{
			int val = (sum[i] - '0') + (s[j] - '0');
			int p = i;
			sum[p--] = val % 2 + '0';
			while (val >= 2)
			{
				val = sum[p] - '0' + val / 2;
				sum[p--] = val % 2 + '0';
			}
			--i;
			--j;
		}
		return sum[0] == '0' ? sum.substr(1, sum.size() - 1) : sum;
	}
};