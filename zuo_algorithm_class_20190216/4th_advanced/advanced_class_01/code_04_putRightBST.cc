bool PutRightBST(const BTreeNode* pRoot)
{	
	if (!pRoot)
	{
		return false;
	}
	int errorNum = 0;
	const BTreeNode* pPre = new BTreeNode(0x80000000);
	const BTreeNode* pFirst = nullptr;
	const BTreeNode* pSecond = nullptr;
	PutProcess(pRoot, &pPre, &pFirst, &pSecond, errorNum);
	if (errorNum == 2)
	{
		std::swap(*pFirst, *pSecond);
	}
	return errorNum == 0 || errorNum == 2;
}

void PutProcess(const BTreeNode* pRoot, 
				const BTreeNode** pPre,
				const BTreeNode** pFirst, 
				const BTreeNode** pSecond,
				int& errorNum)
{
	if (!pRoot || errorNum > 2)
	{
		return;
	}
	PutProcess(pRoot->pLeft, pPre, pFirst, pSecond, errorNum);
	assert(pPre && *pPre);
	if (!*pFirst && *pPre->val > pRoot->val)
	{
		*pFirst = *pPre;
		++errorNum;
	}
	if (*pFirst && *pPre->val > pRoot->val)
	{
		*pSecond = *pPre;
		++errorNum;
	}
	*pPre = pRoot;
	PutProcess(pRoot->pRight, pPre, pFirst, pSecond, errorNum);
}



//注释
class Solution {
public:
    void recoverTree(TreeNode* root){
        TreeNode minNode(INT_MIN);
        //仅仅是为了不用new TreeNode(INT_MIN);
        prevNode = &minNode;
        firstNode = secondNode = nullptr;
        recover(root);
        swap(firstNode->val, secondNode->val);
    }
private:
    void recover(TreeNode* root)
    {
        if(!root)   return;
        recover(root->left);

        //prevNode记录上一个节点
        //当上一个节点的值大于当前节点值时，说明上一个节点是错误的，影响了递增
        //因为递增的时候只能大的值跑到前面导致错误，所以prevNode是错误的
        if(!firstNode && prevNode->val >= root->val)
            firstNode = prevNode;
        //当firstNode记录完后，当前节点小于前面的节点，说明当前节点是错误的
        //因为递增的时候只能是小的值跑到后面导致错误，所以root是错误的
        if(firstNode && prevNode->val >= root->val)
            secondNode = root;
        //改变上一个节点，继续寻找
        prevNode = root;
        recover(root->right);
    }
private:
    TreeNode* prevNode;
    TreeNode* firstNode;
    TreeNode* secondNode;
};