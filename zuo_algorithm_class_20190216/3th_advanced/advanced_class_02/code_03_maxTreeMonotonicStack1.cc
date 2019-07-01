void RecordAndPopNode(stack<BTreeNode*>& nodes, unordered_map<BTreeNode*, BTreeNOde*>& lrBig)
{
  BTreeNode* pNode = nodes.top();
  nodes.pop();
  if (nodes.empty())
  {
    lrBig[pNode] = nullptr;
  }
  else
  {
    lrBig[pNode] = nodes.top();
  }  
}

//单调栈结构 左边比他大右边比他大 单调递减栈
BTreeNode* MaxBTree2(const vector<int>& numbers)
{
  if (numbers.empty())
  {
    return nullptr;
  }
  vector<BTreeNode*> nodes(numbers.size());
  for (int i = 0; i < numbers.size(); ++i)
  {
    nodes[i] = new BTreeNode(numbers[i]);
  }
  stack<BTreeNode*> sortNodes;
  unordered_map<BTreeNode*, BTreeNode*> lBig;  
  for (int i = 0; i < nodes.size(); ++i)
  {
    while (!sortNodes.empty() && sortNodes.top()->val <= nodes[i]->val)
    {
      RecordAndPopNode(sortNodes, lBig);
    }
    sortNodes.push(nodes[i])
  }
  while (!sortNodes.empty())
  {
    RecordAndPopNode(sortNodes, lBig);
  }
  unordered_map<BTreeNode*, BTreeNode*> rBig;
  for (int i = nodes.size() - 1; i >= 0; --i)
  {
    while (!sortNodes.empty() && sortNodes.top() < nodes[i]->val)
    {
      RecordAndPopNode(sortNodes, rBig);
    }
    sortNodes.push(nodes[i]);
  }
  while (!sortNodes.empty())
  {
    RecordAndPopNode(sortNodes, rBig);
  }
  BTreeNode* pRoot = nullptr;
  for (BTreeNode* pNode : nodes)
  {
    BTreeNode* pLeft = lBig[pNode];
    BTreeNode* pRight = rBig[pNode];
    if (pLeft == nullptr && pRight == nullptr)
    {
      pRoot = pNode;
    }
    else if (pLeft == nullptr)
    {
      if (pRight->pLeft == nullptr)
      {
        pRight->pLeft = pNode;
      }
      else
      {
        pRight->pRight = pNode;
      }
    }
    else if (pRight == nullptr)
    {
      if (pLeft->pLeft == nullptr)
      {
        pLeft->pLeft = pNode;
      }
      else
      {
        pLeft->pRight = pNode;
      }
    }
    else
    {
      BTreeNode* pPar = pLeft->val < pRight->val ? pLeft : pRight;
      if (pPar->pLeft == nullptr)
      {
        pPar->pLeft = pNode;
      }
      else
      {
        pPar->pRight = pNode;  
      }
    }
  }
  return pRoot;
}