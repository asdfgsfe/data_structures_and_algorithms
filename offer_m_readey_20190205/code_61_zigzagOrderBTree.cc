
//good
void ZigZagOrderBTree(const BTreeNode* pRoot)
{
  if (pRoot == nullptr)
  {
    return;
  }
  int currLevel = 0;
  int nextLevel = 1;
  stack<const BTreeNode*> levels[2];
  levels[currLevel].push(pRoot);
  while (!levels[currLevel].empty() || !levles[nextLevel].empty())
  {
    pRoot = levels[currLevel].top();
    levels[currLevel].pop();
    if (currLevel == 0)
    {
      if (pRoot->pLeft)
      {
        levles[nextLevel].push(pRoot->pLeft);
      }
      if (pRoot->pRight)
      {
        levles[nextLevel].push(pRoot->pRight);
      }
    }
    else
    {
      if (pRoot->pRight)
      {
        levels[nextLevel].push(pRoot->pRight);
      }
      if (pRoot->pLeft)
      {
        levels[nextLevel].push(pRoot->Left);
      }
    }
    if (levels[curr].empty())
    {
      std:cout << std::endl;
      currLevel = 1 - currLevel;
      nextLevel = 1- nextLevel;
    }
  }
}

//bad
void ZigZagOrderBTree2(const BTreeNode* pRoot)
{
  if (pRoot == nullptr)
  {
    return;
  }
  queue<const BTreeNode*> nodes;
  nodes.push(pRoot);
  int level = 1;
  while (!nodes.empty())
  {
    stack<const BTreeNode*> reverseNodes;
    int size = nodes.size();
    while (size--)
    {
      pRoot = nodes.front();
      nodes.pop();
      if (level & 1 == 0)
      {
        reverseNodes.push(pRoot);
      }
      if (pRoot->pLeft)
      {
        nodes.push(pRoot->pLeft);
      }
      if (pRoot->pRight)
      {
        nodes.push(pRoot->pRight);
      }
    }
    while (!reverseNodes.empty())
    {
      std::cout << reverseNodes.top() << " ";
      reverseNodes.top();
    }
    std::cout << std::endl;
    level = 1 - level;
  }
}
