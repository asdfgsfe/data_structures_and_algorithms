int LengthOfLonggestSubstring(const string& str)
{
    if (str.empty())
    {
        return 0;
    }
    vector<int> preIdx(256, -1);
    int longgest = 0;
    int pre = -1;
    for (int i = 0; i < str.size(); ++i)
    {
        pre = std::max(pre, preIdx[str[i]]);
        longgest = std::max(longgest, i - pre);
        preIndex[str[i]] = i;
    }
    return longgest;
}


string LonggestSubstring(const string& str)
{
    if (str.empty())
    {
        return 0;
    }
    vector<int> preIdx(256, -1);
    int longgest = 0;
    int pre = -1;
    int begin = 0;
    int end = 0;
    for (char ch : str)
    {
        pre = std::max(pre, preIndx[ch]);
        int curLen = i - pre;
        if (curLen > longgest)
        {
            begin = pre;
            end = i;
        }
        preIdx[ch] = i;
    }
    return str.substr(begin, longgest);
}
