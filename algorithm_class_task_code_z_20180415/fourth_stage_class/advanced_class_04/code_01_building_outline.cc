#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

using std::vector;
using std::map;

struct Node
{
  bool isUp;
  int position;
  int height;

  Node ()
    : isUp(false), position(0), height(0)
  {}

  Node(bool up, int p, int h)
    : isUp(up), position(p), height(h)
  {}

  Node& operator=(const Node& node)
  {
    if (&node == this)
    {
      return *this;
    }
    isUp = node.isUp;
    position = node.position;
    height = node.height;
    return *this;
  }
};

void PrintNodes(const vector<Node>& nodes)
{
  for (const auto& node : nodes)
  {
    std::cout << node.isUp << " " << node.position << " " << node.height << std::endl;; 
  }
  std::cout << "end" << std::endl;
}

vector<vector<int>> BuildingOutline(const vector<vector<int>>& building)
{
  if (building.empty() || building.size() != 3)
  {
    return vector<vector<int>>();
  }
  vector<Node> nodes(building.size() * 2);
  for (int i = 0; i < building.size(); ++i)
  {
    nodes[i * 2] = Node(true, building[i][0], building[i][2]);
    nodes[i * 2 + 1] = Node(false, building[i][1], building[i][2]);
  }
  std::sort(nodes.begin(), nodes.end(), [&](const Node& lth, const Node& rth) ->bool 
      {
        if (lth.position != rth.position)
        {
          return lth.position < rth.position;
        }
        if (lth.height != rth.height)
        {
          return lth.isUp;
        }
      });
  map<int, int> heightTimes;
  map<int, int> positionMaxHeight;
  for (const auto& node : nodes)
  {
    if (node.isUp)
    {
      if (heightTimes.find(node.height) == heightTimes.end())
      {
        heightTimes[node.height] = 1;
      }
      else
      {
        heightTimes[node.height] += 1;
      }
    }
    else
    {
      if (heightTimes.find(node.height) == heightTimes.end())
      {
        heightTimes[node.height] = 1;
      }
      else
      {
        if (heightTimes[node.height] == 1)
        {
          heightTimes.erase(node.height);
        }
        else
        {
          heightTimes[node.height] -= 1;
        }
      }
    }
    if (heightTimes.empty())
    {
      positionMaxHeight[node.position] = 0;
    }
    else
    {
      positionMaxHeight[node.position] = heightTimes.rbegin()->first;
    }
  }
  vector<vector<int>> res;
  int start = 0;
  int height = 0;
  for (const auto& p : positionMaxHeight)
  {
    int currPosition = p.first;
    int currMaxHeight = p.second;
    if (height != currMaxHeight)
    {
      if (height != 0)
      {
        vector<int> tmp(3);
        tmp[0] = start;
        tmp[1] = currPosition;
        tmp[2] = height;
        res.push_back(tmp);
      }
      start = currPosition;
      height = currMaxHeight;
    }
  }
  return res;
}

void PrintBuilding(const vector<vector<int>>& b)
{
  for (const auto& a : b)
  {
    for (int i : a)
    {
      std::cout << i << " ";
    }
    std::cout << std::endl;
  }
}

int main(void)
{
  vector<vector<int>> building = {{1, 3, 3}, {2, 4, 4}, {5, 6, 1}};
  building = BuildingOutline(building);
  PrintBuilding(building);

  return 0;
}
