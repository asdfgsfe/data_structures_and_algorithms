#include <vector>
#include <queue>
#include <iostream>

using namespace std;

//不妨设dp[i] 代表 选取的数字累加和 模3 = i 的数字和
//假定nums[i] % 3 = 1 ，那么，和 前面选取的数字和模 3 = 2 的数相加，
//就可以模3为 0 ，表达起来就是 dp[0] = max(dp[0], nums[i] + dp[2])
//依次类推，只要不断更新 dp 数组即可，注意一点，更新的时候要保存上一个状态的值，
//避免后续更新的时候重复影响。
//掌握这种遍历子序列和为某一个固定值的方法
class Solution {
public:
	int maxSumDivThree(vector<int>& nums) {
		int dp[3] = { 0, 0, 0 };

		for (int i = 0; i < nums.size(); ++i) {
			int mod = nums[i] % 3;

			//代码 int a = dp[(3 + 0 - mod) % 3];保证dp[0]存的是最大的累加和取模等于1的值
			//如果mod = 1那么就拿出 dp[2]的值 + nums[i]与dp[0]比较
			//如果mod = 2那么就拿出 dp[1]的值 + nums[i]与dp[0]比较
			//如果mod = 0那么就拿出 dp[0]的值 + nums[i]与dp[0]比较

			//代码 int b = dp[(3 + 1 - mod) % 3];保证dp[1]存的是最大的累加和取模等于1的值
			//如果mod = 1那么就拿出 dp[0]的值 + nums[i]与dp[0]比较
			//如果mod = 2那么就拿出 dp[2]的值 + nums[i]与dp[0]比较
			//如果mod = 0那么就拿出 dp[1]的值 + nums[i]与dp[0]比较
			//c同理保证dp[2]

			//确保dp[0] 仅仅与(num[i] + dp[i]) % 3 == 0的比较
			int a = dp[(3 + 0 - mod) % 3]; 
			//为了更新dp[i] 也是仅仅与(num[i] + dp[i]) % 3 == 1的最大值
			int b = dp[(3 + 1 - mod) % 3];
			//为了更新dp[i] 也是仅仅与(num[i] + dp[i]) % 3 == 2的最大值
			int c = dp[(3 + 2 - mod) % 3];

			//a位true表示dp[i]中的值已经填过一次了 mod == i的目的是为了第一次填dp[i]
			if (a || mod == 0) dp[0] = std::max(dp[0], a + nums[i]);
			if (b || mod == 1) dp[1] = std::max(dp[1], b + nums[i]);
			if (c || mod == 2) dp[2] = std::max(dp[2], c + nums[i]);
			std::cout << dp[0] << " " << dp[1] << " " << dp[2] 
				<< " mod=" << mod 
				<< " a=" << a << " b=" << b << " c=" << c 
				<< " nums[i]" << nums[i] << std::endl;
		}
		return dp[0];
	}
};

int main(void)
{
	Solution s;
	vector<int> nums{ 3,6,5,1,8 };
	std::cout << s.maxSumDivThree(nums) << std::endl;

	return 0;
}

//给你一个整数数组 nums，请你找出并返回能被三整除的元素最大和。
//示例 1：
//
//输入：nums = [3, 6, 5, 1, 8]
//输出：18
//解释：选出数字 3, 6, 1 和 8，它们的和是 18（可被 3 整除的最大和）。
//示例 2：
//
//输入：nums = [4]
//输出：0
//解释：4 不能被 3 整除，所以无法选出数字，返回 0。
//示例 3：
//
//输入：nums = [1, 2, 3, 4, 4]
//输出：12
//解释：选出数字 1, 3, 4 以及 4，它们的和是 12（可被 3 整除的最大和）。
//
//
//提示：
//
//1 <= nums.length <= 4 * 10 ^ 4
//1 <= nums[i] <= 10 ^ 4