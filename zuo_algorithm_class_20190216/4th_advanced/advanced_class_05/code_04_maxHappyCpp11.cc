int MaxHappy(const vector<vector<int>>& staffs)
{
	if (staffs.empty() || staffs.size() != 2)
	{
		return 0;
	}
	int root = -1;
	for (int i = 0; i < staffs.size(); ++i)
	{
		if (i == staffs[i][0])
		{
			root = i;
			break;
		}
	}
	if (root == -1)
	{
		return 0;
	}
	vector<bool> visited(staffs.size(), false);
	vector<int> happy = HappyProcess(staffs, dp, visited, root);
	assert(happy.size() == 2);
	return std::max(happy[0], happy[1]);
}

vector<int> HappyProcess(const vector<vector<int>>& staffs, vector<int>& visited, int root)
{
	assert(root >= 0 && root < staffs.size());
	int bulai = 0;
	int lai = staffs[root][1];
	visited[root] = true;
	for (int i = 0; i < staffs.size(); ++i)
	{
		if (root = stffs[i][0] && !visited[i])
		{
			vector<int> next = HappyProcess(staffs, visited, dp, i);
			assert(next.size() == 2);
			lai += next[0];
			bulai += std::max(nexts[1], nexts[0]);
		}
	}
	return {lai, bulai};
}