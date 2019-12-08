class Solution {
public:
	vector<vector<int>> groupThePeople(vector<int>& groupSizes) {
		if (groupSizes.empty())
		{
			return{};
		}
		unordered_map<int, vector<int>> groupToUsers;
		for (int i = 0; i < groupSizes.size(); ++i)
		{
			groupToUsers[groupSizes[i]].emplace_back(i);
		}
		vector<vector<int>> users;
		for (const auto& groupToUser : groupToUsers)
		{
			const auto& user = groupToUser.second;
			int group = groupToUser.first;
			int i = 0;
			while (i < user.size())
			{
				vector<int> cur(group);
				int p = 0;
				while (p < group)
				{
					cur[p++] = user[i++];
				}
				users.emplace_back(std::move(cur));
			}
		}
		return users;
	}

};