//这里不应该以值是否相等作为判断的依据 而应该直接判断节点的指针
bool IsSubstructInBTree(const BTreeNode* pRoot1, const BTreeNode* pRoot2)
{
  if (pRoot2 == nullptr)
  {
    return true;
  }
  if (pRoot1 == nullptr)
  {
    return false;
  }
  bool result = false;
  if (pRoot1->val == pRoot2->val)
  {
    result = DoesTree1HaveTree2(pRoot1, pRoot2);
  }
  if (!result)
  {
    result = DoesTree1HaveTree2(pRoot1->left, pRoot2);
  }
  if (!result)
  {
    result = DoesTree1HaveTree2(pRoot1->right, pRoot2);
  }
  return result;
}

bool DoesTree1HaveTree2(const BTreeNode* pNode1, const BTreeNode* pNode2)
{
  if (pNode2 == nullptr)
  {
    return false;
  }
  if (pNode1 == nullptr || pNode1->val != pNode2->val)
  {
    return false;
  }
  return DoesTree1HaveTree2(pNode1->left, pNode2->left) 
         && DoesTree1HaveTree2(pNode1->right, pNode2->right);
}
