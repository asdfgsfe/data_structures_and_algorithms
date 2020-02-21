class Solution {
public:
    //题目的本意很简单 依据数字的大小对 index进行排序 如果左半部分大于右半部分 则id大于右半部分j前面的所有
    vector<int> countSmaller(vector<int>& nums) {
        if (nums.empty())
        {
            return {};
        }
        vector<int> indexs(nums.size());
        for (int i = 0; i < nums.size(); ++i)
        {
            indexs[i] = i;
        }
        vector<int> count(nums.size(), 0);
        MergeSort(indexs, 0, indexs.size() - 1, count, nums);
        return count;
    }
    //由于要对index排序 所以l r 均指index的下标
    void MergeSort(vector<int>& indexs, int l, int r, vector<int>& count, const vector<int>& nums)
    {
        if (l >= r)
        {
            return;
        }
        int m = l + (r - l) / 2;
        MergeSort(indexs, l, m, count, nums);
        MergeSort(indexs, m + 1, r, count, nums);
        Merge(indexs, l, m, r, count, nums);
    }
    
    void Merge(vector<int>& indexs, int l, int m, int r, vector<int>& count, const vector<int>& nums)
    {
        vector<int> help(r - l + 1);
        int p = 0;
        int lS = l;
        int rS = m + 1;
        while (lS <= m && rS <= r)
        {
			//确保从大到小排序
            if (nums[indexs[lS]] <= nums[indexs[rS]])
            {
                help[p++] = indexs[rS++];
            }
            else
            {
				//由于从大到小排序 nums[indexs[lS]] > nums[indexs[rS]] 那么i 大于j 后面所有的
                count[indexs[lS]] += r - rS + 1;
                help[p++] = indexs[lS++];
            }
        }
        while (lS <= m)
        {
            help[p++] = indexs[lS++];
        }
        while (rS <= r)
        {
            help[p++] = indexs[rS++];
        }
        for (int i = 0; i < help.size(); ++i)
        {
            indexs[l + i] = help[i];
        }
    }
};
