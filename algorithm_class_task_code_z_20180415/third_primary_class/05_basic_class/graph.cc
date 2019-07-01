#include "graph.h"

Graph* GraphGenerator(const vector<vector<int>>& matrix)
{
  if (matrix.empty())
  {
    return nullptr;
  }
  
  Graph* graph = new Graph();
  assert(matrix[0].size == 3);
  for (int i = 0; i < matrix.size(); ++i)    
  {
    int from = matrix[i][0];
    int to = matrix[i][1];
    int weight = matrix[i][2];
    if (graph->nodes.find(&from) == graph->nodes.end())
    {
      graph->nodes[&from] = new Node(from);
    }
    if (graph->nodes.find(&to) == graph->nodes.end())
    {
      graph->nodes[&to] = new Node(to);
    }
    Node* fromNode = graph->nodes[&from];
    Node* toNode = graph->nodes[&to];
    Edge* edge = new Edge(weight, fromNdoe, toNode);
    fromNode->nexts.push_back(toNode);
    fromNode->out++;
    toNode->in++;
    fromNode->edges.push_back(edge);
    graph->edges.insert(edge);
  }
  return greph;
}
