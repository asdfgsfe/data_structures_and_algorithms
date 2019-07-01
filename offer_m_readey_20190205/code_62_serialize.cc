void Serialize(const BTreeNode* pRoot, string& strTree)
{
  if (pRoot == nullptr)
  {
    strTree.append("#!");
    return;
  }
  strTree.append(std::to_string(pRoot->val)).append("!");
  Serialize(pRoot->pLeft, strTree);
  Serialize(pRoot->pRight, strTree);
}

BTreeNode* Deserialize(const string& strTree)
{
  if (strTree.size() < 2)
  {
    return nullptr;
  }
  vector<string> nodes = boost::split(strTree, '!');
  if (!IsVaild(nodes))
  {
    return nullptr;
  }
  int index = 0;
  return Prcoess(nodes, &index);
}

BTreeNode* Process(const vector<string>& nodes, int* index)
{
  if (*index == nodes.size() || nodes[*index] == "#")
  {
    return nullptr;
  }
  BTreeNode* pRoot = new BTreeNode(::atoi(nodes[*index]));
  ++(*index);
  pRoot->pLeft = Prcoess(nodes, index);
  ++(*index);
  pRoot->pRight = Process(nodes, index);
}
