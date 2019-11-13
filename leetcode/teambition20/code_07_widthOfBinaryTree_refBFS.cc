解题思路：

又是层序遍历，但是本题需要注意的是，需要关心节点的位置了，因为中间的null节点也算宽度。

这就涉及到碰到 null 节点我们怎么处理，如果全都处理，把每一层转变为长度指数增长的字符串，那会有用例超时。

事实上，我们只关心层的宽度，而原本的节点值我们不care，所以其实可以替换掉让它来帮我做点事情。

我们将根节点的值设置为0，在BFS层序遍历的时候，如果一个节点的值为 i 有左右子树，那将它的左节点设置为 2*i，
右节点值设置为 2*i+1，这样我在遍历的过程中，用该层最后一个节点值减去第一个节点的值加 1，就是该层的宽度了。

注意: 答案在32位有符号整数的表示范围内。
代码如下：

class Solution {
public:
    int widthOfBinaryTree(TreeNode* root) {
        if(!root) return 0;
        int res = 0;
        queue<TreeNode*> q;
        root->val = 0;
        q.push(root);
        while(!q.empty()) {
            int s = q.size();
            int minIndex;
            for(int i = 0; i < s; i++) {
                TreeNode* t = q.front();
                q.pop();
                if(i == 0){
                    minIndex = t->val;
                }
                if(i == s-1){
                    res = max(res, t->val - minIndex + 1);
                }
                t->val -= minIndex; //这个地方很重要 如果不减去直接乘 会溢出超时
                if(t->left) {
                    t->left->val = 2 * t->val;
                    q.push(t->left);
                }
                if(t->right) {
                    t->right->val = 2 * t->val + 1;
                    q.push(t->right);
                }
            }
        }
        return res;
    }
};