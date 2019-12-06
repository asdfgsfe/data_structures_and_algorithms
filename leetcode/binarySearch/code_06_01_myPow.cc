class Solution {
public:
    double myPow(double x, int n) {
        if (x == 0.0)
        {
            return 0.0;
        }
        long long exp = (long long)n;
        double ret = PowProcess(x, exp < 0 ? -exp : exp);
        return n < 0 ? 1 / ret : ret;
    }
    
    double PowProcess(double x, long long n)
    {
        if (n == 0)
        {
            return 1;
        }
        if (n == 1)
        {
            return x;
        }
        bool odd = (n & 0x01) == 0x01;
        double half = PowProcess(x, n / 2);
        half *= half;
        half = odd ? half * x : half;
        return half;
    }
};