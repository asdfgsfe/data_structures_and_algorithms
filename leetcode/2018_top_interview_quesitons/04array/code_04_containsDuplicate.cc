存在重复元素
给定一个整数数组，判断是否存在重复元素。

如果存在一值在数组中出现至少两次，函数返回 true 。如果数组中每个元素都不相同，则返回 false 。

 

示例 1:

输入: [1,2,3,1]
输出: true
示例 2:

输入: [1,2,3,4]
输出: false
示例 3:

输入: [1,1,1,3,3,4,3,2,4,2]
输出: true
相关标签
数组
哈希表

作者：力扣 (LeetCode)
链接：https://leetcode-cn.com/leetbook/read/top-interview-questions/xm1rfd/
来源：力扣（LeetCode）
著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。

//就是一道简单的去重复题目， 去重复用set 或者hash

class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        if (nums.size() < 1) {
            return false;
        }
        //用到了hash set 涉及到了动态分配内存 效率不高
        unordered_set<int> processed;
        for (int n : nums) {
            if (processed.count(n)) {
                return true;
            }
            processed.emplace(n);
        }
        return false;
    }
};

class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        if (nums.size() < 1) {
            return false;
        }
        int maxN = nums[0];
        int minN = nums[0];
        for (int i = 1; i < nums.size(); ++i) {
            maxN = std::max(maxN, nums[i]);
            minN = std::min(minN, nums[i]);
        }

        vector<int> processed(maxN - minN + 1, 0);
        for (int n : nums) {
            if (processed[n - minN] != 0) {
                return true;
            }
            processed[n - minN] = 1;
        }
        return false;
    }
};
