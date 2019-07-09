bool IsBST(const BTreeNode* root)
{
	if (!root)
	{
		return true;
	}
	const BTreeNode* pre = nullptr;
	return BSTProcess(root, &pre);
}

bool BSTProcess(const BTreeNode* root, BTreeNode* pre)
{
	if (!root)
	{
		return true;
	}
	if (!BSTProcess(root->left, pre))
	{
		return false;
	}
	if (pre && pre->val >= root->val)
	{
		return false;
	}
	pre = root;
	return BSTProcess(root->right, pre);
}