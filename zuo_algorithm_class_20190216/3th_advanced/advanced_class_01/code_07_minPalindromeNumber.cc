//最暴利的方法 每个位置去尝试
//
string MinNum(string& n)
{
    if (n.empty())
    {
        return string();
    }
    long long base = atoi(n);
    long long minN = 0;
    CvrProcess(n, n.size() - 1, base, minN);
    return minN;
}

void CvrProcess(string& n, int i, long long base, long long& minN)
{
    if (i == 0 && IsPalindrome(n) && std::abs(base - atoi(n)) > std::abs(base - minN))
    {
        minN = atoi(n);
        return;
    }
    for (int i = 0; i < 10; ++i)
    {
        char ch = n[i];
        n[i] = i + '0';
        CvrProcess(n, i - 1, base, minN);
        n[i] = ch;
    }
}
