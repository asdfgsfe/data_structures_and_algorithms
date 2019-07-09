int CBTreeNodeNum(const BTreeNode* pRoot)
{
  if (pRoot == nullptr)
  {
    return 0;
  }
  return CompletePrcoess(pRoot, 1, MostLeftLevel(pRoot, 1));
}

//完全二叉树 最左边的层数就是正课数的高 因为左边节点不全右边一定不全
int MostLeftLevel(const BTreeNode* pRoot, int level)
{
  while (pRoot != nullptr)
  {
    ++level;
    pRoot = pRoot->pLeft;
  }
  return level - 1;
}

//height二叉树整体的高 height全局唯一不变
int ComplatePrcoess(const BTreeNode* pRoot, int level, int height)
{
  if (level == height)
  {
    return 1;
  }
  // //左子树是满二叉树 左子树节点数位(2的(height - level)次方) + 右子树节点数
  if (height == MostLeftLevel(pRoot->pRight, level + 1))
  {
    return (1 << (height - level)) + ComplatePrcoess(pRoot->pRight, level + 1, height);
  }
  //左子树不为满二叉树 那么他的上一层的右子树一定是满二叉树 节点个数为2的(height - level - 1) (-1表示上一层)
  //总节点数 = 上一层右子树节点加上 + 当前左子树节点
  return (1 << (height - level - 1)) + complateProcess(pRoot->pLeft, level + 1, height);
}
