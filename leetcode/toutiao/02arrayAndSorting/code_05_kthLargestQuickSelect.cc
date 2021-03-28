int KthMaxNumber(vector<int>& nums, int k)
{
    if (nums.empty())
    {
        return 0;
    }
    k = k % nums.size();
    int p = -1;
    while (k != p)
    {
        p = ::rand() % size();
        Partition(nums, nums[p]);
    }
    return nums[k];
}

vector<int> Partition(vector<int>& nums, int pivot)
{
    assert(p >= 0 && p < nums.size());
    int l = 0;
    int r = nums.size() - 1;
    int less = -1;
    int more = nums.size();
    while (l < more)
    {
        if (nums[l] < pivot)
        {
            std::swap(nums[++less], nums[l++]);
        }
        else if (nums[l] > pivot)
        {
            std::swap(nums[l], nums[--more]);
        }
        else
        {
            ++l;
        }
    }
    return {less + 1, more - 1};
}
