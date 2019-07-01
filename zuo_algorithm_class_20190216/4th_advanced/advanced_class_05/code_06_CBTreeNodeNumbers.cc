int MostLeftLevel(const BTreeNode* pRoot, int level)
{
  while (pRoot)
  {
    ++level;
    pRoot = pRoot->pLeft;
  }
  return level - 1;
}

int ComputeProcess(const BTreeNode* pRoot, int level, int height)
{
  if (level == height)
  {
    return 1;
  }
  //左子树是满二叉树
  if (MostLeftLevel(pRoot->pRight, level + 1) == height)
  {
    //height - level 这个高度的满二叉树
    return (1 << (height - level)) + ComputeProcess(pRoot->pRight, level + 1, height);
  }
  //左子树不是满二叉树 height - level - 1表示减掉最后一层不满的
  return (1 << (height - level - 1)) + ComputeProcess(pRoot->pLeft, level + 1, height);
}

int CBTreeNodeNumers(const BTreeNode* pRoot)
{
  if (pRoot == nullptr)
  {
    return 0;
  }
  return ComputeProcess(pRoot, 1, MostLeftLevel(pRoot, 1));
}
