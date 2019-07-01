//matrix[from, to, weight]
Graph MakeGraph(const vector<vector<int>>& matrix)
{
  Graph graph;
  for (const auto& node : matrix)
  {
    int from = node[0];
    int to = node[1];
    int weight = node[2];
    const auto& nodes = graph.nodes;
    if (nodes.find(from) == nodes.end())
    {
      nodes[from] = new Node(from);
    }
    if (nodes.find(to) == nodes.end())
    {
      nodes[to] = new Node(to);
    }
    Node* fromNode = node[from];
    Node* toNode = node[to];
    Edge* newEdge = new Edge(weight, fromNode, toNode);
    fromNode->nexts.emplace_back(toNode);
    ++fromNode->out;
    ++toNode->in;
    fromNode->edges.emplace_back(newEdge);
    graph.edges.emplace_back(newEdge);
  }
  return graph;
}
