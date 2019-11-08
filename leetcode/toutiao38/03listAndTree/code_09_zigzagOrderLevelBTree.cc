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
