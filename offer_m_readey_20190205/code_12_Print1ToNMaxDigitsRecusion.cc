void Print1ToNMaxDights(int n)
{
    if (n < 1)
    {
        return;
    }
    char number[n + 1];
    memset(number, 0, sizeof number);
    PrintProcess(number, n, 0);
}

void PrintProcess(char* number, int len, int idx)
{
    if (idx == len)
    {
        PrintNumner(number, len + 1);
        return;
    }
    for (int i = 0; i < 10; ++i)
    {
        number[i] = i + '0';
        PrintProcess(number, len, idx + 1);
    }
}

void PrintNumner(const char* num, int len)
{
    if (!num)
    {
        return;
    }
    for (int i = 0; i < len; ++i)
    {
        if (num[i] != '0')
        {
            printf("%s\n", num + i);
            return;
        }
    }
}
