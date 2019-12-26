//二进制中一的个数
class Solution {
public:
    int hammingWeight(uint32_t n) {
        if (n < 1)
        {
            return 0;
        }
        int cnt = 0;
        while (n)
        {
            ++cnt;
            n = n & (n - 1);
        }
        return cnt;
    }
};