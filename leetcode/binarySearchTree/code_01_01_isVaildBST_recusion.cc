98. 验证二叉搜索树
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
		//中序遍历 必须记录pre 不然无法衔接
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
