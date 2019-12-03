class Solution {
public:
	vector<string> findRestaurant(vector<string>& list1, vector<string>& list2) {
		if (list1.empty() || list2.empty())
		{
			return {};
		}
		unordered_map<string, int> eateryToIds;
		for (int i = 0; i < list1.size(); ++i)
		{
			eateryToIds[list1[i]] = i;
		}
		unordered_map<int, vector<int>> sumToIds;
		int minId = 0x7fffffff;
		for (int i = 0; i < list2.size(); ++i)
		{
			auto id = eateryToIds.find(list2[i]);
			if (id != eateryToIds.end() && minId >= id->second + i)
			{
				minId = id->second + i;
				sumToIds[minId].emplace_back(i);
			}
		}
		vector<string> eaterys;
		const vector<int>& ids = sumToIds[minId];
		for (int id : ids)
		{
			eaterys.emplace_back(list2[id]);
		}
		return eaterys;
	}
};