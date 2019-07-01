BSTreeNode* GeneratorProcess(const vector<int>& nodes, int l, int r)
{
  if (l > r)
  {
    return nullptr;
  }
  int mid = (l + r) / 2;
  BSTreeNode* pRoot = new nodes[mid];
  pRoot->pLeft = GeneratorPrcoess(nodes, l, mid - 1);
  pRoot->pRight = GeneratorProcess(nodes, mid + 1, r);
  return pRoot;
}

BSTreeNode* GeneratorBST(const vector<int>& nodes)
{
  if (nodes.empty())
  {
    return nullptr;
  }
  return GeneratorProcess(nodes, 0, nodes.size() - 1);
}
