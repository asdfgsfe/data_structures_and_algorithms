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
    bool hasPathSum(TreeNode* root, int sum) {
        if (!root)
        {
            return false;
        }
        return SumProcess(root, sum);
    }
    
    bool SumProcess(TreeNode* root, int sum)
    {
        assert(root);
        if (!root->left && !root->right)
        {
            return sum - root->val == 0;
        }
        bool status = false;
        if (root->left)
        {
            status = SumProcess(root->left, sum - root->val);
        }
        if (!status && root->right)
        {
            status = SumProcess(root->right, sum - root->val);
        }
        return status;
    }
};