vector<vector<int>> BuildOutLine(const vector<vector<int>>& floors)
{
	if (floors.empty() || floors[0].size() != 3)
	{
		return vector<vector<int>>();
	}
	vector<vector<int>> lines(floors.size() * 2);
	for (int i = 0; i < floors.size(); ++i)
	{
		lines[i * 2] = {floors[i][0], floors[i][2], 1}; //1==ио
		lines[i * 2 + 1] = {floors[i][1], floors[i][2], 0};
	}
	std::sort(lines.begin(), lines.end(), 
		[](const auto& lhs, const auto& rhs)
		{
			if (lhs[0] != rhs[0])
			{
				return lhs[0] < rhs[0];
			}
			return lhs[2] ? true : false;
		});
	map<int, int> heightTimes;
	heightTimes[0] = 0;
	map<int, int> posHeight;
	for (const auto& line : lines)
	{
		if (line[2])
		{
			++heightTimes[line[1]];
		}
		else
		{
			auto times = heightTimes.find(line[1]);
			assert(times);
			--times->second;
			if (times->second == 0)
			{
				heightTimes.erase(times);
			}
		}
		posHeight[line[0]] = heightTimes.empty() ? 0 : heightTimes.rbegin()->first;
	}
	vector<vector<int>> outline;
	int pre = posHeight.begin()->first;
	int height = posHeight.begin()->second;
	for (const auto& ph : posHeight)
	{
		if (height < ph.second)
		{
			outline.emplace_back(pre, ph.first, ph.second);
			pre = ph.first;
			height = ph.second;
		}
	}
	return outlines;
}