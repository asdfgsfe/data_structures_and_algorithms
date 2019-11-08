#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <stack>
#include <assert.h>
#include <unordered_set>

using std::string;
using std::vector;
using std::stack;
using std::unordered_set;





class Solution {
public:
	int fa(int n)
	{
		if (n < 4)
		{
			return 0x80000000;
		}
		return std::min(fb(n - 1), std::min(fb(n - 2), fb(n - 3)));
	}

	int fb(int n)
	{
		if (n < 4)
		{
			return 0x7fffffff;
		}
		return std::max(fa(n - 1), std::max(fa(n - 2), fa(n - 3)));
	}

	//递归 考虑返回true和false也是可以的
	bool canWinNim(int n) {
		if (n < 4)
		{
			return true;
		}
		//nt ret = fa(n);
		return fa(n) < 4;
	}

	//动态规划
	bool canWinNim2(int n) {
		if (n < 4)
		{
			return true;
		}
		vector<int> dpa(n);
		vector<int> dpb(n);
		for (int i = 0; i < 3; ++i)
		{
			dpa[i] = 0x80000000;
			dpb[i] = 0x7fffffff;
		}
		for (int i = 3; i < n; ++i)
		{
			dpa[i] = std::min(dpb[i - 1], std::min(dpb[i - 2], dpb[i - 3]));
			dpb[i] = std::max(dpa[i - 1], std::max(dpa[i - 2], dpa[i - 3]));
		}
		//std::cout << "canWinNim2 dpa[n-3]=" << dpa[n - 3] << " dp[n-2]=" << dpa[n - 2] << " dp[n-1]=" << dpa[n-1] << " n=" << n << std::endl;
		return dpa[n - 1] < 4;
	}

	//举证压缩
	bool canWinNim3(int n) {
		if (n < 4)
		{
			return true;
		}
		vector<int> dpa(3, 0x80000000);
		vector<int> dpb(3, 0x7fffffff);
		for (int i = 3; i < n; ++i)
		{
			int fa = std::min(dpb[2], std::min(dpb[1], dpb[0]));
			int fb = std::max(dpa[2], std::max(dpa[1], dpa[0]));
			dpa[0] = dpa[1];
			dpa[1] = dpa[2];
			dpa[2] = fa;
			dpb[0] = dpb[1];
			dpb[1] = dpb[2];
			dpb[2] = fb;
		}
		return dpa[2] < 4;
	}
};

template<typename T>
 void Dump(const vector<T>& vals)
 {
	 for (auto val: vals)
	 {
		 std::cout << val << std::endl;
	 }
	 std::cout << std::endl;
 }

int main(void)
{
	Solution s;
	std::cout << s.canWinNim3(1348820612) << std::endl;
	return 0;
}