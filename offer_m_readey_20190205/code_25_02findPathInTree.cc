void FindPathInTree(const BTreeNode* root, int aim)
{
    if (!root)
    {
        return;
    }
    vector<const BTreeNode*> path;
    FindProcess(root, aim, path)
}

void FindProcess(const BTreeNode* root, int aim, vector<const BTreeNode*>& path)
{
    if (!root)
    {
        return;
    }
    aim -= root->val;
    path.emplace_back(root);
    bool isLeaf = !root->left && !root->right;
    if (isLeaf && aim == 0)
    {
        DumpPath(path);
    }
    FindProcess(root->left, aim, path);
    FindProcess(root->right, aim, path);
    path.pop_back();
}
