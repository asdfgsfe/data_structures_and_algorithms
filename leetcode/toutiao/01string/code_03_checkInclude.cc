class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        if (s1 == s2)
        {
            return true;
        }
        if (s1.empty() || s2.empty() || s1.size() > s2.size())
        {
            return false;
        }
        vector<int> charNums1(26, 0);
        vector<int> charNums2(26, 0);
        for (char ch : s1)
        {
            ++charNums1[ch - 'a'];
        }
        for (int i = 0; i < s2.size(); ++i)
        {
            if (i >= s1.size())
            {
                --charNums2[s2[i - s1.size()] - 'a'];//窗口每次移动一个 所以--操作等于出窗口
            }
            ++charNums2[s2[i] - 'a'];
            if (i >= s1.size() - 1 && charNums1 == charNums2)
            {
                return true;
            }
        }
        return false;
    }
};
//滑动窗口模型 窗口大小为s1的长度 在s2中固定窗口找与s1一样的
