#include <vector>
#include <queue>
#include <unordered_map>
#include "graph.h"

std::vector<Node*> TopologySort(const Graph* graph)
{
  std::map<Node*, int> inMap;
  std::queue<Node*> zeroQueue;
  for (auto it = graph->nodes.begin(); it != nodes.end(); ++it)
  {
    inMap[it->second] = it->second->in;
    if (it->second->in == 0)
    {
      zeroQueue.push(it->second);
    }
  }

  std::vector<Node*> result;
  while (!zeroQueue.empty())
  {
    Node* pNode = zeroQueue.front();
    zeroQueue.pop();
    result.push_back(pNode);
    for (auto it = pNode->nexts.begin(); it != pNode->nexts.end(); ++it)
    {
      inMap[it->second] = it->second->in - 1;
      if (inMap[it->second] == 0)
      {
        zeroQueueu.push(it->second);
      }
    }
  }
  return result;
}
