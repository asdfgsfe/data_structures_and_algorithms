struct TreeNode {
    int val;
    vector<TreeNode*> nexts;
};

TreeNode* NTreeCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
    if (!root || !p || !q) {
        return nullptr;
    }
    vector<TreeNode*> path1;
    FindPath(root, p, path1);
    vector<TreeNode*> path2;
    FindPath(root, q, path2);
    TreeNode* ancestor = nullptr;
    for (int i = 0; i < std::min(path1.size(), path2.size()); ++i) {
        if (paht1[i] != path2[i]) {
            break;
        }
        ancestor = path1[i];
    }
    return ancestor;
}

bool FindPath(TreeNode* root, TreeNode* node, vector<TreeNode*>& path) {
    if (!root) {
        return false;
    }
    path.push_back(root);
    if (root == node) {
        return true;
    }
    for (TreeNode* cur : root->nexts) {
        if (FindPath(cut, node, path)) {
            return true;
        }
    }
    path.pop_back();
    return false;
}
