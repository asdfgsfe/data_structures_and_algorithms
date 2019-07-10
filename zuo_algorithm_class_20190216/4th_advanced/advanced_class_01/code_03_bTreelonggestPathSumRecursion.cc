//Ӧ���ǿ��Ե� ���Ӷȸ�
//����ÿ���ڵ� ȥ�ж��ܲ����ۼӳ������sum�� �ۼӲ��������λ -1�϶�ȡ����
//��ÿ���ڵ���ȡ�����ֵ
int LengthPathSum(const BTreeNode* root, int sum)
{
	if (!root)
	{
		return 0;
	}
	int length = SumProcess(root, sum);
	length = std::max(length, SumProcess(root->left, sum));
	length = std::max(length, SumProcess(root->right, sum));
	return length;
}

int SumProcess(const BTreeNode* node, int sum)
{
	if (sum == 0)
	{
		return 0;
	}
	if (!node)
	{
		return -1;
	}
	sum -= node->val;
	int length = std::max(SumProcess(root->left, sum), SumProcess(root->right, sum));
	return length == -1 ?  -1, length + 1;
}