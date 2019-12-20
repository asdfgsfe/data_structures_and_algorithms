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

//����˼·���ݹ����Ӵ������Ρ���ͳ�Ƴ�ÿ���ַ����ֵ�Ƶ�Σ�ά��һ��˫ָ�룬
//����β��ʼͳ�ƣ�����β���м��ų���������ִ���С��k�򲻿��ܳ����������Ӵ��У�
//�ų���Ų��ָ�룬Ȼ��õ���ʱ�Ӵ������δ�ͷ������һ�����ֳ���Ƶ��С��k���ַ���
//�Ը��ַ�Ϊ�ָ��ߣ��ֱ�ݹ��������ֵ���ء�