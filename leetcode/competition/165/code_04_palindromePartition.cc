class Solution {
public:
	int palindromePartition(string s, int k) {
		if (s.empty() || k > s.size())
		{
			return 0;
		}
		int n = s.size();
		//sum[i][j]表示将i~j这段字符串变为回文串需要的替换次数
		//这道题区别于仅仅判断是否问回文串 由于要统计变化的个数 所以用域处理数组记录下来
		//如果仅仅只是判断是否 就可以加入到dp中去判断
		vector<vector<int>>sum(n, vector<int>(n, 0));
		for (int i = 0; i < n; ++i) 
		{
			for (int j = i + 1; j < n; ++j) 
			{
				int l = i;
				int r = j;
				while (l < r)
				{
					sum[i][j] = s[l++] != s[r--] ? sum[i][j] + 1 : sum[i][j];
				}
			}
		}
		//dp[i][j]表示将前i个字符变为j个回文串所需的最小代价。
		//注意这里的初始化10000 很微妙 不能是0x7fffffff 累加会溢出
		vector<vector<int>>dp(n + 1, vector<int>(k + 1, 1000));
		for (int i = 0; i < dp[0].size(); i++) 
		{
			dp[0][dp[0].size() - 1] = 0;
		}
		for (int i = 1; i < dp.size(); i++) 
		{
			dp[i][1] = sum[0][i - 1];
		}
		for (int i = 1; i < dp.size(); ++i) 
		{
			for (int j = 2; j < dp[0].size(); ++j) 
			{
				for (int m = 1; m < i; ++m) 
				{
					dp[i][j] = std::min(dp[i][j], sum[m][i - 1] + dp[m][j - 1]);
				}
			}
		}
		return dp[n][k];
	}
};

给你一个由小写字母组成的字符串 s，和一个整数 k。

请你按下面的要求分割字符串：

首先，你可以将 s 中的部分字符修改为其他的小写英文字母。
接着，你需要把 s 分割成 k 个非空且不相交的子串，并且每个子串都是回文串。
请返回以这种方式分割字符串所需修改的最少字符数。

 

示例 1：

输入：s = "abc", k = 2
输出：1
解释：你可以把字符串分割成 "ab" 和 "c"，并修改 "ab" 中的 1 个字符，将它变成回文串。
示例 2：

输入：s = "aabbc", k = 3
输出：0
解释：你可以把字符串分割成 "aa"、"bb" 和 "c"，它们都是回文串。
示例 3：

输入：s = "leetcode", k = 8
输出：0
 

提示：

1 <= k <= s.length <= 100
s 中只含有小写英文字母。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/palindrome-partitioning-iii
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。