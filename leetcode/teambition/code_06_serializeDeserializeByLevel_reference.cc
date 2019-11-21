/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:
    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        queue<TreeNode*> nodeQueue;
        string result;
        if(root == NULL)
            return result;
        nodeQueue.push(root);
        while(!nodeQueue.empty())
        {
            TreeNode* temp = nodeQueue.front();
            nodeQueue.pop();
            if(temp)
            {
                result += to_string(temp->val) + " ";
                nodeQueue.push(temp->left);
                nodeQueue.push(temp->right);
            }
            else
            {
                result += "# ";
            }           
        }
        return result;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if(data.empty())
            return NULL;
        istringstream ss(data);
        string temp;
        ss >> temp;
        TreeNode* root = new TreeNode(stoi(temp));
        queue<TreeNode*> nodeQueue;
        nodeQueue.push(root);
        while(ss >> temp)
        {
            TreeNode* node = nodeQueue.front();
            nodeQueue.pop();
            node->left = temp=="#" ? NULL : new TreeNode(stoi(temp));
            ss >> temp;
            node->right = temp=="#" ? NULL : new TreeNode(stoi(temp));
            if(node->left)
                nodeQueue.push(node->left);
            if(node->right)
                nodeQueue.push(node->right);
        }
        return root;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.deserialize(codec.serialize(root));