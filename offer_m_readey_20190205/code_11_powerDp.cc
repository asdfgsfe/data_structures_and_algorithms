bool g_invaildInput = false;
double Power(double base, int exp)
{
    g_invaildInput = false;
    if (base == 0.0)
    {
        g_invaildInput = true;
        return;
    }
    bool minus = exp < 0 ? true : false;
    exp = exp < 0 ? -exp : exp;
    vector<double> dp(exp + 1, 1.0);
    dp[1] = base;
    for (int i = 2; i < dp.size(); ++i)
    {
        dp[i] = dp[i / 2] * dp[i / 2];
        if ((i & 0x01) == 1)
        {
            dp[i] = dp[i] * base;
        }
    }
    return minus ? 1 / dp[exp] : dp[exp];
}
