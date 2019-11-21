 �������ĺ������
����һ������������������ ���� ������

ʾ��:

����: [1,null,2,3]  
   1
    \
     2
    /
   3 

���: [3,2,1]
����: �ݹ��㷨�ܼ򵥣������ͨ�������㷨�����

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
    vector<int> postorderTraversal(TreeNode* root) {
        if (!root)
        {
            return {};
        }
        vector<int> values;
        TraversalProcess(root, values);
        return values;
    }
    
    void TraversalProcess(const TreeNode* root, vector<int>& values)
    {
        if (!root)
        {
            return;
        }
        TraversalProcess(root->left, values);
        TraversalProcess(root->right, values);
        values.emplace_back(root->val);
    }
};