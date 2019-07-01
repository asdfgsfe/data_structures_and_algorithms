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
        std::cout << pRoot->val << " ";  //��һ����������ڵ� ��ӡ
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
      std::cout << pRoot->val << " "; //��һ����������ڵ��ӡ
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
    //�е�һ������ Ҳ�еڶ������� ��ӡ ��һ������˵��û�������� ֱ�Ӵ�ӡ���ڵ� ��ȡ
    //�ڶ�������˵�������ڵ� �˿�pRoot�պ������������ڵ� ��ӡ��ȷ
    std::cout << pRoot->val << " ";
    pRoot = pRoot->pRight;
  }
  std::cout << std::endl;
}

void MorrisTraversalTail(BTreeNode* pRoot)
{
  BTreeNode* pNode = pRoot; //�����¸��ڵ�
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
        PrintEdge(pRoot->pLeft); //����Ҫ�ȴ�ӡ������ ���Ա���ڶ������������ӡ  �����д����˳���ܵ���
      }
    }
    pRoot = pRoot->pRight; //���λ���е�һ������ �ڶ������� ���Էŵ�ǰ���ӡ�� Ϊ�˼򻯴���
  }
  PrintEdge(pNode); //��ӡ���ڵ��������
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
