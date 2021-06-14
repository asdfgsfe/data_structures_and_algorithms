//第一个错误的版本

// Forward declaration of isBadVersion API.
bool isBadVersion(int version);

//递归版
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

//二分查找
// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

class Solution {
public:
    int firstBadVersion(int n) {
        if (n < 1) {
            return n;
        }
        int l = 1;
        int r = n;
        int t = -1;
        while (l <= r) {
            int m = l + (r - l) / 2;
            if (isBadVersion(m)) {
                t = m;
                r = m - 1;
            } else {
                l = m + 1;
            }
        }
        return t;
    }
};
