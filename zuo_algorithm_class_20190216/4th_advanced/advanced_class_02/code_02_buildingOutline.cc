struct Node
{
  int postion;
  int height;
  bool isup;
  Node(int p, int h, bool up)
    : postion(p), height(h), isUp(up)
  {}
  Node() {}
};

vector<vector<int>> BuildingOutline(const vector<vector<int>>& matrix)
{
  if (matrix.empty() || matrix[0].size() != 3)
  {
    return;
  }
  vector<Node> nodes(matrix.size() * 2);
  for (int i = 0; i < nodes.size(); ++i)
  {
    nodes[2 * i] = Node(matrix[i][0], matrix[i][2], true);
    nodes[2 * i + 1] = Node(matrix[i][1], matrix[i][2], false);
  }
  std::sort(nodes.begin(), nodes.end(), 
      [](const Node& lhs, const Node& rhs) ->bool
      {
	return lhs.position != rhs.position ? lhs.position < rhs.position : lhs.isUp;
      });
  map<int, int> heightTimes;
  map<int, int> positionMaxH;
  for (const Node& node : nodes)
  {
    if (node.isUp)
    {
      ++heightTimes[node.height];
    }
    else
    {
      auto it = heightTimes.find(node.height);
      assert(it != heightTimes.end());
      if (--it->second == 0)
      {
        heightTimes.erase(it);
      }
    }
    positionMaxH[node.position] = heightTimes.empty() ? 0 : heightTimes.rbegin()->first;
  }
  vectro<vector<int>> outlines;
  int start = 0;
  int height = 0;
  for (const auto& pm : positionMaxH)
  {
    int curPos = pm.first;
    int curMaxH = pm.second;
    if (curMaxH != height)
    {
      if (height != 0)
      {
        outlines.emplace_back(start, curPos, height);
      }
      start = curPos;
      height = curMaxH;
    }
  }
  return outlines;
}

