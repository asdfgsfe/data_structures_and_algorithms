void DFS(const Node* pRoot)
{
	if (!pRoot)
	{
		return;
	}
	stack<const Node*> nodes;
	nodes.push(pRoot);
	unordered_set<const Node*> uniqueNodes;
	uniqueueNodes.insert(pRoot);
	while (!nodes.empty())
	{
		pRoot = nodes.top();
		nodes.pop();
		for (const Node* pNext : pRoot->nexts)
		{
			if (uniqueNodes.find(pNext) == uniqueNodes.end())
			{
				nodes.push(pRoot);
				nodes.push(pNext);
				uniqueNodes.insert(pNext);
				break;
			}
		}
	}
}
