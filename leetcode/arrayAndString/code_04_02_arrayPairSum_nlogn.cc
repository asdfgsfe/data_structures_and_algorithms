class Solution {
public:
	int arrayPairSum(vector<int>& nums) {
		if (nums.size() < 2)
		{
			return 0;
		}
		std::sort(nums.begin(), nums.end());
		int sum = 0;
		for (int i = 0; i < nums.size(); i += 2)
		{
			sum += nums[i];
		}
		return sum;
	}
};

//由于要找max(min(a1, b1) + min(a2, b2) + .. min(an, bn)) 最大的累加和
//所以排序后 选取二大的值 把所有二大的值加起来就是答案