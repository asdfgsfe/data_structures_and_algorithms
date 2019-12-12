class Solution {
public:
    bool isAnagram(string s, string t) {
        if (s.empty())
        {
            return t.empty();
        }
        if (t.empty())
        {
            return s.empty();
        }
        int charCnt[26] = {0};
        for (char ch : t)
        {
            ++charCnt[ch - 'a'];
        }
        for (char ch : s)
        {
            --charCnt[ch - 'a'];
        }
        for (int i = 0; i < 26; ++i)
        {
            if (charCnt[i] != 0)
            {
                return false;
            }
        }
        return true;
    }
};