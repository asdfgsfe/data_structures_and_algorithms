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
        stack<TreeNode*> nodes;
        while (root || !nodes.empty())
        {
            if (root)
            {
                nodes.push(root);
                root = root->left;
            }
            else
            {
                root = nodes.top();
                nodes.pop();
                if (pre && pre->val >= root->val)
                {
                    return false;
                }
                pre = root;
                root = root->right;
            }
        }
        return true;
    }
};