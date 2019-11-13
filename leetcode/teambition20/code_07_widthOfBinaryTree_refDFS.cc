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
    ��������������ʾ����������, ���ڵ����ڵ�λ��Ϊ1, ������λ��i�ڵ�������ӽڵ��indexΪ2*i, 2*i+1
    ��һ��List����ÿ�����˵�, ��֪�������ж��ٲ�List��Ԫ�ؾ��ж��ٸ�. ��ô������dfs�Ĺ����м�¼ÿ��
    �ڵ��index�������ڵĲ�level, ���level > List.size()˵����ǰ�ڵ�����µ�һ�������ڵ�, ����
    ����List��, �����жϵ�ǰ�ڵ��index��ȥList�ж�Ӧ�������ڵ��index�Ŀ���Ƿ��������Ȳ�����
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
        
		//����ѹ���һ��������ķǿսڵ� ����ǰ����� һ���ᱣ֤��ÿ������ڵ�
        if (level > left.size())
            left.push_back(index);
        
		//level-1 ����Ϊ�˶��������±��0��ʼ
        maxWidth = max(maxWidth, index - left[level-1] + 1);
        
        dfs(root->left, level+1, index*2, left);
        dfs(root->right, level+1, index*2+1, left);
    }
};