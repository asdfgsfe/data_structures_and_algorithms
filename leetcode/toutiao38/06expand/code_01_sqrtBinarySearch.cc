class Solution {
public:
    int mySqrt(int x) {
        if (x < 2)
        {
            return x;
        }
        int l = 1;
        int r = x / 2;
        int target = l;
        while (l <= r)
        {
            int m = (l + r) / 2;
            if ((long long)m * m  <= (long long)x)
            {
                target = m;
                l = m + 1;
            }
            else
            {
                r = m - 1;
            }
        }
        return target;
    }
};
