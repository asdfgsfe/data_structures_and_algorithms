struct Project
{
	int cost;
	int profit;
	Project()
		cost(0), profit(0)
	{}
	Project(int c, int p)
		: cost(c), profit(p)
	{}
};

int MaxProfit(const vector<int>& costs, const vector<int>& profits, int k, int m)
{
	if (costs.empty() || profits.empty() || costs.size() != profits.size() || k < 1 || m < 1)
	{
		return 0;
	}
	
	auto minCost = [](const auto& lhs, const auto& rhs) ->bool
					{
						return lhs.cost > rhs.cost;
					});
	auto maxProfit = [](const auto& lhs, const auto& rhs) ->bool
					{
						return lhs.profit < rhs.profit;
					});
	vector<Project> projects;
	projects.reserve(costs.size());
	for (int i = 0; i < costs.size(); ++i)
	{
		projects.emplace_back(costs[i], profits[i]);
		std::push_heap(projects.begin(), projects.end(), minCost);
	}
	vector<Project> maxProfits;
	for (int i = 0; i < k; ++i)
	{
		while (!projects.empty() && projects.front() <= w)
		{
			maxProfits.emplace_back(projects.front());
			std::push_heap(maxProfits.begin(), maxProfit.end(), maxProfit);
			std::pop_heap(projects.begin(), projects.end(), minCost);
			projects.pop_back();
		}
		if (!maxProfits.empty() && w >= maxProfits.front())
		{
			w += maxProfits.front();
			std::pop_heap(maxProfits.begin(), maxProfits.end(), maxProfit);
			maxProfits.pop_back();
		}
	}
	return w;
}