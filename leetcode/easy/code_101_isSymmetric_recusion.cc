//����һ����������������ڵ�ֵ�Ե����ϵĲ�α����� 
//������Ҷ�ӽڵ����ڲ㵽���ڵ����ڵĲ㣬���������ұ���
//���磺
//����������[3, 9, 20, null, null, 15, 7],
//
//	 3
//	/ \
//	9   20
//		/ \
//		15   7
//�������Ե����ϵĲ�α���Ϊ��
//
//[
//	[15, 7],
//	[9, 20],
//	[3]
//]

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    bool isSymmetric(TreeNode* root) {
        if (!root)
        {
            return true;
        }
        return SymmetricProcess(root, root);
    }

    bool SymmetricProcess(TreeNode* lhs, TreeNode* rhs)
    {
        if (!lhs && !rhs)
        {
            return true;
        }
        if (!lhs || !rhs)
        {
            return false;
        }
        if (lhs->val != rhs->val)
        {
            return false;
        }
        return SymmetricProcess(lhs->left, rhs->right) && 
               SymmetricProcess(lhs->right, rhs->left);
    }
};