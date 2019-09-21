//打印所有不重复的全排列
void UniquePermutation(string& s)
{
    if (s.empty())
    {
        return;
    }
    PermutationProcess(s, 0);
}
void PermutationProcess(string& s, int index)
{
    if (index == s.size())
    {
        std::cout << s << std::endl;
        return;
    }
    unordered_set<char> processed;
    for (int i = index; i < s.size(); ++i)
    {
        if (processed.count(s[i]))
        {
            continue;
        }
        std::swap(s[i], s[index]);
        PermutationProcess(s, index + 1);
        std::swap(s[i], s[index]);
    }
}
