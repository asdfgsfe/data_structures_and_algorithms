class Solution {
public:
    bool isPerfectSquare(int num) {
        if (num < 2)
        {
            return true;
        }
        int l = 1;
        int r = num / 2;
        while (l <= r)
        {
            long long mid = l + (r - l) / 2;
            long long m = mid * mid;
            if (m == (long long)num)
            {
                return true;
            }
            else if (m > (long long)num)
            {
                r = mid - 1;
            }
            else
            {
                l = mid + 1;
            }
        }
        return false;
    }
};