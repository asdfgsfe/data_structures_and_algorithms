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
    int maxSum_ = 0x80000000;
    int maxPathSum(TreeNode* root) {
        SumProcess(root);
        return maxSum_;
    }
    
    int SumProcess(TreeNode* root)
    {
        if (!root)
        {
            return 0x80000000;
        }
        int lSum = std::max(0, SumProcess(root->left));
        int rSum = std::max(0, SumProcess(root->right));
        maxSum_ = std::max(maxSum_, lSum + rSum + root->val);
        return std::max(lSum, rSum) + root->val;
    }
};