class Solution {
public:
    int numJewelsInStones(string J, string S) {
        if (J.empty() || S.empty())
        {
            return 0;
        }
        vector<int> charNums(256, 0);
        for (char ch : S)
        {
            ++charNums[ch];
        }
        int cnt = 0;
        for (char ch : J)
        {
            cnt += charNums[ch];
        }
        return cnt;
    }
};