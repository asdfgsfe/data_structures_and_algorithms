class Solution {
public:
	int openLock(vector<string>& deadends, string target) {
		if (target.empty())
		{
			return -1;
		}
		string base("0000");
		unordered_set<string> visited(deadends.begin(), deadends.end());
        if (visited.count(base) || visited.count(target))
        {
            return -1;
        }
		visited.emplace(base);
		queue<string> steps;
		steps.push(base);
		int path = 0;
		while (!steps.empty())
		{
			int size = steps.size();
			while (size--)
			{
				string cur = steps.front();
				steps.pop();
				if (cur == target)
				{
					return path;
				}
				for (int i = 0; i < 4; ++i)
				{
					char pre = cur[i];
					for (int d = -1; d < 2; d += 2)
					{
						int n = pre - '0' + d;
						n = n < 0 ? 9 : n;
						cur[i] = n % 10 + '0';
						if (!visited.count(cur))
						{
							steps.emplace(cur);
							visited.emplace(cur);
						}
					}
					cur[i] = pre;
				}
			}
			++path;
		}
		return -1;
	}
};