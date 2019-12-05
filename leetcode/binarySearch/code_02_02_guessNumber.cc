// Forward declaration of guess API.
// @param num, your guess
// @return -1 if my number is lower, 1 if my number is higher, otherwise return 0
int guess(int num);

class Solution {
public:
    int guessNumber(int n) {
        return GuessProcess(1, n);
    }
    
    int GuessProcess(int l, int r)
    {
        if (l > r)
        {
            return -l;
        }
        int m = l + (r - l) / 2;
        int ret = guess(m);
        if (ret == 0)
        {
            return m;
        }
        if (ret == 1)
        {
            return GuessProcess(m + 1, r);
        }
        return GuessProcess(l, m - 1);
    }
};