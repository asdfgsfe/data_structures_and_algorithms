#include <iostream>
#include <string>
#include <vector>
#include <unordered_set>

using std::string;
using std::vector;
using std::unordered_set;

bool IsRectangleCover(const vector<vector<int>>& rectangles)
{
  if (rectangles.empty() || rectangles[0].empty())
  {
    return false;
  }

  unordered_set<string> point;
  int x1 = 0x7fffffff;
  int x2 = 0x80000000;
  int y1 = 0x7fffffff;
  int y2 = 0x80000000;
  int area = 0;
  for (int r = 0; r < rectangles.size(); ++r)
  {
    x1 = std::min(rectangles[r][0], x1);
    y1 = std::min(rectangles[r][1], y1);
    x2 = std::max(rectangles[r][2], x2);
    y2 = std::max(rectangles[r][3], y2);
    area += (rectangles[r][2] - rectangles[r][0]) * (rectangles[r][3] - rectangles[r][1]);
    string s1 = std::to_string(rectangles[r][0]) + "_" + std::to_string(rectangles[r][1]);
    string s2 = std::to_string(rectangles[r][0]) + "_" + std::to_string(rectangles[r][3]);
    string s3 = std::to_string(rectangles[r][2]) + "_" + std::to_string(rectangles[r][3]);
    string s4 = std::to_string(rectangles[r][2]) + "_" + std::to_string(rectangles[r][1]);
    if (point.find(s1) != point.end())
    {
      point.erase(s1);
    }
    else
    {
      point.insert(s1);
    }
    if (point.find(s2) != point.end())
    {
      point.erase(s2);
    }
    else
    {
      point.insert(s2);
    }
    if (point.find(s3) != point.end())
    {
      point.erase(s3);
    }
    else
    {
      point.insert(s3);
    }
    if (point.find(s4) != point.end())
    {
      point.erase(s4);
    }
    else
    {
      point.insert(s4);
    }
  }

  string s1 = std::to_string(x1) + "_" + std::to_string(y1);
  string s2 = std::to_string(x1) + "_" + std::to_string(y2);
  string s3 = std::to_string(x2) + "_" + std::to_string(y2);
  string s4 = std::to_string(x2) + "_" + std::to_string(y1);
  if (point.find(s1) == point.end()
      || point.find(s2) == point.end()
      || point.find(s3) == point.end()
      || point.find(s4) == point.end()
      || point.size() != 4)
  {
    return false;
  }

  return area == (x2 - x1) * (y2 - y1);
}

int main(void)
{
  vector<vector<int>> rectangles = {
    {1,1,3,3},
    {3,1,4,2},
    {3,2,4,4},
    {1,3,2,4},
    {2,3,3,4},
  };
  std::cout << IsRectangleCover(rectangles) << std::endl;
}

