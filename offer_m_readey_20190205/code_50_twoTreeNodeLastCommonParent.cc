const TreeNode* LastCommonParent(const TreeNode* pRoot
                                         const TreeNode* pNode1,
                                         const TreeNode* pNode2)
{
  if (!pRoot || !pNode1 || !pNode2)
  {
    return nullptr;
  }
  list<const TreeNode*> path1;
  NodePath(pRoot, pNode1, path1);
  list<const TreeNode*> path2;
  NodePath(pRoot, pNode2, path2);
  return ListLastCommonNode(path1, path2);
}

bool NodePath(const TreeNode* pRoot, const TreeNode* pNode, lsit<const TreeNode*>& path)
{
  if (pRoot == pNode)
  {
    return true;
  }
  path.push_back(pRoot);
  bool found = false;
  for (const auto child = pRoot->children.begin(); !found && child != pRoot->children.end(); ++child)
  {
    found = NodePath(*child, pNode, path);
  }
  if (!found)
  {
    path.pop_back();
  }
  return found;
}

const TreeNode* ListLastCommonNode(const list<const TreeNode*>& path1, const list<TreeNode*>& path2)
{
  const auto pNode1 = path1.begin();
  const auto pNode2 = path2.begin();
  const TreeNode* pLastNode = nullptr;
  while (pNode1 != path1.end() && pNode2 != path2.end())
  {
    if (*pNode1 == *pNode2)
    {
      pLastNode = *pNode1;
    }
    ++pNode1;
    ++pNode2;
  }
  return pLastNode;t
}
