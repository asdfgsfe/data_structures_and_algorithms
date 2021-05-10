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
    int maxPathSum(TreeNode* root) {
        if (!root)
        {
            return 0x80000000;
        }
        int maxSum = 0x80000000;
        SumProcess(root, maxSum);
        return maxSum;
    }
    
    int SumProcess(TreeNode* root, int& maxSum)
    {
        if (!root)
        {
            return 0;
        }
        int lMax = std::max(0, SumProcess(root->left, maxSum));
        int rMax = std::max(0, SumProcess(root->right, maxSum));
        maxSum = std::max(maxSum, lMax + rMax + root->val);
        //函数的返回值是：以每个节点为根节点的最大路径和 答案比在其中
        //为根节点，就表示是开始节点或者末尾节点，所以这里要max(lmax, rMax)
        return std::max(lMax, rMax) + root->val;
    }
};

124. 二叉树中的最大路径和
路径 被定义为一条从树中任意节点出发，沿父节点-子节点连接，达到任意节点的序列。同一个节点在一条路径序列中 至多出现一次 。该路径 至少包含一个 节点，且不一定经过根节点。

路径和 是路径中各节点值的总和。

给你一个二叉树的根节点 root ，返回其 最大路径和 。

 

示例 1：


输入：root = [1,2,3]
输出：6
解释：最优路径是 2 -> 1 -> 3 ，路径和为 2 + 1 + 3 = 6
示例 2：


输入：root = [-10,9,20,null,null,15,7]
输出：42
解释：最优路径是 15 -> 20 -> 7 ，路径和为 15 + 20 + 7 = 42
 

提示：

树中节点数目范围是 [1, 3 * 104]
-1000 <= Node.val <= 1000

