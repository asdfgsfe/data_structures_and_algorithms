class Solution {
public:
    bool isHappy(int n) {
        if (n < 1)
        {
            return false;
        }
        unordered_set<int> visited;
        while (1)
        {
            if (visited.count(n))
            {
                return false;
            }
            visited.emplace(n);
            int num = 0;
            while (n)
            {
                num += (n % 10) * (n % 10);
                n /= 10;
            }
            if (num == 1)
            {
                return true;
            }
            n = num;
        }
    }
};