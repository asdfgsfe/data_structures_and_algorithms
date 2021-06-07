//103. 二叉树的锯齿形层序遍历
给定一个二叉树，返回其节点值的锯齿形层序遍历。（即先从左往右，再从右往左进行下一层遍历，以此类推，层与层之间交替进行）。

例如：
给定二叉树 [3,9,20,null,null,15,7],

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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        if (!root)
        {
            return vector<vector<int>>();
        }
        queue<TreeNode*> nodes;
        nodes.push(root);
        int level = 1;
        vector<vector<int>> levels;
        while (!nodes.empty())
        {
            int size = nodes.size();
            vector<int> levelNodes;
            while (size--)
            {
                root = nodes.front();
                nodes.pop();
                levelNodes.emplace_back(root->val);
                if (root->left)
                {
                    nodes.push(root->left);
                }
                if (root->right)
                {
                    nodes.push(root->right);
                }
            }
            if ((level & 0x1) == 0)
            {
                levels.emplace_back(vector<int>(levelNodes.rbegin(), levelNodes.rend()));
            }
            else
            {
                levels.emplace_back(vector<int>(levelNodes.begin(), levelNodes.end()));
            }
            ++level;
        }
        return levels;
    }
};

//仅仅编码上参考
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
        vector<vector<int>> orders;
        queue<TreeNode*> nodes;
        nodes.emplace(root);
        int flag = 1;
        while (!nodes.empty()) {
            int size = nodes.size();
            vector<int> order(size);
            int p = 0;
            while (size-- > 0) {
                root = nodes.front();
                nodes.pop();
                if (flag == 1) {
                    order[p++] = root->val;
                } else {
                    order[p--] = root->val;
                }
                if (root->left) {
                    nodes.emplace(root->left);
                }
                if (root->right) {
                    nodes.emplace(root->right);
                }
            }
            orders.emplace_back(std::move(order));
            flag ^= 1;
        }
        return orders;
    }
};

