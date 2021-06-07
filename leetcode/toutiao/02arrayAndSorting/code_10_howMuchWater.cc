//接雨水问题和最多可以存入多少水比较下题目
//42. 接雨水
给定 n 个非负整数表示每个宽度为 1 的柱子的高度图，计算按此排列的柱子，下雨之后能接多少雨水。

 

示例 1：



输入：height = [0,1,0,2,1,0,1,3,2,1,2,1]
输出：6
解释：上面是由数组 [0,1,0,2,1,0,1,3,2,1,2,1] 表示的高度图，在这种情况下，可以接 6 个单位的雨水（蓝色部分表示雨水）。 
示例 2：

输入：height = [4,2,0,3,2,5]
输出：9
 

提示：

n == height.length
0 <= n <= 3 * 104
0 <= height[i] <= 105




class Solution {
public:
    int trap(vector<int>& container) {
        if (container.size() < 3)
        {
            return 0;
        }
        int leftMax = container[0];
        int rightMax = container[container.size() - 1];
        int l = 1;
        int r = container.size() - 2;
        int cnt = 0;
        while (l <= r)
        {
            if (leftMax < rightMax)
            {
                cnt += std::max(0, leftMax - container[l]);
                leftMax = std::max(leftMax, container[l++]);
            }
            else
            {
                cnt += std::max(0, rightMax - container[r]);
                rightMax = std::max(rightMax, container[r--]);
            }
        }
        return cnt;
    }
};
