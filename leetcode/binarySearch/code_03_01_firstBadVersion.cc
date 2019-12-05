// Forward declaration of isBadVersion API.
bool isBadVersion(int version);

class Solution {
public:
	int firstBadVersion(int n) {
		int first = 0;
		BabVersionProcess(1, n, first);
		return first;
	}

	void BabVersionProcess(int l, int r, int& first)
	{
		if (l > r)
		{
			return;
		}
		int m = l + (r - l) / 2;
		bool is = isBadVersion(m);
		if (is)
		{
			first = m;
			BabVersionProcess(l, m - 1, first);
		}
		else
		{
			BabVersionProcess(m + 1, r, first);
		}
	}
};