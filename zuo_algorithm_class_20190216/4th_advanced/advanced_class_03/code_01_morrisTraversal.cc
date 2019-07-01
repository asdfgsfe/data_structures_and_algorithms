void MorrisTraversal(BTreeNode* pRoot)
{
  while (pRoot)
  {
    BTreeNode* pCurLeft = pRoot->pLeft;
    if (pCurLeft)
    {
      while (pCurLeft->pRight && pCurLeft->pRight != pRoot)
      {
        pCurLeft = pCurLeft->pRight;
      }
      if (pCurLeft->pRight == nullptr)
      {
        pCurLeft->pRight = pRoot;
        pRoot = pRoot->pLeft;
        continue;
      }
      if (pCurLeft->pRight == pRoot)
      {
        pCurLeft->pRight = nullptr;
      }
    }
    pRoot = pRoot->pRigth;
  }
}

void MorrisTaversalPrev(BTreeNode* pRoot)
{
  while (pRoot)
  {
    BTreeNode* pCurLeft = pRoot->pLeft;
    if (pCurLeft)
    {
      while (pCurLeft->pRight && pCurLeft->pRight != pRoot)
      {
        pCurLeft = pCurLeft->pRight;
      }
      if (pCurLeft->pRight == nullptr)
      {
        pCurLeft->pRight = pRoot;
        std::cout << pRoot->val << " ";  //第一次来到这个节点 打印
        pRoot = pRoot->pLeft;
        continue;
      }
      if (pCurLeft->pRight == pRoot)
      {
        pCurLeft->pRight = nullptr;
      }
    }
    else
    {
      std::cout << pRoot->val << " "; //第一次来到这个节点打印
    }
    pRoot = pRoot->pRight;
  }
  std::cout << std::endl;
}

void MorrisTraversalIn(BTreeNode* pRoot)
{
  while (pRoot)
  {
    BTreeNode* pCurLeft = pRoot->pLeft;
    if (pCurLeft)
    {
      while (pCurLeft->pRight && pCurLeft->pRight != pRoot)
      {
        pCurLeft = pCurLeft->pRight;
      }
      if (pCurLeft->pRight == nullptr)
      {
        pCurLeft->pRight = pRoot;
        pRoot = pRoot->pLeft;
        continue;
      }
      if (pCurLeft->pRight == pRoot)
      {
        pCurLeft->pRight = nullptr;
      }
    }
    //有第一次来到 也有第二次来到 打印 第一次来到说明没有左子树 直接打印根节点 正取
    //第二次来到说明有做节点 此刻pRoot刚好来到他的做节点 打印正确
    std::cout << pRoot->val << " ";
    pRoot = pRoot->pRight;
  }
  std::cout << std::endl;
}

void MorrisTraversalTail(BTreeNode* pRoot)
{
  BTreeNode* pNode = pRoot; //保存下根节点
  while (pRoot)
  {
    BTreeNode* pCurLeft = pRoot->pLeft;
    if (pCurLeft)
    {
      while (pCurLeft->pRight && pCurLeft->pRight != pRoot)
      {
        pCurLeft = pCurLeft->pRight;
      }
      if (pCurLeft->pRight == nullptr)
      {
        pCurLeft->pRight = pRoot;
        pRoot = pRoot->pLeft;
        continue;
      }
      if (pCurLeft->pRight == pRoot)
      {
        pCurLeft->pRight = nullptr;
        PrintEdge(pRoot->pLeft); //必须要先打印右子树 所以必须第二次来到逆序打印  这两行代码的顺序不能调换
      }
    }
    pRoot = pRoot->pRight; //这个位置有第一次来到 第二次来到 所以放到前面打印了 为了简化代码
  }
  PrintEdge(pNode); //打印根节点的那条边
  std::cout << std::endl;
}

void PrintEdge(BTreeNode* pRoot)
{
  BTreeNode* pTail = ReverseEdge(pRoot);
  BTreeNode* pNode = pTail;
  while (pNode)
  {
    std::cout << pNode->val << " ";
    pNode = pNode->pRight;
  }
  ReverseEdge(pTail);
}

BTreeNode* ReverseEdge(BTreeNode* pRoot)
{
  BTreeNode* pPre = nullptr;
  while (pRoot)
  {
    BTreeNode* pNext = pRoot->pRight;
    pRoot->pRight = pPre;
    pPre = pRoot;
    pRoot = pNext;
  }
  return pPre;
}
