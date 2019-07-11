struct Node
{
  bool isUp;
  int p;
  int h;
  Node() {}
  Node(bool up, int position, int height)
    : isUp(up), p(position), h(height)
  {}
};

vector<vector<int>> BuildingOutline(const vector<vector<int>>& matrix)
{
  if (matrix.empty() || matrix[0].size() != 3)
  {
    return vector<vector<int>>();
  }
  vector<Node> nodes(matrix.size());
  for (int i = 0; i < matrix.size(); ++i)
  {
    nodes[2 * i] = Node(true, matrix[i][0], matrix[i][2]);
    nodes[2 * i + 1] = Node(false, matrix[i][1], matrix[i][2]);
  }
  std::sort(nodes.begin(), nodes.end(),
      [](const Node& lhs, const Node& rhs) -> bool
      {
        if (lhs.p != rhs.p)
        {
          return lhs.p < rhs.p;
        }
        if (lhs.isUp != rhs.isUp)
        {
          return lhs.isUp;
        }
        return false;
      });
  map<int, int> ht;
  map<int, int> pMh;
  for (const auto& node : nodes)
  {
    if (node.isUp)
    {
      ++ht[node.h];
    }
    else
    {
      auto it = ht.find(node.h);
      if (it != ht.end())
      {
        if (it->second == 1)
        {
          ht.erase(it);
        }
        else
        {
          --it->second;
        }
      }
    }
    if (ht.empty())
    {
      pMh[node.p] = 0;
    }
    else
    {
      pMh[node.p] = ht.rbegin()->first;
    }
  }
  vector<vector<int>> outlines;
  int start = 0;
  int height = 0;
  for (const auto& ph : pMh)
  {
    int curP = ph.first;
    int curMaxH = ph.second;
    if (height != curMaxH)
    {
      if (height)
      {
        outlines.emplace_back(start, curP, height);
      }
    }
    start = curP;
    height = curMaxH;
  }
  return outlines;
}
