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
    bool isBalanced(TreeNode* root) {
        int depth = 0;
        return BalanceProcess(root, depth);
    }
    
    bool BalanceProcess(TreeNode* root, int& depth)
    {
        if (!root)
        {
            depth = 0;
            return true;
        }
        int lH;
        int rH;
        if (!BalanceProcess(root->left, lH) || !BalanceProcess(root->right, rH))
        {
            return false;
        }
        if (std::abs(lH - rH) > 1)
        {
            return false;
        }
        depth = std::max(lH, rH) + 1;
        return true;
    }
};