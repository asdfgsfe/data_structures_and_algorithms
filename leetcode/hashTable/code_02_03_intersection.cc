两个数组的交集
给定两个数组，编写一个函数来计算它们的交集。

 

示例 1：

输入：nums1 = [1,2,2,1], nums2 = [2,2]
输出：[2]
示例 2：

输入：nums1 = [4,9,5], nums2 = [9,4,9,8,4]
输出：[9,4]
 

说明：

输出结果中的每个元素一定是唯一的。
我们可以不考虑输出结果的顺序。
相关标签
数组
哈希表
双指针
二分查找
排序

作者：力扣 (LeetCode)
链接：https://leetcode-cn.com/leetbook/read/hash-table/xh4sec/
来源：力扣（LeetCode）
著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。两个数组的交集
给定两个数组，编写一个函数来计算它们的交集。

 

示例 1：

输入：nums1 = [1,2,2,1], nums2 = [2,2]
输出：[2]
示例 2：

输入：nums1 = [4,9,5], nums2 = [9,4,9,8,4]
输出：[9,4]
 

说明：

输出结果中的每个元素一定是唯一的。
我们可以不考虑输出结果的顺序。
相关标签
数组
哈希表
双指针
二分查找
排序

作者：力扣 (LeetCode)
链接：https://leetcode-cn.com/leetbook/read/hash-table/xh4sec/
来源：力扣（LeetCode）
著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。

class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        if (nums1.empty() || nums2.empty())
        {
            return {};
        }
        unordered_set<int> visited;
        for (int num : nums1)
        {
            visited.emplace(num);
        }
        unordered_set<int> processed;
        vector<int> nums;
        for (int num : nums2)
        {
            if (processed.count(num))
            {
                continue;
            }
            processed.emplace(num);
            if (visited.count(num))
            {
                nums.emplace_back(num);
            }
        }
        return nums;
    }
};

//采用hash表 代码更加简单一点
class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        if (nums1.empty() || nums2.empty()) {
            return {};
        }
        unordered_map<int, int> numTimes;
        for (int n : nums1) {
            ++numTimes[n];
        }
        vector<int> ret;
        for (int n : nums2) {
            auto it = numTimes.find(n);
            if (it != numTimes.end() && it->second > 0) {
                ret.push_back(n);
                it->second = 0;
            }
        }
        return ret;
    }
};
