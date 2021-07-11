二叉树的锯齿形层次遍历
给定一个二叉树，返回其节点值的锯齿形层序遍历。（即先从左往右，再从右往左进行下一层遍历，以此类推，层与层之间交替进行）。

例如：
给定二叉树 [3,9,20,null,null,15,7],

    3
   / \
  9  20
    /  \
   15   7
返回锯齿形层序遍历如下：

[
  [3],
  [20,9],
  [15,7]
]
相关标签
树
广度优先搜索
二叉树


作者：力扣 (LeetCode)
链接：https://leetcode-cn.com/leetbook/read/top-interview-questions-medium/xvle7s/
来源：力扣（LeetCode）
著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。


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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        if (!root) {
            return {};
        }
        vector<vector<int>> order;
        queue<TreeNode*> nodes;
        nodes.emplace(root);
        int flag = 1;
        while (!nodes.empty()) {
            vector<int> level;
            int size = nodes.size();
            while (size -- > 0) {
                root = nodes.front();
                nodes.pop();
                level.emplace_back(root->val);
                if (root->left) {
                    nodes.emplace(root->left);
                }
                if (root->right) {
                    nodes.emplace(root->right);
                }
            }
            if (flag) {
                order.emplace_back(std::move(level));
            } else {
                order.emplace_back(level.rbegin(), level.rend());
            }
            flag = !flag;
        }
        return order;
    }
};
