class Solution {
public:
	int numSquares(int n) {
		if (n < 3)
		{
			return n;
		}
		int cnt = 0;
		queue<int> nums;
		nums.emplace(n);
		unordered_set<int> visited;
		visited.emplace(n);
		while (!nums.empty())
		{
			int size = nums.size();
			while (size--)
			{
				int num = nums.front();
				nums.pop();
				if (num == 0)
				{
					return cnt;
				}
				for (int i = num / 2; i >= 1; --i)
				{
					int next = num - i * i;
					if (next >= 0 && !visited.count(next))
					{
						nums.emplace(next);
						visited.emplace(next);
					}
				}
			}
			++cnt;
		}
		return -1;
	}
};