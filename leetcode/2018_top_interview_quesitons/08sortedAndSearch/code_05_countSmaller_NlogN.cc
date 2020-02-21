class Solution {
public:
    //��Ŀ�ı���ܼ� �������ֵĴ�С�� index�������� �����벿�ִ����Ұ벿�� ��id�����Ұ벿��jǰ�������
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
    //����Ҫ��index���� ����l r ��ָindex���±�
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
			//ȷ���Ӵ�С����
            if (nums[indexs[lS]] <= nums[indexs[rS]])
            {
                help[p++] = indexs[rS++];
            }
            else
            {
				//���ڴӴ�С���� nums[indexs[lS]] > nums[indexs[rS]] ��ôi ����j �������е�
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
