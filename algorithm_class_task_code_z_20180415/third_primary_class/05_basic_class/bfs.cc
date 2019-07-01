#include <iostream>
#include <queue>
#include <unordered_set>
#include "node.h"

void BFS(const Node* pNode)
{
  if (pNode == nullptr)
  {
    return;
  }
  
  std::queue<Node*> nodeQue;
  std::unordered_set<Node*> nodeSet;
  que.push(pNode);
  nodeSet(pNode);
  while (!que.empty())
  {
    pNode = que.front();
    que.pop();
    std::cout << pNode->val << " ";
    for (auto it = pNode->nexts.begin(); it != pNode->nexts.end(); ++it)
    {
      if (nodeSet.find(*it) == nodeSet.end())
      {
        nodeSet.insert(*it);
        nodeQue.push(*it);
      }
    }
  }
}
