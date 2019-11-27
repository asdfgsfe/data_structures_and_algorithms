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
    TreeNode* searchBST(TreeNode* root, int val) {
        if (!root)
        {
            return nullptr;
        }
        stack<TreeNode*> nodes;
        nodes.push(root);
        while (!nodes.empty())
        {
            root = nodes.top();
            nodes.pop();
            if (root->val == val)
            {
                return root;
            }
            if (root->val > val && root->left)
            {
                nodes.push(root->left);
            }
            if (root->val < val && root->right)
            {
                nodes.push(root->right);   
            }
        }
        return nullptr;
    }
};