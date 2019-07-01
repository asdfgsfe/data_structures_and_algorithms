#include <iostream>
#include <vector>
#include <algorithm>

using std::vector;

struct Node
{
  int cost;
  int profit;
  Node() {}
  Node(int c, int p)
    : cost(c), profit(p) {}
};

void PrintNodes(const vector<Node>& nodes)
{
  for (auto node : nodes)
  {
    std::cout << node.cost << "->" << node.profit << " ";
  }
  std::cout << std::endl;
}

int FindMaximizedCaptital(const vector<int>& costs, const vector<int>& profits, int k, int w)
{
  if (costs.empty() || profits.empty() || costs.size() != profits.size() || k <= 0)
  {
    return 0;
  }
  vector<Node> projects(costs.size());
  for (int i = 0; i < costs.size(); ++i)
  {
    projects[i] = Node(costs[i], profits[i]);
  }
  auto MinCostCamparator = [&](const Node& n1, const Node& n2) -> bool {return n1.cost > n2.cost;};
  auto MaxProfitCamparator = [&](const Node& n1, const Node& n2) -> bool {return n1.profit < n2.profit;};
  std::make_heap(projects.begin(), projects.end(), MinCostCamparator);
  PrintNodes(projects);
  vector<Node> maxProfits;
  for (int i = 0; i < k; ++i)
  {
    while (!projects.empty() && projects.front().cost <= w)
    {
      std::pop_heap(projects.begin(), projects.end(), MinCostCamparator);
      maxProfits.push_back(projects.back());
      projects.pop_back();
      std::push_heap(maxProfits.begin(), maxProfits.end(), MaxProfitCamparator);
    }
    PrintNodes(maxProfits);
    if (maxProfits.empty())
    {
      return w;
    }
    std::pop_heap(maxProfits.begin(), maxProfits.end(), MaxProfitCamparator);
    w += maxProfits.back().profit;
    maxProfits.pop_back();
  }
  return w;
}

int main(void)
{
  vector<int> costs = {4, 7 ,1, 8};
  vector<int> profits = {2, 1, 9, 3};
  int w = 5;
  int k = 3;
  std::cout << FindMaximizedCaptital(costs, profits, k, w) << std::endl;

  return 0;
}
