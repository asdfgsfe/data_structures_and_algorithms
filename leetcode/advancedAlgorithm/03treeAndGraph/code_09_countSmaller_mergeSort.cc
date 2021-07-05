计算右侧小于当前元素的个数
给定一个整数数组 nums，按要求返回一个新数组 counts。数组 counts 有该性质： counts[i] 的值是  nums[i] 右侧小于 nums[i] 的元素的数量。

 

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
-10^4 <= nums[i] <= 10^4
相关标签
树状数组
线段树
数组
二分查找
分治
有序集合
归并排序


作者：力扣 (LeetCode)
链接：https://leetcode-cn.com/leetbook/read/top-interview-questions-hard/xdoube/
来源：力扣（LeetCode）
著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。

class Solution {
public:
    vector<int> countSmaller(vector<int>& nums) {
        if (nums.empty()) {
            return {};
        }
        vector<int> counts(nums.size(), 0);
        vector<int> index(nums.size());
        for (int i = 0; i < index.size(); ++i) {
            index[i] = i;
        }
        MergeSort(index, 0, nums.size() - 1, nums, counts);
        return counts;
    }

    void MergeSort(vector<int>& index, int l, int r, const vector<int>& nums, vector<int>& counts) {
        if (l >= r) {
            return;
        }
        int m = (l + r) / 2;
        MergeSort(index, l, m, nums, counts);
        MergeSort(index, m + 1, r, nums, counts);
        Merge(index, l, m, r, nums, counts);
    }

	//从大到小排序
    void Merge(vector<int>& index, int l, int m, int r, const vector<int>& nums, vector<int>& counts) {
        vector<int> help(r - l + 1);
        int p = 0;
        int rS = m + 1;
        int lS = l;
        while (rS <= r && lS <= m) {
            if (nums[index[lS]] <= nums[index[rS]]) {
                help[p++] = index[rS++];
            } else {
                counts[index[lS]] += r - rS + 1;
                help[p++] = index[lS++];
            }
        }
        while (rS <= r) {
            help[p++] = index[rS++];
        }
        while (lS <= m) {
            help[p++] = index[lS++];
        }
        for (int i = 0; i < help.size(); ++i) {
            index[l + i] = help[i];
        }
    }
};
