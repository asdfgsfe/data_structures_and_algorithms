/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
/**
    假设满二叉树表示成数组序列, 根节点所在的位置为1, 则任意位于i节点的左右子节点的index为2*i, 2*i+1
    用一个List保存每层的左端点, 易知二叉树有多少层List的元素就有多少个. 那么可以在dfs的过程中记录每个
    节点的index及其所在的层level, 如果level > List.size()说明当前节点就是新的一层的最左节点, 将其
    加入List中, 否则判断当前节点的index减去List中对应层的最左节点的index的宽度是否大于最大宽度并更新
**/

class Solution {
public:
    unsigned int maxWidth = 0;
    
    int widthOfBinaryTree(TreeNode* root) {
        vector<unsigned int> left;
        dfs(root, 1, 1, left);
        return maxWidth;
    }

private:
    void dfs(TreeNode* root, unsigned int level, unsigned int index, vector<unsigned int>& left)
    {
        if (root == nullptr)
            return;
        
		//这里压入的一定是最左的非空节点 由于前序遍历 一定会保证是每层最左节点
        if (level > left.size())
            left.push_back(index);
        
		//level-1 仅仅为了对齐数组下表从0开始
        maxWidth = max(maxWidth, index - left[level-1] + 1);
        
        dfs(root->left, level+1, index*2, left);
        dfs(root->right, level+1, index*2+1, left);
    }
};