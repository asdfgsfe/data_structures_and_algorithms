BTreeNode* NextNode(const BTreeNode* pRoot)
{
  if (pRoot == nullptr)
  {
    return nullptr;
  }
  const BTreeNode* pNextNode = nullptr;
  //������Һ��� ����������Ľڵ�
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
    //����� �����ҵ�һ�����������ڵ������ ���ڵ���Ǻ�̽ڵ�
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
  //��������� ���������ҵĽڵ� ����ǰ�̽ڵ�
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
    //����� �������ҵ���һ���ڵ��Ǹ��׽ڵ���Һ��� ���׽ڵ����ǰ�̽ڵ�
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
