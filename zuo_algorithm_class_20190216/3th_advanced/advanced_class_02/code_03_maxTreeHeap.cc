void HeapInsert(vector<int>& nodes, int index)
{
  while (index > 0)
  {
    int parent = (index - 1) / 2;
    if (nodes[parent]->val >= nodes[index]->val)
    {
      break;
    }
    std::swap(nodes[parent], nodes[index]);
    index = parent;
  }
}

//就是堆的模型 将数组堆转换为树形堆
BTreeNode* MaxTree1(vector<int>& numbers)
{
	if (numbers.empty())
	{
		return nullptr;
	}
	vector<BTreeNode*> nodes(numbers.size());
	for (int i = 0; i < numbers.size(); ++i)
	{
		nodes[i] = new numbers[i];
		HeapInsert(nodes, i);
	}

	for (int i = 0; i < nodes.size(); ++i)
	{
		int left = 2 * i + 1;
		if (left < nodes.size())
		{
			nodes[i]->pLeft = nodes[left];
		}
		if (left + 1 < nodes.size())
		{
			nodes[i]->pRight = nodes[left + 1];
		}
	}
  return nodes[0];
}