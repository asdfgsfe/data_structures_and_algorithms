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
    bool isValidBST(TreeNode* root) {
        if (!root)
        {
            return true;
        }
        TreeNode* pre = nullptr;
        return BSTProcess(root, pre);
    }
    
    bool BSTProcess(TreeNode* root, TreeNode*& pre)
    {
        if (!root)
        {
            return true;
        }
        if (!BSTProcess(root->left, pre))
        {
            return false;
        }
        if (pre && pre->val >= root->val)
        {
            return false;
        }
        pre = root;
        return BSTProcess(root->right, pre);
    }
};