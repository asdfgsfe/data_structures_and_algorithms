class Solution {
public:
	vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
		if (nums1.empty() || nums2.empty())
		{
			return {};
		}
		unordered_map<int, vector<int>> numToIds;
		for (int i = 0; i < nums1.size(); ++i)
		{
			numToIds[nums1[i]].emplace_back(i);
		}
		unordered_map<int, int> visited;
		vector<int> intersection;
		for (int num : nums2)
		{
			auto ids = numToIds.find(num);
			auto preId = visited.find(num);
			if (ids != numToIds.end() && (preId == visited.end() || preId->second + 1< ids->second.size()))
			{
				intersection.emplace_back(num);
				visited[num] = preId == visited.end() ? 0 : preId->second + 1;
			}
		}
		return intersection;
	}
};