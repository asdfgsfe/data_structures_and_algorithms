��������������
����һ�����������ҳ��������ȡ�

�����������Ϊ���ڵ㵽��ԶҶ�ӽڵ���·���ϵĽڵ�����

˵��: Ҷ�ӽڵ���ָû���ӽڵ�Ľڵ㡣

ʾ����
���������� [3,9,20,null,null,15,7]��

    3
   / \
  9  20
    /  \
   15   7
�������������� 3 ��

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
    int maxDepth(TreeNode* root) {
        if (!root)
        {
            return 0;
        }
        return std::max(maxDepth(root->left), maxDepth(root->right)) + 1;
    }
};