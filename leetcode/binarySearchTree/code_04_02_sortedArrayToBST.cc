����������ת��Ϊ����������
����һ���������� nums ������Ԫ���Ѿ��� ���� ���У����㽫��ת��Ϊһ�� �߶�ƽ�� ������������

�߶�ƽ�� ��������һ�����㡸ÿ���ڵ���������������ĸ߶Ȳ�ľ���ֵ������ 1 ���Ķ�������



���ߣ����� (LeetCode)
���ӣ�https://leetcode-cn.com/leetbook/read/introduction-to-data-structure-binary-search-tree/xm5go5/
��Դ�����ۣ�LeetCode��
����Ȩ���������С���ҵת������ϵ���߻����Ȩ������ҵת����ע��������

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
 //�������ɵĲ����������������� ���һ���AVL��
class Solution {
public:
    TreeNode* sortedArrayToBST(vector<int>& nums) {
		if (nums.empty())
		{
			return nullptr;
		}
		return BSTProcess(nums, 0, nums.size() - 1);
    }

	TreeNode* BSTProcess(const vector<int>& nums, int l, int r)
	{
		if (l > r)
		{
			return nullptr;
		}
		int m = (l + r) / 2;
		TreeNode* root = new TreeNode(nums[m]);
		root->left = BSTProcess(nums, l, m - 1);
		root->right = BSTProcess(nums, m + 1, r);
		return root;
	}
};
