void MirrorOfBTree(BTreeNode* pRoot)
{
  if (pRoot == nullptr)
  {
    return;
  }
  if (!pRoot->left && !pRoot->right)
  {
    return;
  }
  BTreeNode* pNode = pRoot->left;
  pRoot->left = pRoot->right;
  pRoot->right = pNode;
  MirrorOfBTree(pRoot->left);
  MirrorOfBTree(pRoot->right);
}
