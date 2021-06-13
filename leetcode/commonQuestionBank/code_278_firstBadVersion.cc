//278. 第一个错误的版本

// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

class Solution {
public:
    int firstBadVersion(int n) {
        int l = 1;
        int r = n;
        int bad = 0;
        while (l <= r) {
            int m = l + (r - l) / 2;
            if (isBadVersion(m)) {
                bad = m;
                r = m - 1;
            } else {
                l = m + 1;
            }
        }
        return bad;
    }
};
