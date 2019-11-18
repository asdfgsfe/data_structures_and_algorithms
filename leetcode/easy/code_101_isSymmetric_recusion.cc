//给定一个二叉树，返回其节点值自底向上的层次遍历。 
//即按从叶子节点所在层到根节点所在的层，逐层从左向右遍历
//例如：
//给定二叉树[3, 9, 20, null, null, 15, 7],
//
//	 3
//	/ \
//	9   20
//		/ \
//		15   7
//返回其自底向上的层次遍历为：
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