前 K 个高频元素
给你一个整数数组 nums 和一个整数 k ，请你返回其中出现频率前 k 高的元素。你可以按 任意顺序 返回答案。

 

示例 1:

输入: nums = [1,1,1,2,2,3], k = 2
输出: [1,2]
示例 2:

输入: nums = [1], k = 1
输出: [1]
 

提示：

1 <= nums.length <= 105
k 的取值范围是 [1, 数组中不相同的元素的个数]
题目数据保证答案唯一，换句话说，数组中前 k 个高频元素的集合是唯一的
 

进阶：你所设计算法的时间复杂度 必须 优于 O(n log n) ，其中 n 是数组大小。

相关标签
数组
哈希表
分治
桶排序
计数
快速选择
排序
堆（优先队列）

作者：力扣 (LeetCode)
链接：https://leetcode-cn.com/leetbook/read/top-interview-questions-medium/xvzpxi/
来源：力扣（LeetCode）
著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。

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
