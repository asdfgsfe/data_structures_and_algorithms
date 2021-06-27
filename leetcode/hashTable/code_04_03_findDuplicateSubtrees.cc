652. Ѱ���ظ�������
����һ�ö����������������ظ�������������ͬһ����ظ���������ֻ��Ҫ������������һ�õĸ���㼴�ɡ�

�������ظ���ָ���Ǿ�����ͬ�Ľṹ�Լ���ͬ�Ľ��ֵ��

ʾ�� 1��

        1
       / \
      2   3
     /   / \
    4   2   4
       /
      4
�����������ظ���������

      2
     /
    4
��

    4

class Solution {
public:
	vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {
		if (!root)
		{
			return {};
		}
		//key�����л������� val�Ǹ��������ֵĴ���
		unordered_map<string, int> subtreeToNodes;
		//���ڼ�¼���
		vector<TreeNode*> nodes;
		SerializeProcess(root, nodes, subtreeToNodes);
		return nodes;
	}

	//������� �ж����������ṹ��ȫ��ͬ ���ǵ����л�һ����ͬ
	string SerializeProcess(TreeNode* root, vector<TreeNode*>& nodes, unordered_map<string, int>& subtreeToNodes)
	{
		if (!root)
		{
			return "#!";
		}
		//�����Ǻ������ ��Ϊ�������ڱ�������������������֮��
		//resΪ�Ե�ǰΪ���ڵ����л�֮�����
		string res = std::to_string(root->val) + "!";
		res += SerializeProcess(root->left, nodes, subtreeToNodes);
		res += SerializeProcess(root->right, nodes, subtreeToNodes);
		auto node = subtreeToNodes.find(res);
		//����val�Ƿ����1ȥ�ظ�
		if (node != subtreeToNodes.end() && node->second == 1)
		{
			nodes.emplace_back(root);
		}
		++subtreeToNodes[res];
		return res;
	}
};
