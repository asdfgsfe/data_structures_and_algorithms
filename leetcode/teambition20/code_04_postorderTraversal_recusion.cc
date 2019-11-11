 二叉树的后序遍历
给定一个二叉树，返回它的 后序 遍历。

示例:

输入: [1,null,2,3]  
   1
    \
     2
    /
   3 

输出: [3,2,1]
进阶: 递归算法很简单，你可以通过迭代算法完成吗？

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
    vector<int> postorderTraversal(TreeNode* root) {
        if (!root)
        {
            return {};
        }
        vector<int> values;
        TraversalProcess(root, values);
        return values;
    }
    
    void TraversalProcess(const TreeNode* root, vector<int>& values)
    {
        if (!root)
        {
            return;
        }
        TraversalProcess(root->left, values);
        TraversalProcess(root->right, values);
        values.emplace_back(root->val);
    }
};