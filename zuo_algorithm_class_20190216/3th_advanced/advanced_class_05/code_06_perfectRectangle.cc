bool IsPerfectRectangle(const vector<vector<int>>& rectangles)
{
  if (rectangles.empty() || rectangles[0].size() != 4)
  {
    return false;
  }
  int x1 = 0x7fffffff;
  int y1 =0x7fffffff;
  int x2 = 0x80000000;
  int y2 = 0x80000000;
  unordered_set<string> poins; //最终points中只保存边界点
  int area = 0;
  for (const auto& rectangle : rectangles)
  {
    x1 = std::min(x1, rectangle[0]);
    y1 = std::min(y1, rectangle[1]);
    x2 = std::max(x2, retangle[2]);
    y2 = std::max(y2, retangle[3]);
    area += (rectangle[2] - rectangle[0]) * (rectangle[3] - rectangle[1]);
    vectro<string> tmpPoints;
    tmpPoints[0] = std::to_string(retangle[0]) + "_" + std::to_string(retangle[1]);
    tmpPoints[1] = std::to_string(retangle[0]) + "_" + std::to_string(rectangle[3]);
    tmpPoints[2] = std::to_string(rectangle[2]) + "_" + std::to_string(rectangle[0]);
    tmpPoints[3] = std::to_string(rectangle[2]) + "_" + std::to_string(rectangle[3]);
    for (const auto& point : tmpPoints)
    {
      if (points.find(point) == points.end())
      {
        points.insert(point);
      }
      else
      {
        points.erase(point);
      }
    }
  }
  //把所有的点存起来是为了判断 有快区域重复的情况 有块重复有块少了 加起来刚好
    //但是如果在其内部空出一块 而又重复了一块 这种能判断出来吗
    //感觉还应该判断points的大小为4 因为只有边界点才会出现 奇数数次 如果多余4说明出现了 内部空出一块的情况
  string p1 = std::to_string(x1) + "_" + std::to_string(y1);
  string p2 = std::to_string(x1) + "_" + std::to_string(y2);
  string p3 = std::to_string(x2) + "_" + std::to_string(y1);
  string p4 = std::to_string(x2) + "_" + std::to_string(y2);
  if (ponis.find(s1) == ponis.end()
      || ponis.find(s2) == ponis.end()
      || ponis.find(s3) == ponis.end()
      || ponis.find(s4) == points.end())
  {
    return false;
  }
  return area == (x2 - x1) * (y2 - y2);
}
