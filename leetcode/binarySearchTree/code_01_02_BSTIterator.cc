/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class BSTIterator {
public:
    BSTIterator(TreeNode* root) {
        MoveLeftEdge(root);
    }
    
    /** @return the next smallest number */
    int next() {
        assert(!nodes.empty());
        TreeNode* root = nodes.top();
        nodes.pop();
        MoveLeftEdge(root->right);
        assert(root);
        return root->val;
    }
    
    /** @return whether we have a next smallest number */
    bool hasNext() {
        return !nodes.empty();
    }
    
private:
    void MoveLeftEdge(TreeNode* root)
    {
        while (root)
        {
            nodes.push(root);
            root = root->left;
        }
    }
    stack<TreeNode*> nodes;
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */