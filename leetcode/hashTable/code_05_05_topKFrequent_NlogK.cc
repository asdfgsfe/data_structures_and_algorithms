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