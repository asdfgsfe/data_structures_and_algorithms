315. 计算右侧小于当前元素的个数
给定一个整数数组 nums，按要求返回一个新数组 counts。数组 counts 有该性质： counts[i] 的值是  nums[i] 右侧小于 nums[i] 的元素的数量。

 

示例：

输入：nums = [5,2,6,1]
输出：[2,1,1,0] 
解释：
5 的右侧有 2 个更小的元素 (2 和 1)
2 的右侧仅有 1 个更小的元素 (1)
6 的右侧有 1 个更小的元素 (1)
1 的右侧有 0 个更小的元素
 

提示：

0 <= nums.length <= 10^5
-10^4 <= nums[i] <= 10^4
通过次数44,385提交次数105,832

class Solution {
public:
    vector<int> countSmaller(vector<int>& nums) {
        if (nums.size() < 1) {
            return {0};
        }
        vector<int> index(nums.size());
        for (int i = 0; i < nums.size(); ++i) {
            index[i] = i;
        }
        vector<int> count(nums.size(), 0);
        MergeSort(index, 0, index.size() - 1, count, nums);
        return count;
    }

    void MergeSort(vector<int>& index, int l, int r, vector<int>& count, const vector<int>& nums) {
        if (l >= r) {
            return;
        }
        int m = l + (r - l) / 2;
        MergeSort(index, l, m, count, nums);
        MergeSort(index, m + 1, r, count, nums);
        Merge(index, l, m, r, count, nums);
    }

    void Merge(vector<int>& index, int l, int m, int r, vector<int>& count, const vector<int>& nums) {
        vector<int> help(r - l + 1);
        int p = 0;
        int lS = l;
        int rS = m + 1;
        while (lS <= m && rS <= r) {
            if (nums[index[lS]] <= nums[index[rS]]) {
                help[p++] = index[rS++]; //从大到小排序 对nums的index排序， 但是比较规则是nums中数字的大小
            } else {
                count[index[lS]] += r - rS + 1;
                help[p++] = index[lS++];
            }
        }
        while (lS <= m) {
            help[p++] = index[lS++];
        }
        while (rS <= r) {
            help[p++] = index[rS++];
        }
        for (int i = 0; i < help.size(); ++i) {
            index[l + i] = help[i];
        }
    }
};
