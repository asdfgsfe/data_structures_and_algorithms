string SerializerBTree(const BTreeNode* pRoot)
{
	if (!pRoot)
	{
		return string("#!");
	}
	string res = std::to_string(pRoot->val) + string("!");
	res += SerializerBTree(pRoot->pLeft);
	res += SerializerBTree(pRoot->pRight);
	return res;
}

BTreeNode* DeSerializer(const string& serializer)
{
	if (sertalizer.empty())
	{
		return nullptr;
	}
	vector<string> values;
	boost::split(serializer, values, boost::is_any_of("!"));
	return DeSerializerProcess(values, 0);
}

BTreeNode* DeSerializerProcess(const vector<string>& values, int& i)
{
	if (i == values.size() || values[i] == '#')
	{
		return nullptr;
	}
	BTreeNode* pRoot = new BTreeNode(::atoi(values[i++]));
	pRoot->pLeft = DeSerializerProcess(values, i++);
	pRoot->pRight = DeSerializerProcess(values, i++);
	return pRoot;
}