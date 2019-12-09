方法一：枚举
我们可以使用递归，枚举出所有可能的情况。具体地，当我们处理到第 i 个数时，我们可以将它添加 + 或 -，
递归地搜索这两种情况。当我们处理完所有的 N 个数时，我们计算出所有数的和，并判断是否等于 S。

Java
public class Solution {
    int count = 0;
    public int findTargetSumWays(int[] nums, int S) {
        calculate(nums, 0, 0, S);
        return count;
    }
    public void calculate(int[] nums, int i, int sum, int S) {
        if (i == nums.length) {
            if (sum == S)
                count++;
        } else {
            calculate(nums, i + 1, sum + nums[i], S);
            calculate(nums, i + 1, sum - nums[i], S);
        }
    }
}
复杂度分析

时间复杂度：O(2^N)O(2 
N
 )，其中 NN 是数组 nums 的长度。

空间复杂度：O(N)O(N)，为递归使用的栈空间大小。

方法二：动态规划
这道题也是一个常见的背包问题，我们可以用类似求解背包问题的方法来求出可能的方法数。

我们用 dp[i][j] 表示用数组中的前 i 个元素，组成和为 j 的方案数。考虑第 i 个数 nums[i]，
它可以被添加 + 或 -，因此状态转移方程如下：

dp[i][j] = dp[i - 1][j - nums[i]] + dp[i - 1][j + nums[i]]
也可以写成递推的形式：

dp[i][j + nums[i]] += dp[i - 1][j]
dp[i][j - nums[i]] += dp[i - 1][j]
由于数组中所有数的和不超过 1000，那么 j 的最小值可以达到 -1000。
在很多语言中，是不允许数组的下标为负数的，因此我们需要给 dp[i][j] 的第二维预先增加 1000，即：

dp[i][j + nums[i] + 1000] += dp[i - 1][j + 1000]
dp[i][j - nums[i] + 1000] += dp[i - 1][j + 1000]
下面的幻灯片中，为了表述方便，我们将数组中所有数的和控制在 [-6, 6] 之间，仅将 dp[i][j] 的第二维预先增加 6。


1 / 7

Java
public class Solution {
    public int findTargetSumWays(int[] nums, int S) {
        int[][] dp = new int[nums.length][2001];
        dp[0][nums[0] + 1000] = 1;
        dp[0][-nums[0] + 1000] += 1;
        for (int i = 1; i < nums.length; i++) {
            for (int sum = -1000; sum <= 1000; sum++) {
                if (dp[i - 1][sum + 1000] > 0) {
                    dp[i][sum + nums[i] + 1000] += dp[i - 1][sum + 1000];
                    dp[i][sum - nums[i] + 1000] += dp[i - 1][sum + 1000];
                }
            }
        }
        return S > 1000 ? 0 : dp[nums.length - 1][S + 1000];
    }
}
复杂度分析

时间复杂度：O(N*\text{sum})O(N∗sum)，其中 NN 是数组 nums 的长度。

空间复杂度：O(N*\text{sum})O(N∗sum)。

方法三：动态规划 + 空间优化
我们发现，方法二中动态规划的状态转移方程中，dp[i][...] 只和 dp[i - 1][...] 有关，
因此我们可以优化动态规划的空间复杂度，只需要使用两个一维数组即可。

Java
public class Solution {
    public int findTargetSumWays(int[] nums, int S) {
        int[] dp = new int[2001];
        dp[nums[0] + 1000] = 1;
        dp[-nums[0] + 1000] += 1;
        for (int i = 1; i < nums.length; i++) {
            int[] next = new int[2001];
            for (int sum = -1000; sum <= 1000; sum++) {
                if (dp[sum + 1000] > 0) {
                    next[sum + nums[i] + 1000] += dp[sum + 1000];
                    next[sum - nums[i] + 1000] += dp[sum + 1000];
                }
            }
            dp = next;
        }
        return S > 1000 ? 0 : dp[S + 1000];
    }
}
复杂度分析

时间复杂度：O(N*\text{sum})O(N∗sum)，其中 NN 是数组 nums 的长度。

空间复杂度：O(\text{sum})O(sum)。

作者：LeetCode
链接：https://leetcode-cn.com/problems/target-sum/solution/mu-biao-he-by-leetcode/
来源：力扣（LeetCode）
著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。


//没看懂 背包问题
class Solution {
public:
 int findTargetSumWays(vector<int>& nums, int S) {
        int sum = 0;
        for (int num : nums) {
            sum += num;
        }
        if (sum < S || (sum + S) % 2 == 1) {
            return 0;
        }
        int w = (sum + S) / 2;
        vector<int>dp(w+1,0);
        dp[0] = 1;
        for (int num : nums) {
            for (int j = w; j >= num; j--) {
                dp[j]= dp[j - num]+dp[j];
            }
        }
        return dp[w];
 }
    };