#include <assert.h>

#include <iostream>
#include <vector>
#include <algorithm>

struct Node
{
  int cost;
  int profit;

  Node(int c, int p) 
    : cost(c), profit(p)
  {}
};

class MinCostComparator
{
public:
  int operator() (const Node o1, const Node o2)
  {
    return o2.cost - o1.cost;
  }
};

class MaxProfitComparator
{
public:
  int operator() (const Node o1, const Node o2)
  {
    return o1.profit - o2.profit; 
  }
};

void PrintVector(const std::vector<int>& v)
{
  std::cout << "[";
  for (int i = 0; i < v.size(); ++i)
  {
    std::cout << v[i] << " ";
  }
  std::cout << "]" << std::endl;
}

void PrintHeap(const std::vector<Node>& heap)
{
  std::cout << "[";
  for (int i = 0; i < heap.size(); ++i)
  {
    std::cout << "(" << heap[i].cost << "," << heap[i].profit << ")"; 
  }
  std::cout << "]" << std::endl;
}

int FindMaximizedCapital(int k, int w, const std::vector<int>& costs, const std::vector<int>& profits)
{
  assert(costs.size() == profits.size());
  assert(costs.size() >= k);
  
  std::vector<Node> minCostHeap;
  std::vector<Node> maxProfitHeap;
  for (int i = 0; i < costs.size(); ++i)
  {
    Node node(costs[i], profits[i]);
    minCostHeap.push_back(node);
    std::push_heap(minCostHeap.begin(), minCostHeap.end(), MinCostComparator());
  }

  PrintHeap(minCostHeap);
  PrintHeap(maxProfitHeap);

  for (int i = 0; i < k; ++i)
  {
    while (!minCostHeap.empty() && minCostHeap[0].cost <= w)
    {
      maxProfitHeap.push_back(minCostHeap[0]);
      std::pop_heap(minCostHeap.begin(), minCostHeap.end(), MinCostComparator());
      minCostHeap.pop_back();
      std::push_heap(maxProfitHeap.begin(), maxProfitHeap.end(), MaxProfitComparator());
    }
    
    std::cout << "{" << i;
    PrintHeap(minCostHeap);
    PrintHeap(maxProfitHeap);

    if (maxProfitHeap.empty())
    {
      return w;
    }
    w += maxProfitHeap[0].profit; 
    std::pop_heap(maxProfitHeap.begin(), maxProfitHeap.end(), MaxProfitComparator());
    maxProfitHeap.pop_back();

    PrintHeap(minCostHeap);
    PrintHeap(maxProfitHeap);

    std::cout << "}" << std::endl;
  }
  return w;
}

int main(void)
{
  int c[] = {5, 2, 4, 1};
  int p[] = {3, 6, 2, 5};
  std::vector<int> costs(c, c+4);
  std::vector<int> costs1(c, c+4);
  std::vector<int> costs2(c, c+4);
  std::make_heap(costs1.begin(), costs1.end(), std::greater<int>());
  PrintVector(costs1);

  std::vector<int> profits(p, p+4);
  int k = 2;
  int w = 1;
  std::cout << FindMaximizedCapital(k, w, costs, profits) << std::endl;

  return 0;
}


