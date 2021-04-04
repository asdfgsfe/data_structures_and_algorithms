class Solution {
public:
	vector<int> topKFrequent(vector<int>& nums, int k) {
		if (nums.empty() || k < 1 || k > nums.size())
		{
			return {};
		}
		unordered_map<int, int> numToTimes;
		for (int num : nums)
		{
			++numToTimes[num];
		}
		if (k > numToTimes.size())
		{
			return {};
		}
		auto compare = [](const auto& lhs, const auto& rhs) {return lhs.second > rhs.second; };
		vector<pair<int, int>> topk;
		for (pair<const int, int>& times : numToTimes)
		{
			if (topk.size() < k)
			{
				topk.emplace_back(std::move(times));
				std::push_heap(topk.begin(), topk.end(), compare);
				continue;
			}
			if (times.second > topk[0].second)
			{
				std::pop_heap(topk.begin(), topk.end(), compare);
				topk.back() = times;
				std::push_heap(topk.begin(), topk.end(), compare);
			}
		}
		vector<int> topkNums(k);
		int p = 0;
		for (const pair<int, int>& num : topk)
		{
			topkNums[p++] = num.first;
		}
		return topkNums;
	}
};


前 K 个高频元素
给定一个非空的整数数组，返回其中出现频率前 k 高的元素。

 

示例 1:

输入: nums = [1,1,1,2,2,3], k = 2
输出: [1,2]
示例 2:

输入: nums = [1], k = 1
输出: [1]
 

提示：

你可以假设给定的 k 总是合理的，且 1 ≤ k ≤ 数组中不相同的元素的个数。
你的算法的时间复杂度必须优于 O(n log n) , n 是数组的大小。
题目数据保证答案唯一，换句话说，数组中前 k 个高频元素的集合是唯一的。
你可以按任意顺序返回答案。
相关标签
堆
哈希表

作者：力扣 (LeetCode)
链接：https://leetcode-cn.com/leetbook/read/top-interview-questions/xau4ci/
来源：力扣（LeetCode）
著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。
