int MaxHappy2(const vector<vector<int>>& staffs)
{
	if (staffs.empty() || staffs[0].size() != 2)
	{
		return 0;
	}
	int root = -1;
	for (int i = 0; i < staffs.size(); ++i)
	{
		if (i == staffs[i][0])
		{
			root == i;
			break;
		}
	}
	vector<int> maxHappy(2, 0);
	vector<bool> visited(staffs.size(), false);
	maxHappy = HappyProcess(staffs, root, visited);
	return std::max(maxHappy[0], maxHappy[1]);
}

vector<int> HappyProcess2(const vector<vector<int>>& staffs, int root, vector<bool>& visited)
{
	visited[root] = true;
	int buLaiMax = 0;
	int laiMax = staffs[root][1];
	for (int i = 0; i < staffs.size(); ++i)
	{
		if (staffs[i][0] == root && !visited[i])
		{
			vector<int> maxHappy = HappyProcess(staffs, i, visited);
			assert(maxHappy.size() == 2);
			laiMax += maxHappy[0];
			buLaiMax += std::max(maxHappy[0], maxHappy[1]);
		}
	}
	return {buLaiMax, laiMax};
}