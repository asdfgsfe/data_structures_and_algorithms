//不能AC 但是这种方法值得研究下 连一个case也不能过
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


//了解下这种编码方式 连一个case也不能过
class Solution {
public:
    int openLock(vector<string>& deadends, string target) {
        if (target.empty()) {
            return -1;
        }
        string base("0000");
        unordered_set<string> visited(deadends.begin(), deadends.end());
        if (visited.count(base) || visited.count(target)) {
            return -1;
        }
        return OpenProcess(base, visited, target);
    }

    int OpenProcess(string& base, unordered_set<string>& visited, const string& target) {
        if (visited.count(base)) {
            return 0x7fffffff;
        }
        if (base == target) {
            return 0;
        }
        visited.emplace(base);
        int path = 0x7fffffff;
        for (int i = 0; i < base.size(); ++i) {
            char pre = base[i];
            for (int d = -1; d < 2; d += 2) {
                int n = pre - '0' + d;
                n = n < 0 ? 9 : n;
                base[i] = n % 10 + '0';
                int next = OpenProcess(base, visited, target);
                if (next != 0x7fffffff) {
                    path = std::min(path, next);
                }
            }
            base[i] = pre;
        }
        return path == 0x7fffffff ? -1 : 1 + path;
    }
};
