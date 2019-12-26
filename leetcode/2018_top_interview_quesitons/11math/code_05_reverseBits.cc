class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        if (n < 1)
        {
            return n;
        }
        return ReverseProcess(n, 31);
    }
    
    uint32_t ReverseProcess(uint32_t n, int i)
    {
        if (n == 0)
        {
            return 0;
        }
        return pow(2, i) * (n % 2) + ReverseProcess(n / 2, i - 1);
    }
};

//最佳解法 移位操作
class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        uint32_t res = 0;
        int i = 32;
        while(i--)
        {
            res <<= 1;
            res = res + (n & 1);
            n >>= 1;
        }

        return res;
    }
};