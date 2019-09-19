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
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
		if (!root || !p || !q)
		{
			return nullptr;
		}
		list<TreeNode*> pathP;
		FindPath(root, p, pathP);
		list<TreeNode*> pathQ;
		FindPath(root, q, pathQ);
		return TwoListLastCommonNode(pathP, pathQ);
    }

	TreeNode* TwoListLastCommonNode(list<TreeNode*>& lhs, list<TreeNode*>& rhs)
	{
		if (lhs.empty() || rhs.empty())
		{
			return nullptr;
		}
        list<TreeNode*>::const_iterator lHead= lhs.begin();
        list<TreeNode*>::const_iterator rHead= rhs.begin();
        TreeNode* target = nullptr;
		while (lHead != lhs.end() && rHead != rhs.end() && *lHead == *rHead)
		{
            if (*lHead == *rHead)
            {
                target = *lHead;
            }
			++lHead;
			++rHead;
		}
		return target;
	}

	bool FindPath(TreeNode* root, TreeNode* node, list<TreeNode*>& path)
	{
		if (!root || !node)
        {
            return false;
        }
        path.push_back(root);
        if (root == node)
		{
			return true;
		}
		if (FindPath(root->left, node, path))
		{
			return true;
		}
		if (FindPath(root->right, node, path))
		{
			return true;
		}
		path.pop_back();
		return false;
	}
};

