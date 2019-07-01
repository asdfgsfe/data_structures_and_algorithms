string SerializeByPreOrder(const BTreeNode* pRoot)
{
  if (pRoot == nullptr)
  {
    return string("#!");
  }
  string res = std::to_string(pRoot->val);
  res.append("!");
  res += SerializeByPreOrder(pRoot->pLeft);
  res += SerializeBtPreOrder(pRoot->pRight);
  return res;
}

BTreeNode* ReconstrcutProcess(const vector<string>& values, int& index)
{
  if (index == values.size() || values[index] == "#")
  {
    return nullptr;
  }
  BTreeNode* pRoot = new BTreeNode(::atoi(values[index++]));
  pRoot->pLeft = ReconstructProcess(values, index++);
  pRoot->pRight = ReconstructProcess(values, index++);
  return pRoot;
}

BTreeNode* ReconstructTree(const string& nodes)
{
  if (nodes.empty())
  {
    return nullptr;
  }
  vector<string> values;
  boost::split(values, boost::is_any_of("!"));
  return  ReconstructProcess(values, 0);
}

string SerializeByLevel(const BTreeNode* pRoot)
{
  if (pRoot == nullptr)
  {
    return string("#!");
  }
  queue<const BTreeNode*> nodes;
  nodes.push(pRoot);
  string res;
  while (!nodes.empty())
  {
    pRoot = nodes.front();
    nodes.pop();
    res.append(std::to_string(pRoot->val)).append("!");
    if (pRoot->pLeft)
    {
      nodes.push(pRoot->pLeft);
    }
    else
    {
      res.append("#!");
    }
    if (pRoot->pRight)
    {
      nodes.push(pRoot->pRight);
    }
    else
    {
      res.append("#!");
    }
  }
  return res;
}

BTreeNode* GenNode(const string& val)
{
  if (val.empty() || val == "#!")
  {
    return nullptr;
  }
  return new BTreeNode(atoi(val));
}

BTreeNode* ReconstructByLevel(const string& pLevelOrder)
{
  if (pLevelOrder.empty())
  {
    return nullptr;
  }
  vector<string> values;
  boost::split(values, boost::is_any_of("!"));
  if (values.empty() || values.front() == "#")
  {
    return nullptr;
  }
  int index = 0;
  BTreeNode* pRoot = new BTreeNode(atoi(values[index++]))
  queue<BTreeNode*> nodes;
  nodes.push(pRoot);
  while (!nodes.empty())
  {
    BTreeNode* pNode = nodes.top();
    nodes.pop();
    pNode->pLeft = GenNode(values[index++]);
    pNode->pRight = GenNode(values[index++]);
    if (pNode->pLeft)
    {
      nodes.push(pNode->pLeft);
    }
    if (pNode->pRight)
    {
      nodes.push(pNode->pRight);
    }
  }
  return pRoot;
}
