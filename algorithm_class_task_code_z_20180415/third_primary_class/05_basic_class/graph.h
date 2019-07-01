#ifndef _GRAPH_H_
#define _GRAPH_H_

#include <unordered_map>
#include <unoedered_set>
#include "node.h"
#include "edge.h"

class Graph
{
public:
  Graph(const vector<vector<int>>& matrix);
  void AddNode(const Node& node, const Edge& edge);
  void DeleteNode(const Node& node);
private:
  std::unordered_map<int, Node*> nodes;
  std::unoedered_set<Edge*> edges;
};

#endif 
//_GRAPH_H_
