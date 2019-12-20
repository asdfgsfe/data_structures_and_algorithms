class Solution {
public:
    int longestSubstring(string s, int k) {
        if (s.empty())
        {
			return 0;
        }
		if (k < 2)
		{
			return s.size();
		}
		return LonggestProcess(s, 0, s.size() - 1, k);
    }

	int LonggestProcess(const string& str, int l, int r, int k)
	{
		if (r - l + 1 < k)
		{
			return 0;
		}
		vector<int> times(26, 0);
		for (int i = l; i <= r; ++i)
		{
			++times[str[i] - 'a'];
		}
		while (r - l + 1 >= k && times[str[l] - 'a'] < k)
		{
			++l;
		}
		while (r - l + 1 >= k && times[str[r] - 'a'] < k)
		{
			--r;
		}
		if (r - l + 1 < k)
		{
			return 0;
		}
		for (int i = l; i <= r; ++i)
		{
			if (times[str[i] - 'a'] < k)
			{
				return std::max(LonggestProcess(str, l, i - 1, k), LonggestProcess(str, i + 1, r, k));
			}
		}
		return r - l + 1;
	}
};

//解题思路：递归拆分子串，分治。先统计出每个字符出现的频次，维护一对双指针，
//从首尾开始统计，从首尾往中间排除，如果出现次数小于k则不可能出现在最终子串中，
//排除并挪动指针，然后得到临时子串，依次从头遍历，一旦发现出现频次小于k的字符，
//以该字符为分割线，分别递归求其最大值返回。