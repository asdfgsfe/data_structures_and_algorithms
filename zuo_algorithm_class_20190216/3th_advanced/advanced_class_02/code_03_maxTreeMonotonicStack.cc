//单调栈结构 左边比他大右边比他大 单调递减栈
//将计算左边比他大右边比他大合并了 在同一个操作中搞定
BTreeNode* MaxBTree3(const vector<int>& values)
{
	if (values.empty())
	{
		return nullptr;
	}
	vector<BTreeNode*> nodes;
	for (int val : values)
	{
		nodes.emplace_back(new BTreeNode(val));
	}
	unordered_map<BTreeNode*, BTreeNode*> lBig;
	unordered_map<BTreeNode*, BTreeNode*> rBig;
	stack<BTreeNode*> descStack;
	for (int i = 0; i < nodes.size(); ++i)
	{
		while (!descStack.empty() && descStack.top()->val <= nodes[i]->val)
		{
			PopAndRecord(descStack, nodes[i], lBig, rBig);
		}
		descStack.emplace(nodes[i]);
	}
	while (!descStack.empty())
	{
		BTreeNode* cur = descStack.top();
		descStack.pop();
		lBig[cur] = descStack.empty() ? nullptr : descStack.top();
	}
	BTreeNode* root = nullptr;
	for (BTreeNode* cur : nodes)
	{
		assert(lBig.count(cur) && rBig.count(cur));
		BTreeNode* left = lBig[cur];
		BTreeNode* right = rBig[cur];
		if (!left && !right)
		{
			root = cur;
			continue;
		}
		if (!left)
		{
			if (!right->left)
			{
				right->left = cur;
			}
			else
			{
				right->right = cur;
			}
			continue;
		}
		if (!right)
		{
			if (!left->left)
			{
				left->left = cur;
			}
			else
			{
				left->right = cur;
			}
			continue;
		}
		if (left && right)
		{
			BTreeNode* parent = left->val < right->val ? left : right;
			if (parent->left)
			{
				parent->right = cur;
			}
			else
			{
				parent->left = cur;
			}
		}
	}
	return root;
}

void PopAndRecord(stack<BTreeNode*> descStack, 
				  BTreeNode* cur,
				  unordered_map<BTreeNode*, BTreeNode*>& lBig,
				  unordered_map<BTreeNode*, BTreeNode*>* rBig)
{
	BTreeNode* pre = descStack.top();
	rBig[pre] = cur;
	lBig[pre] = descStack.empty() ? nullptr : descStack.top();
}