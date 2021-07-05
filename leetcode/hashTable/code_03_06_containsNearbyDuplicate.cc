//存在重复元素 II
class Solution {
public:
	bool containsNearbyDuplicate(vector<int>& nums, int k) {
		if (nums.empty())
		{
			return false;
		}
		unordered_set<int> klen;
		// i - j的绝对值小于等于k 利用固定长度的set
		// 滑动窗口模型 固定长度的窗口
		for (int i = 0; i < nums.size(); ++i)
		{
			if (klen.count(nums[i]))
			{
				return true;
			}
			klen.emplace(nums[i]);
			if (klen.size() > k)
			{
				//窗口长度太长 删除超过窗口的值 
				//有重复值无所谓 因为重复值如果是答案 前面肯定已经找过了
				klen.erase(nums[i - k]);
			}
		}
		return false;
	}
};

class Solution {
public:
	bool containsNearbyDuplicate(vector<int>& nums, int k) {
		if (nums.empty())
		{
			return false;
		}
		//利用map
		unordered_map<int, int> numToIds;
		for (int i = 0; i < nums.size(); ++i)
		{
			auto id = numToIds.find(nums[i]);
			if (id != numsToIds.end() && i - id->second <= k)
			{
				return true;
			}
			//由于要找i-j<=k 所以存最近的一次i
			//有些题目要求存>= 就要存最远的一次
			numsToIds[nums[i]] = i;
		}
		return false;
	}
};
