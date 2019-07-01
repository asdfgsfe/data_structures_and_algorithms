struct Staff
{
  int happy;
  list<Staff*> nexts;
  Staff(int h) 
    : happy(h)
  {}
};

struct ReturnData
{
  int buLaiMax;
  int laiMax;
  RetrunData(int bm, int lm)
    : buLaiMax(bm), laiMax(lm)
  {}
};

ReturnData NotifyProcess(const Staff* pRoot)
{
  if (pRoot == nullptr)
  {
    return ReturnData(0, 0);
  }
  vector<RetrunData> subHappyInfos;
  for (const auto staff : pRoot->nexts)
  {
    subHappyInfos.push_back(NotifyProcess(staff));
  }
  int laiMax = pRoot->happy;
  int buLaiMax = 0;
  for (const auto happyInfo : subHappyInfos)
  {
    laiMax += happyInfo.buLaiMax;
    buLaiMax = std::max(happyInfo.laiMax, happyInfo.buLaiMax);
  }
  return ReturnData(buLaiMax, laiMax);
}

int MaxHappyTree(const Staff* pRoot)
{
  if (pRoot == nullptr)
  {
    return 0;
  }
  RetrunData happyInfo = NotifyProcess(pRoot);
  return std::max(happyInfo.buLaiMax, happyInfo.laiMax);
}

//dp[0]bulaiMax dp[1]laiMax
void NotifyProcessDp(const vector<vector<int>>& staffs,
                    int root,
                    vector<vector<int>>& dp,
                    vector<bool> visited)
{
  visited[root] = true;
  dp[root][1] = staffs[root][1];
  for (int staff = 0; staff < staffs.size(); ++staff)
  {
    //staffs[staff][0] == root 找到root的直接下级员工
    if (staffs[staff][0] == root && !visited[staff])
    {
      NotifyProcessDp(staffs, staff, dp, visited);
      dp[root][0] += std::max(dp[staff][0], dp[staff][1]);
      dp[root][1] += dp[staff][0];
    }
  }
}

int MaxHappyMatrxi(const vector<vector<int>>& staffs)
{
  if (staffs.empty() || staffs[0].size() != 2)
  {
    return 0;
  }
  int root = -1;
  for (int i = 0; i < staffs.size(); ++i)
  {
    if (staffs[i][0] == i)
    {
      root = i;
      break;
    }
  }
  vector<vector<int>> dp(staffs.size(), vector<int>(2));
  vector<bool> visited(staffs.size(), false);
  NotifyProcessDp(staffs, root, dp, visited);
  return std::max(dp[root][0], dp[root][1]);
}
