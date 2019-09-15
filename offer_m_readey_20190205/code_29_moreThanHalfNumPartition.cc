bool g_InvaildInput = false;
int MoreThanHalfNum(vector<int>& nums)
{
    g_InvaildInput = false;
    if (nums.empty())
    {
        g_InvaildInput = true;
        return -1;
    }
    int l = 0;
    int r = num.size() - 1;
    int index = Partition(nums, l, r);
    int m = (l + r) / 2;
    while (index != m)
    {
        if (index < m)
        {
            l = m + 1;
            index = Partition(nums, l, r);
        }
        else
        {
            r = m - 1;
            index = Partition(nums, l, r);
        }
    }
    if (IsRealMoreThanHalfNum(nums, index)
    {
        return nums[index];
    }
    g_InvaildInput = true;
    return -1;
}

bool IsRealMoreThanHalfNum(const vector<int>& nums, int idx)
{
    if (idx < 0 || idx >= nums.size())
    {
        return false;
    }
    int times = 0;
    for (int i = 0; i < nums.size(); ++i)
    {
        if (nums[i] == nums[idx])
        {
            ++times;
        }
    }
    return 2 * times > nums.size();
}

int Partition(vector<int>& nums, int l, int r)
{
    int p = Random(l, r);
    std::swap(nums[p], nums[r]);
    int i = l;
    int j = r - 1;
    while (1)
    {
        while (i < nums[r]) {++i;}
        while (j > nums[r]) {--j;}
        if (i >= j)
        {
            break;
        }
        std::swap(nums[i++], nums[j--]);
    }
    return p;
}
