01背包
思路
原问题是给定一些数字，加加减减，使得它们等于targert。例如，1 - 2 + 3 - 4 + 5 = target(3)。
如果我们把加的和减的结合在一起，可以写成

(1+3+5)  +  (-2-4) = target(3)
-------     ------
 -> 正数    -> 负数
所以，我们可以将原问题转化为： 找到nums一个正子集和一个负子集，使得总和等于target，统计这种可能性的总数。

我们假设P是正子集，N是负子集。让我们看看如何将其转换为子集求和问题：

                  sum(P) - sum(N) = target
                  （两边同时加上sum(P)+sum(N)）
sum(P) + sum(N) + sum(P) - sum(N) = target + sum(P) + sum(N)
            (因为 sum(P) + sum(N) = sum(nums))
                       2 * sum(P) = target + sum(nums)
因此，原来的问题已转化为一个求子集的和问题： 找到nums的一个子集 P，使得

sum(P) = \frac{target + sum(nums)}{2}
sum(P)= 
2
target+sum(nums)
​	
 

根据公式，若target + sum(nums)不是偶数，就不存在答案，即返回0个可能解。

因此题目转化为01背包，也就是能组合成容量为sum(P)的方式有多少种,一种组合中每个数字只能取一次。
解决01背包问题使用的是动态规划的思想。

方法是

开辟一个长度为P+1的数组，命名为dp
dp的第x项，代表组合成数字x有多少方法。比如说,dp[0] = 1，代表组合成0只有1中方法，即什么也不取。
比如说dp[5] = 3 ，代表使总和加到5总共有三种方法。
所以最后返回的就是dp[P]，代表组合成P的方法有多少种
问题是

怎么更新dp数组呢？

遍历nums，遍历的数记作num
再逆序遍历从P到num，遍历的数记作j
更新dp[j] = dp[j - num] + dp[j]
这样遍历的含义是，对每一个在nums数组中的数num而言，dp在从num到P的这些区间里，都可以加上一个num，
来到达想要达成的P。
举例来说，对于数组[1,2,3,4,5]，想要康康几种方法能组合成4,那么设置dp[0]到dp[4]的数组
假如选择了数字2,那么dp[2:5]（也就是2到4）都可以通过加上数字2有所改变，
而dp[0:2]（也就是0到1）加上这个2很明显就超了，就不管它。
以前没有考虑过数字2,考虑了会怎么样呢？就要更新dp[2:5]，比如说当我们在更新dp[3]的时候，
就相当于dp[3] = dp[3] + dp[1],即本来有多少种方法，加上去掉了2以后有多少种方法。
因为以前没有考虑过2,现在知道，只要整到了1,就一定可以整到3。
为什么以这个顺序来遍历呢？
假如给定nums = [num1,num2,num3]，我们现在可以理解dp[j] = dp[j-num1] + dp[j-num2] + dp[j-num3]。

但是如何避免不会重复计算或者少算？要知道，我们的nums并不是排序的，我们的遍历也不是从小到大的。

我们不妨跟着流程走一遍

第一次num1，仅仅更新了dp[num1] = 1，其他都是0+0都是0啊都是0
第二次num2，更新了dp[num2] = 1和dp[num1+num2] = dp[num1+num2] + dp[num1] = 1,先更新后者。
第三次num3，更新了dp[num3] = 1和dp[num1+num3] += 1和dp[num2+num3] += 1和dp[num1+num2+num3] += 1。
按下标从大到小顺序来更新。
......
由此可见，这种顺序遍历能得到最后的答案。这里可以跟着IDE的debug功能走一遍，加深理解。

代码
class Solution:
    def findTargetSumWays(self, nums: List[int], S: int) -> int:
        if sum(nums) < S or (sum(nums) + S) % 2 == 1: return 0
        P = (sum(nums) + S) // 2
        dp = [1] + [0 for _ in range(P)]
        for num in nums:
            for j in range(P,num-1,-1):dp[j] += dp[j - num]
        return dp[P]
这个方法用时只有第一种DFS的十分之一，也只有第三种DP方法的十分之一。

作者：jimmy00745
链接：https://leetcode-cn.com/problems/target-sum/solution/python-dfs-xiang-jie-by-jimmy00745/
来源：力扣（LeetCode）
著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。