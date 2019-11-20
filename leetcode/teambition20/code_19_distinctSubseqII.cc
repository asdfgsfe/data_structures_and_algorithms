//官方分析方法一：动态规划
//虽然解决这题的代码很短，但它的算法并不是很容易设计。
//我们会用动态规划先求出包括空序列的所有子序列，再返回答案之前再减去空序列。
//我们用 dp[k] 表示 S[0 .. k] 可以组成的不同子序列的数目。
//如果 S 中的所有字符都不相同，例如 S = "abcx"，那么状态转移方程就是简单的 dp[k] = dp[k-1] * 2，
//例如 dp[2] = 8，它包括 ("", "a", "b", "c", "ab", "ac", "bc", "abc") 这 8 个不同的子序列，而 dp[3] 
//在这些子序列的末尾增加 x，就可以得到额外的 8 个不同的子序列，
//即 ("x", "ax", "bx", "cx", "abx", "acx", "bcx", "abcx")，因此 dp[3] = 8 * 2 = 16。
//但当 S 中有相同字母的时候，就要考虑重复计数的问题了，例如当 S = "abab" 时，我们有：
//dp[0] = 2，它包括 ("", "a")；
//dp[1] = 4，它包括 ("", "a", "b", "ab")；
//dp[2] = 7，它包括 ("", "a", "b", "aa", "ab", "ba", "aba")；
//dp[3] = 12，它包括 ("", "a", "b", "aa", "ab", "ba", "bb", "aab", "aba", "abb", "bab", "abab")。
//当从 dp[2] 转移到 dp[3] 时，我们只会在 dp[2] 中的 ("b", "aa", "ab", "ba", "aba") 的末尾增加 b，
//而忽略掉 ("", "a")，因为它们会得到重复的子序列。我们可以发现，这里的 ("", "a") 刚好就是 dp[0]，
//也就是上一次增加 b 之前的子序列集合。因此我们就得到了如下的状态转移方程：
//dp[k] = 2 * dp[k - 1] - dp[last[S[k]] - 1]
//即在计算 dp[k] 时，首先会将 dp[k - 1] 对应的子序列的末尾添加 S[k] 得到额外的 dp[k - 1] 个子序列，
//并减去重复出现的子序列数目，这个数目即为上一次添加 S[k] 之前的子序列数目 dp[last[S[k]] - 1]。

//https://leetcode-cn.com/problems/distinct-subsequences-ii/solution/bu-tong-de-zi-xu-lie-ii-by-leetcode/
//空间o(n) 时间o(n) 利用举证压缩技术可以空间可以优化到o(1)
class Solution {
    public int distinctSubseqII(String S) {
        int MOD = 1_000_000_007;
        int N = S.length();
        int[] dp = new int[N+1];
        dp[0] = 1;

        int[] last = new int[26];
        Arrays.fill(last, -1);

        for (int i = 0; i < N; ++i) {
            int x = S.charAt(i) - 'a';
            dp[i+1] = dp[i] * 2 % MOD;
            if (last[x] >= 0)
                dp[i+1] -= dp[last[x]];
            dp[i+1] %= MOD;
            last[x] = i;
        }

        dp[N]--;
        if (dp[N] < 0) dp[N] += MOD;
        return dp[N];
    }
}

//分析过程
//无重复字符的的情况下
// a	2^1 = 2 (包含了空串)
// ab	2^2 = 4
// abc  2^3 = 8
//则dp[i] = 2^(i + 1) 其中i位数组的下标 或者dp[i] = 2 * dp[i - 1]

//有重复字符的情况下
// a	a 2^1 = 2 (包含了空串)
// ab	a,b,ab	2^2 = 4
// aba  a,ab,aa,aba,b,ba	由于aba包含了a这个串 所以在计算子序列的过程中重复计算了a这个串的情况 
//设last表示字符a上次出现在数组中的位置 
//则 dp[i] = 2 * dp[i - 1] - dp[last]


class Solution
{
public:
	int distinctSubseqII(string S)
	{
		if (S.empty())
		{
			return 0;
		}
		const static int mod = 1000000007;
		vector<int> dp(S.size() + 1, 0);
		dp[0] = 1;
		vector<int> last(26, -1); //注意这里先不能last[S[0] - 'a'] = 0; 这样会多减一遍dp[S[0] - 'a']
		for (int i = 1; i < dp.size(); ++i)
		{
			dp[i] = dp[i - 1] * 2 % mod;
			int id = S[i - 1] - 'a';
			if (last[id] >= 0)
			{
				dp[i] = (dp[i] + mod - dp[last[id]]) % mod;
			}
			last[id] = i - 1;
		}

		return dp[dp.size() - 1] - 1;
	}
};

//最优解
from collections import defaultdict
class Solution:
    def distinctSubseqII(self, S: str) -> int:
        dp = defaultdict(int)
        
        res = 0
        for c in S:
            res, dp[c] = 2 * res - dp[c] + 1, res + 1
			#res = 2 * res - dp[c] + 1
			#dp[c] = res + 1
        
        return res % (10 ** 9 + 7)

三种dp方法，时间复杂度从O(N^2)到O(N)
Rui Ban
发布于 3 个月前
246 阅读
分析
思路一
子序列问题一般考虑结尾的字符，通过递推构建重复子问题。

先举例分析。

若s = "abc"，直观的想法是设dp[i]为s[:i+1]的以s[i]结尾的子序列数量，这里容易得到递推关系：

dp[i+1] = dp[0] + dp[1] + ... + dp[i] + 1（还有"" + s[i]这种情况）

如果没有重复元素，这种计算是正确的，接下来要考虑如何避免重复计算。

首先需要思考的是，重复计算是如何产生的。

考虑这个例子: s="abb"

dp[0]: {"a"}

dp[1]: {"ab", "b"}

dp[2]: {"ab", "abb", "bb", "b"}

在这里，dp[0]的含义是以a结尾的子序列数量，dp[1]和dp[2]的含义分别是ab中和abb中以b结尾的子序列数量，但显然dp[2]是包含了dp[1]的，这是因为ab是abb的子串，所以dp[1]也是dp[2]的子集。

因此在计算时，对于每一个字符，应统计最新的结果，忽略所有的子集。

基于这个思路，可以写出解法一，时间复杂度O(N^2)

思路二
在思路一中，dp[i]的含义是s[:i+1]的以s[i]结尾的子序列数量，而对于每个字符，都只考虑i最大的dp[i]。

可以修改dp的定义，使dp[c]的含义为：s的以字符c结尾的子序列数量。这样，递推公式可以写为：

dp[s[i]] = dp[a] + dp[b] + ... + dp[z] + 1

遍历完s后，最终结果为res = dp[a] + dp[b] + ... + dp[z]

具体解法见解法二，时间复杂度O(26*N)

思路三
在思路二中，每次迭代都需要计算dp[a] + dp[b] + ... + dp[z]，可以保存这个结果，使复杂度进一步降低到O(N)

设res = dp[a] + dp[b] + ... + dp[z]， 则递推公式为：

new_dp[s[i]] = res + 1

new_res = res - dp[s[i]] + new_dp[s[i]]
        = res * 2 - dp[s[i]] + 1
具体解法见解法三

解答
解法一
from collections import defaultdict
class Solution:
    def distinctSubseqII(self, S: str) -> int:
        dp = [1] * len(S)
        for i in range(1, len(S)):
            used = set()
            for j in range(i-1, -1, -1):
                if S[j] not in used:
                    dp[i] += dp[j]
                    used.add(S[j])
        res = 0
        u = set()
        for j in range(len(S)-1, -1, -1):
            if S[j] not in u:
                res += dp[j]
                u.add(S[j])    
        return res % (10**9 + 7)
解法二
from collections import defaultdict
class Solution:
    def distinctSubseqII(self, S: str) -> int:
        dp = defaultdict(int)
        
        for c in S:
            dp[c] = sum(dp.values()) + 1
        
        return sum(dp.values()) % (10 ** 9 + 7)
解法三
from collections import defaultdict
class Solution:
    def distinctSubseqII(self, S: str) -> int:
        dp = defaultdict(int)
        
        res = 0
        for c in S:
            res, dp[c] = 2 * res - dp[c] + 1, res + 1
        
        return res % (10 ** 9 + 7)