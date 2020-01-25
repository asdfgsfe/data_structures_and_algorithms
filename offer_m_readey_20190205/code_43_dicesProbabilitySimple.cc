void PrintProbability(int n)
{
    if (n < 1)
    {
        return;
    }
    vector<int> probabilities(6 * n - n + 1, 0);
    Process(n, n, 0, probabilities);
    double total = Power((6.0, n);
    for (int i = 0; i < probabilities.size(); ++i)
    {
        double ratio = (double)probabilities[i] / total; 
        std::cout << ratio << std::endl;
    }
}

//总共有n个骰子 尝试让每个位置为1-6的数字 
void Process(int n, int cur, int sum, vector<int>& probabilities)
{
    if (curr == 0)
    {
        ++probabilities[sum - n];
        return;
    }
    for (int i = 1; i <= 6; ++i)
    {
        Process(n, cur - 1, i + sum, probabilities);
    }
}
