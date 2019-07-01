void BFS(const Node* pRoot)
{
	if (!pRoot)
	{
		return;
	}
	queue<const Node*> nodes;
	nodes.push(pRoot);
	unordered_set<const Node*> uniqueNodes;
	uniqueNodes.insert(pRoot);
	while (!nodes.empty())
	{
		int size = nodes.size();
		while (size--)
		{
			pRoot = nodes.front();
			nodes.pop();
			for (const Node* pNode : pRoot->nexts)
			{
				if (pNode && uniqueNode.find(pNode) == uniqueNode.end())
				{
					uniqueNode.insert(pNode);
					nodes.push(pNode);
				}
			}
		}
	}
}