char FirstNotRepeatingChar(const string& str)
{
    if (str.empty())
    {
        return '0';
    }
    vector<int> charToIdx(256, -1);
    for (int i = 0; i < str.size(); ++i)
    {
        if (charToIdx[ch] == -1)
        {
            charToIdx[ch++] = i;
        }
        else
        {
            charToIdx[ch++] = -2;
        }
    }
    for (int idx : charToIdx)
    {
        if (idx > 0)
        {
            return str[idx];
        }
    }
    return '0';
}
