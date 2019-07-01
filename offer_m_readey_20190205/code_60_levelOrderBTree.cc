void LevelOrderBTree(const BTreeNode* pRoot)
{
  if (pRoot == nullptr)
  {
    return;
  }
  queue<const BTreeNode*> nodes;
  nodes.push(pRoot);
  while (!nodes.empty())
  {
    int size = nodes.size();
    while (size--)
    {
      pRoot = nodes.front();
      nodes.pop();
      std::cout << pRoot->val << " ";
      if (pRoot->pLeft)
      {
        nodes.push(pRoot->pLeft);
      }
      if (pRoot->pRight)
      {
        nodes.push(pRoot->pRight);
      }
    }
    std::cout << std::endl;
  }
}
