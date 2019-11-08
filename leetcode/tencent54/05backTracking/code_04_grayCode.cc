格雷编码
格雷编码是一个二进制数字系统，在该系统中，两个连续的数值仅有一个位数的差异。

给定一个代表编码总位数的非负整数 n，打印其格雷编码序列。格雷编码序列必须以 0 开头。

示例 1:

输入: 2
输出: [0,1,3,2]
解释:
00 - 0
01 - 1
11 - 3
10 - 2

对于给定的 n，其格雷编码序列并不唯一。
例如，[0,2,3,1] 也是一个有效的格雷编码序列。

00 - 0
10 - 2
11 - 3
01 - 1
示例 2:

输入: 0
输出: [0]
解释: 我们定义格雷编码序列必须以 0 开头。
     给定编码总位数为 n 的格雷编码序列，其长度为 2n。当 n = 0 时，长度为 20 = 1。
     因此，当 n = 0 时，其格雷编码序列为 [0]。

class Solution {
public:
	vector<int> grayCode(int n) {
		if (n < 0 || n > 32)
		{
			return {};
		}
		int code = 0;
		vector<int> codes = {code};
		unordered_set<int> visited;
		visited.emplace(code);
		CodeProcess(n, codes, visited);
		return codes;
	}

	void CodeProcess(int n, vector<int>& codes, unordered_set<int>& visited)
	{
		assert(!codes.empty());
		int preCode;
		int m;
		for (m = 0; m < n; ++m)
		{
			preCode = codes.back();
			preCode ^= (1 << m);
			if (!visited.count(preCode))
			{
				break;
			}
		}
		if (m == n)
		{
			return;
		}
		codes.emplace_back(preCode);
		visited.emplace(preCode);
		CodeProcess(n, codes, visited);
	}
};