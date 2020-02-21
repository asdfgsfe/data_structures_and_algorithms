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
  unordered_set<string> poins; //����points��ֻ����߽��
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
  //�����еĵ��������Ϊ���ж� �п������ظ������ �п��ظ��п����� �������պ�
    //������������ڲ��ճ�һ�� �����ظ���һ�� �������жϳ�����
    //�о���Ӧ���ж�points�Ĵ�СΪ4 ��Ϊֻ�б߽��Ż���� �������� �������4˵�������� �ڲ��ճ�һ������
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
