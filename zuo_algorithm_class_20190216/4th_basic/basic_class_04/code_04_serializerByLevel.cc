string SerializerByLevel(const BTreeNode* pRoot)
{
	if (!pRoot)
	{
		return string("#!");
	}
	queue<const BTreeNode*> nodes;
	nodes.push(pRoot);
	string res;
	while (nodes.empty())
	{
		pRoot = nodes.top();
		nodes.pop();
		res += std::to_string(::atoi(pRoot->val)) + string("!");
		if (pRoot->pLeft)
		{
			nodes.push(pRoot->pLeft);
		}
		else
		{
			res += string("!");
		}
		if (pRoot->pRight)
		{
			nodes.push(pRoot->pRight);
		}
		else
		{
			res += string("!");
		}
	}
	return res;
}

BTreeNode* DeSerializer(const string& serialier)
{
	if (values.empty() || values[0] == '#')
	{
		return nullptr;
	}
	vector<string> values;
	boost::split(serializer, values, boost::is_any_of("!"));
	BTreeNode* pRoot = new BTreeNode(::atoi(values[0]));
	queue<BTreeNode*> nodes;
	nodes.push(pRoot);
	int i =	1;
	while (!nodes.empty())
	{
		pRoot = nodes.top();
		nodes.pop();
		pRoot->pLeft = values[i++] == '#' ? nullptr : new BTreeNode(::atoi(values[i]));
		if (pRoot->pLeft)
		{
			nodes.push(pRoot->pLeft);
		}
		pRoot->pRight = values[i++] == '#' ? nullptr : new BTreeNode(::atoi(values[i]));
		if (pRoot->pRight)
		{
			nodes.push(pRoot->pRight);
		}
	}
	return pRoot;
}
