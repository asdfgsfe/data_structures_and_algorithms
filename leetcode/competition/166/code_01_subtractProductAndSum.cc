class Solution {
public:
    int subtractProductAndSum(int n) {
        if (n < 1)
        {
            return 0;
        }
        int m = 1;
        int sum = 0;
        while (n)
        {
            int rest = n % 10;
            n /=10;
            sum += rest;
            m *= rest;
        }
        return m - sum;
    }
};