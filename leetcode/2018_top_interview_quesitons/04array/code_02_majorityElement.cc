给定一个大小为 n 的数组，找到其中的多数元素。多数元素是指在数组中出现次数 大于 ⌊ n/2 ⌋ 的元素。

你可以假设数组是非空的，并且给定的数组总是存在多数元素。

 

示例 1：

输入：[3,2,3]
输出：3
示例 2：

输入：[2,2,1,1,1,2,2]
输出：2
 

进阶：

尝试设计时间复杂度为 O(n)、空间复杂度为 O(1) 的算法解决此问题。


作者：力扣 (LeetCode)
链接：https://leetcode-cn.com/leetbook/read/top-interview-questions/xmz79t/
来源：力扣（LeetCode）
著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。


//原因：从加法的结合率来分析，具有交换律和结合率 
//排序之后加起来的个数和一定大于其他所有的

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        if (nums.empty()) {
            return 0x7fffffff;
        }
        int n = nums[0];
        int times = 1;
        for (int i = 1; i < nums.size(); ++i) {
            times = nums[i] == n ? times + 1 : times - 1;
            if (times <= 0) {
                n = nums[i];
                times = 1;
            }
        }
        return n;
    }
};
