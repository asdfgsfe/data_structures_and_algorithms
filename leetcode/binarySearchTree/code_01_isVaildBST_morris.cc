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
        bool vaild = true;
        while (root)
        {
            TreeNode* mostRight = root->left;
            if (mostRight)
            {
                while (mostRight->right && mostRight->right != root)
                {
                    mostRight = mostRight->right;
                }
                if (!mostRight->right)
                {
                    mostRight->right = root;
                    root = root->left;
                    continue;
                }
                if (mostRight->right == root)
                {
                    mostRight->right = nullptr;
                }
            }
            if (pre && pre->val >= root->val)
            {
                vaild = false;
            }
            pre = root;
            root = root->right;
        }
        return vaild;
    }
};