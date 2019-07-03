//o(n*n*n)
int MaxRectangle(const vector<vector<int>>& rectangles)
{
  if (rectangles.empty() || rectangles[0].empty())
  {
    return 0;
  }
  vector<int> height(rectangles.size(), 0);
  int maxArea = 0;
  //以每行结尾的情况下做大面 选出全局最大
  for (int i = 0; i < rectangles.size(); ++i)
  {
    for (int j = 0; j < rectangles[0].size(); ++j)
    {
      height[j] = retangles[i][j] == 0 ? 0 : height[j] + 1;
    }
    maxArea = std::max(maxArea, MaxRecFromBottom(height));
  }
}

//注意边界 数组遍历完了 栈可能还没有弹空 单调递增栈
int MaxRecFromBottom(const vector<int>& height)
{
  if (height.empty())
  {
    return 0;
  }
  stack<int> lrMin;
  int maxArea = 0;
  for (int i = 0; i < height.size(); ++i)
  {
	//左右边离我最近的比我小的 其实就是以每个位置向左右扩张 算出面积
    while (!lrMin.empty() && height[i] <= height[lrMin.top()])
    {
      int curId = lrMin.top();
      lrMin.pop();
      int lId = lrMin.empty() ? -1 : lrMin.top();
      int area = (i - lId - 1) * height[curId]; //fix (lId - curId)
      maxArea = std::max(area, maxArea);
    }
    lrMin.push(i);
  }
  while (!lrMin.empty())
  {
    int curId = lrMin.top();
    lrMin.pop();
    int lId = lrMin.empty() ? -1 : lrMin.top();
    int area = (height.size() - lId - 1) * height[curId];
    maxArea = std::max(maxArea, area);
  }
  return maxArea;
}
