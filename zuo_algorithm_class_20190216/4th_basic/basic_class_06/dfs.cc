void DFS(const Node* pRoot) //应该是入度为0的节点
{
	if (!pRoot)
	{
		return;
	}
	stack<const Node*> nodes;
	nodes.push(pRoot);
	unordered_set<const Node*> visited;
	visited.insert(pRoot);
	while (!nodes.empty())
	{
		pRoot = nodes.top();
		nodes.pop();
		for (const Node* pNext : pRoot->nexts)
		{
			if (visited.find(pNext) == visited.end())
			{
				nodes.push(pRoot);
				nodes.push(pNext);
				visited.insert(pNext);
				break; //很关键
			}
		}
	}
}
