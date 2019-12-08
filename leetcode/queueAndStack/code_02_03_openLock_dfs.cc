//不能AC 但是这种方法值得研究下
class Solution {
public:
	int openLock(vector<string>& deadends, string target) {
		return OpenProcess(string("0000"), 0, deadends, target);
	}

	int OpenProcess(string& base, int i, vector<string>& deads, string target)
	{
		if (base == target)
		{
			return 0;
		}
		if (i == base.size())
		{
			return -1;
		}
		int cnt = 0;
		int minCnt = 0x7fffffff;
		int cur = base[i];
		for (int s = 0; s < 10; ++s)
		{
			bool find = false;
			for (const string& dead : deads)
			{
				if (dead == base)
				{
					find = true;
					break;
				}
			}
			if (find)
			{
				continue;
			}
			int next = OpenProcess(base, i + 1, deads, target);
			if (next == -1)
			{
				continue;
			}
			minCnt = std::min(minCnt, next + cnt);
			base[i] = (base[i] - '0' + 1) % 10 + '0';
			++cnt;
		}
		base[i] = cur;
		//std::cout << minCnt << std::endl;
		return minCnt == 0x7ffffff ? -1 : minCnt;
	}
};