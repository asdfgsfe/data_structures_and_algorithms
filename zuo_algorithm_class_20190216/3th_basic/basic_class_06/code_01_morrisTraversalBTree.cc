void Morris(BTreeNode* pRoot)
{
  while (pRoot)
  {
    BTreeNode* pLeft = pRoot->pLeft;
    if (pLeft)
    {
      while (pLeft->pRight && pLeft->pRight != pRoot)
      {
        pLeft = pLeft->pRight;
      }
      if (pLeft->pRight == nullptr)
      {
        pLeft->pRight = pRoot;
        pRoot = pRoot->pLeft;
        continue;
      }
      else
      {
        pLeft->pRight = nullptr;
      }
    }
    pRoot = pRoot->pRight;
  }
}

void MorrisPre(BTreeNode* pRoot)
{
  while (pRoot)
  {
    BTreeNode* pLeft = pRoot->pLeft;
    if (pLeft)
    {
      while (pLeft->pRight && pLeft->pRight != pRoot)
      {
        pLeft = pLeft->pRight;
      }
      if (pLeft->pRight == nullptr)
      {
        pLeft->pRight = pRoot;
        std::cout << pRoot->val << " ";
        pRoot = pRoot->pLeft;
        continue;
      }
      else
      {
        pLeft->pRight = nullptr;
      }
    }
    else
    {
      std::cout << pRoot->val << " ";
    }
    pRoot = pRoot->pRight;
  }
  std::cout << std::endl;
}

void MorrisIn(BTreeNode* pRoot)
{
  while (pRoot)
  {
    BTreeNode* pLeft = pRoot->pLeft;
    if (pLeft)
    {
      while (pLeft->pRight && pLeft->pRight != pRoot)
      {
        pLeft = pLeft->pRight;
      }
      if (pLeft->pRight == nullptr)
      {
        pLeft->pRight = pRoot;
        pRoot = pRoot->pLeft;
        continue;
      }
      else
      {
        pLeft->pRight = nullptr;
      }
    }
    std::cout << pRoot->val << " ";
    pRoot = pRoot->pRight;
  }
}

void MorrisTail(BTreeNode* pRoot)
{
  BTreeNode* pCur = pRoot;
  while (pCur)
  {
    BTreeNode* pLeft = pCur->pLeft;
    if (pLeft)
    {
      while (pLeft->pRight && pLeft->pRight != pCur)
      {
        pLeft = pLeft->pRight;
      }
      if (pLeft->pRight == nullptr)
      {
        pLeft->pRight = pCur;
        pCur = pCur->pLeft;
        continue;
      }
      else
      {
        pLeft->pRight = nullptr;
        PrintEdge(pCur->pLeft);
      }
    }
    pCur = pCur->pRight;
  }
  PrintEdge(pRoot);
  std::cout << std::endl;
}

void PrintEdge(BTreeNode* pRoot)
{
  BTreeNode* pTail = ReverseEdge(pRoot);
  pRoot = pTail;
  while (pRoot)
  {
    std::cout << pRoot->val << " ";
    pRoot = pRoot->pRight;
  }
  ReverseEdge(pTail);
}

BTreeNode* ReverseEdge(BTreeNode* pRoot)
{
  if (pRoot == nullptr || pRoot->pRight)
  {
    return pRoot;
  }
  BTreeNode* pPre = nullptr;
  while (pRoot)
  {
    BTreeNode* pRight = pRoot->pRight;
    pRoot->pRight = pPre;
    pPre = pRoot;
    pRoot = pRight;
  }
  return pPre;
}
