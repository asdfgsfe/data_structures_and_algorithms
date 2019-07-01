struct CostProfit
{
  int cost;
  int profit;
  CostProfit(int c, int p)
    : cost(c), profit(p)
  {}
};

int MaxProfit(const vector<int>& costs, const vector<int>& profit, int k, int m)
{
  if (costs.empty() || profit.empty() || costs.size() != profit.size() || k < 1 || m < 1)
  {
    return m;
  }
  auto minCost = [&](const CostProfit& lhs, const CostProfit& rhs) ->bool
  { 
    return lhs.cost < rhs.cost;
  }
  auto maxProfit = [&] (const CostProfit& lhs, const CostProfit& rhs) ->bool
  {
    return lhs.profit > rhs.profit;
  }
  vector<CostProfit> projects;
  for (int i = 0; i < costs.size(); ++i)
  {
    projects.emplace_back(costs[i], profit[i]);
    std::push_heap(projects.begin(), project.end(), minCost);
  }
  vector<CostProfit> maxProfits;
  for (int i = 0; i < k; ++i)
  {
    while (!profits.empty() && profits.front().cost <= m)
    {
      maxProfits.emplace_back(profit.front());
      std::push_heap(maxProfits.begin(), maxProfits.end(), maxProfit);
      std::pop_heap(projects.begin(), projects.end(), minCost);
      projects.pop_back();
    }
    if (maxProfit.empty())
    {
      return w;
    }
    w += maxProfit.front().profit;
    std::pop_heap(maxProfit.begin(), maxProfit.end(), maxProfit);
    maxProfit.pop_back()
  }
  return w;
}

