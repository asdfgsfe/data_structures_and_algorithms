struct Node
{
};

class UnionFind
{
public:
	void MakeUnionFind(const vector<Node*>& nodes)
	{
		nodeToFather_.clear();
		fatherToSize_.clear();
		for (Node* node : nodes)
		{
			nodeToFather_[node] = node;
			fatherToSize_[node] = 1;
		}
	}

	Node* FindFather(const Node* node)
	{
		const auto pFather = nodeToFather_.find(node);
		if (pFather == nodeToFather_.end())
		{
			return nullptr;
		}
		if (*pFather != node)
		{
			*pFather = FindFather(*pFather);
		}
		nodeToFather_[node] = *pFather; //递归将沿途所有节点打平
		return *pFather;
	}

	bool IsSameSet(const Node* lhs, const Node* rhs)
	{
		return FindFather(lhs) == FindFather(rhs);
	}

	void Union(const Node* lhs, const Node* rhs)
	{
		if (!lhs || !rhs)
		{
			return;
		}
		const Node* lFather = FindFather(lhs);
		const Node* rFather = FindFather(rhs);
		if (lFather && rFather && lFather != rFather)
		{
			auto lSize = fatherToSize_.find(lFather);
			assert(lSzie != fatherToSize_.end());
			auto rSize = fatherToSize_.find(rFather);
			assert(rSize != fatherToSize_.end());
			if (*lSize > * rSize)
			{
				nodeToFather_[rFather] = lFather;
				fatherToSize_[lFather] = *lSize + *rSize;
			}
			else
			{
				nodeToFather_[lFather] = rFather;
				fatherToSize_[rFather] = *lSize + *rSize;
			}
		}
	}
private:
	unordered_map<Node*, Node*> nodeToFather_;
	unordered_map<Node*, int> fatherToSize_;
};