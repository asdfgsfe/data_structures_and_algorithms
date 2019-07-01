BTreeNode* NextNode(const BTreeNode* pRoot)
{
  if (pRoot == nullptr)
  {
    return nullptr;
  }
  const BTreeNode* pNextNode = nullptr;
  //如果有右孩子 右子树最左的节点
  if (pRoot->pRight)
  {
    const BTreeNode* pNode = pRoot->pRight;
    while (pNode->pLeft)
    {
      pNode = pNode->pLeft;
    }
    pNextNode = pNode;
  }
  else
  {
    //如果无 向上找到一个点是他父节点的左孩子 父节点就是后继节点
    const BTreeNode* pParentNode = pRoot->pParent;
    while (pParentNode)
    {
      if (pRoot == pParentNode->pLeft)
      {
        pNextNode = pParentNode;
        break;
      }
      pRoot = pParentNode;
      pParentNode = pParentNode->pParent;
    }
  }
  return pNextNode;
}

BTreeNode* PrevNode(const BTreeNode* pRoot)
{
  if (pRoot == nullptr)
  {
    return nullptr;
  }
  const pRreNode = nullptr;
  //如果有左孩子 左子树最右的节点 就是前继节点
  if (pRoot->pLeft)
  {
    const BTreeNode* pNode = pRoot->pLeft;
    while (pNode->pRight)
    {
      pNode = pNode->pRight;
    }
    pPreNode = pNode;
  }
  else
  {
    //如果无 向上找找到第一个节点是父亲节点的右孩子 父亲节点就是前继节点
    const BTreeNode* pParentNode = pRoot->pParent;
    while (pParentNode)
    {
      if (pParentNode->pRight == pRoot)
      {
        pPreNode = pParentNode;
        break;
      }
      pRoot = pParentNode;
      pParetnNode = pParentNode->pParent;
    }
  }
  return pPreNode;
}
