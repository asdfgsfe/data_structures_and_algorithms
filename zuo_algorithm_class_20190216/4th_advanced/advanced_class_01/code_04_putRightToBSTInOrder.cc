//Ҳ���Կ�������Ķ�������· �����ReturnData �����ô�� �ұ���ô��
bool SwapLeftRightNodeToBST(const BTreeNode* root)
{
	if (!root)
	{
		return true;
	}
	int errorNums = 0;
	vector<const BTreeNode*> errorNodes(2, nullptr);
	SwapProcess(root, nullptr, errorNums, errorNodes);
	if (errorNums == 2)
	{
		std::swap(errorNodes[0], errorNodes[1]);
	}
	return errorNums == 0 || errorNums == 2;
}

//����ط�Ҳ������ �ǵݹ���������ȥ�ж�
void SwapProcess(const BTreeNode* root, const BTreeNode*& pre, int& errorNums, vector<const BTreeNode*>& errorNodes)
{
	if (!root || errorNums > 1)
	{
		return;
	}
	SwapProcess(root->left, pre, errorNums, errorNodes) ;
	if (pre && pre >= root->val)
	{
		++errorNums;
		if (!errorNodes[0])
		{
			errorNodes[0] = pre;
		}
		else
		{
			errorNodes[1] = pre;
		}
	}
	pre = root;
	SwapProcess(root->right, pre, errorNums, errorNodes);
}