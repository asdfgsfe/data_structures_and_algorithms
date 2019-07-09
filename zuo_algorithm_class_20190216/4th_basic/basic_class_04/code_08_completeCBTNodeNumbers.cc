int CBTreeNodeNum(const BTreeNode* pRoot)
{
  if (pRoot == nullptr)
  {
    return 0;
  }
  return CompletePrcoess(pRoot, 1, MostLeftLevel(pRoot, 1));
}

//��ȫ������ ����ߵĲ��������������ĸ� ��Ϊ��߽ڵ㲻ȫ�ұ�һ����ȫ
int MostLeftLevel(const BTreeNode* pRoot, int level)
{
  while (pRoot != nullptr)
  {
    ++level;
    pRoot = pRoot->pLeft;
  }
  return level - 1;
}

//height����������ĸ� heightȫ��Ψһ����
int ComplatePrcoess(const BTreeNode* pRoot, int level, int height)
{
  if (level == height)
  {
    return 1;
  }
  // //���������������� �������ڵ���λ(2��(height - level)�η�) + �������ڵ���
  if (height == MostLeftLevel(pRoot->pRight, level + 1))
  {
    return (1 << (height - level)) + ComplatePrcoess(pRoot->pRight, level + 1, height);
  }
  //��������Ϊ�������� ��ô������һ���������һ������������ �ڵ����Ϊ2��(height - level - 1) (-1��ʾ��һ��)
  //�ܽڵ��� = ��һ���������ڵ���� + ��ǰ�������ڵ�
  return (1 << (height - level - 1)) + complateProcess(pRoot->pLeft, level + 1, height);
}
