����˼·��

���ǲ�����������Ǳ�����Ҫע����ǣ���Ҫ���Ľڵ��λ���ˣ���Ϊ�м��null�ڵ�Ҳ���ȡ�

����漰������ null �ڵ�������ô�������ȫ��������ÿһ��ת��Ϊ����ָ���������ַ������ǻ���������ʱ��

��ʵ�ϣ�����ֻ���Ĳ�Ŀ�ȣ���ԭ���Ľڵ�ֵ���ǲ�care��������ʵ�����滻�������������������顣

���ǽ����ڵ��ֵ����Ϊ0����BFS���������ʱ�����һ���ڵ��ֵΪ i �������������ǽ�������ڵ�����Ϊ 2*i��
�ҽڵ�ֵ����Ϊ 2*i+1���������ڱ����Ĺ����У��øò����һ���ڵ�ֵ��ȥ��һ���ڵ��ֵ�� 1�����Ǹò�Ŀ���ˡ�

ע��: ����32λ�з��������ı�ʾ��Χ�ڡ�
�������£�

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
                t->val -= minIndex; //����ط�����Ҫ �������ȥֱ�ӳ� �������ʱ
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