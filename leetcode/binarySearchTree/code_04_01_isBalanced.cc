平衡二叉树
给定一个二叉树，判断它是否是高度平衡的二叉树。

本题中，一棵高度平衡二叉树定义为：

一个二叉树每个节点 的左右两个子树的高度差的绝对值不超过 1 。

作者：力扣 (LeetCode)
链接：https://leetcode-cn.com/leetbook/read/introduction-to-data-structure-binary-search-tree/xmx4r7/
来源：力扣（LeetCode）
著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。

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
