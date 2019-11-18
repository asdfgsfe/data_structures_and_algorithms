//给定两个二叉树，编写一个函数来检验它们是否相同。

//如果两个树在结构上相同，并且节点具有相同的值，则认为它们是相同的。

//示例 1:

//输入:      1         1
//          / \       / \
//         2   3     2   3
//        [1,2,3],   [1,2,3]
//输出: true

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
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if (!p && !q)
        {
            return true;
        }
        if (!p || !q || p->val != q->val)
        {
            return false;
        }
        return isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
    }
};