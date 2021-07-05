/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    bool isValidBST(TreeNode* root) {
        if (!root) {
            return true;
        }
        //如果一个节点有左子节点 找到最子节点最右边的节点 
        //如果改节点为空 让其指向当前节点 当前节点来到自己的左子节点 如果只想当前节点 将其设置为null 他来到有孩子
        //如果没有左节点 直接来到有节点
        TreeNode* pre = nullptr;
        bool ret = true;
        while (root) {
            TreeNode* mostRight = root->left;
            if (mostRight) {
                while (mostRight->right && mostRight->right != root) {
                    mostRight = mostRight->right;
                }
                if (!mostRight->right) {
                    mostRight->right = root;
                    root = root->left;
                    continue;
                }
                if (mostRight->right == root) {
                    mostRight->right = nullptr;
                }
            }
            if (pre && pre->val >= root->val) {
                ret = false;
            }
            pre = root;
            root = root->right;
        }
        return ret;
    }
};

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
