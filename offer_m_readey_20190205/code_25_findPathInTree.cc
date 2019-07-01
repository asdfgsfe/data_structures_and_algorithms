void FindPathInTree(const BTreeNode* pRoot, int sum)
{
  if (!pRoot)
  {
    return;
  }
  vector<const BTreeNode*> path;
  int curSum = 0;
  FindPathProcess(pRoot, curSum, sum, path);
}

void FindPathProcess(const BTreeNode* pNode, int curSum, int sum, vector<const BTreeNode*>& path)
{
  curSum += pNode->val;
  path.push_back(pNode);
  bool isLeaf = pNode->pLeft == nullptr && pNode->pRight == nullptr;
  if (isLeaf && curSum == sum)
  {
    DumpPath(path);
  }
  if (pNode->pLeft)
  {
    FindPathProcess(pNode->pLeft, curSum, sum, path); 
  }
  if (pNode->pRight)
  {
    FindPathProcess(pNode->pRight, curSum, sum, path);
  }
  path.pop_back();
}
