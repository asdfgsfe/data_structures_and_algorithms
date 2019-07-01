struct TreeNode
{
  int happy;
  vector<TreeNode*> children;
};

struct ReturnData
{
  int bulaiMax;
  int laiMax;
};

ReturnData NotifyProcess(const TreeNode* pRoot)
{
  if (pRoot == nullptr)
  {
    return ReturnData(0, 0);
  }
  int laiMax = pRoot->happy;
  int bulaiMax = 0;
  for (const TreeNode* child : pRoot->children)
  {
    ReturnData happy = NotifyProcess(child);
    laiMax = happy.bulaiMax;
    bulaiMax = std::max(happy.bulaiMax, happy.laiMax);
  }
  return ReturnData(bulaiMax, laiMax);
}

int MaxHappy(const TreeNode* pRoot)
{
  if (pRoot == nullptr)
  {
    return 0;
  }
  ReturnData happy = NotifyProcess(pRoot);
  return std::max(happy.bulaiMax, laiMax);
}
