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



//ע��
class Solution {
public:
    void recoverTree(TreeNode* root){
        TreeNode minNode(INT_MIN);
        //������Ϊ�˲���new TreeNode(INT_MIN);
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

        //prevNode��¼��һ���ڵ�
        //����һ���ڵ��ֵ���ڵ�ǰ�ڵ�ֵʱ��˵����һ���ڵ��Ǵ���ģ�Ӱ���˵���
        //��Ϊ������ʱ��ֻ�ܴ��ֵ�ܵ�ǰ�浼�´�������prevNode�Ǵ����
        if(!firstNode && prevNode->val >= root->val)
            firstNode = prevNode;
        //��firstNode��¼��󣬵�ǰ�ڵ�С��ǰ��Ľڵ㣬˵����ǰ�ڵ��Ǵ����
        //��Ϊ������ʱ��ֻ����С��ֵ�ܵ����浼�´�������root�Ǵ����
        if(firstNode && prevNode->val >= root->val)
            secondNode = root;
        //�ı���һ���ڵ㣬����Ѱ��
        prevNode = root;
        recover(root->right);
    }
private:
    TreeNode* prevNode;
    TreeNode* firstNode;
    TreeNode* secondNode;
};