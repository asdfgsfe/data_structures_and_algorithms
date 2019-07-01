class TrieTree
{
	struct Node
	{
		int path;
		int end;
		vector<Node*> nexts;

		Node()
			: path(0), end(0), nexts(vector<Node*>(26, nullptr))
		{}
	};

	void Insert(const string& word)
	{
		Node* pNode = pRoot;
		for (char ch : word)
		{
			if (!pNode->nexts[ch - 'a'])
			{
				pNode->nexts[ch - 'a'] = new Node;
			}
			pNode = pNodes->nexts[ch - 'a'];
			++pNode->path;
		}
		++pNode->end;
	}
	void Delete(const string& word)
	{
		Node* pNode = pRoot;
		for (char ch : word)
		{
			if (--pNode->nexts[ch - 'a']->path == 0)
			{
				delete pNode->nexts[ch - 'a'];
				pNode->nexts[ch - 'a'] = nullptr;
				pNode->nexts[ch - 'a']->end = 0;
				return;
			}
			pNode = pNode->nexts[ch - 'a'];
		}
		--pNode->end;
	}
	int Search(const string& word)
	{
		Node* pNode = pRoot;
		for (char ch : word)
		{
			if (!pNode->nexts[ch - 'a'])
			{
				return 0;
			}
			pNode = pNodes->nexts[ch - 'a'];
		}
		return pNode->end;
	}

	int PrefixNum(const string& word)
	{
		Node* pNode = pRoot;
		for (char ch : word)
		{
			if (!pNode->nexts[ch - 'a'])
			{
				return 0;
			}
			pNode = pNode->nexts[ch - 'a'];
		}
		return pNode->path;
	}

private:
	Node* pRoot_;
};