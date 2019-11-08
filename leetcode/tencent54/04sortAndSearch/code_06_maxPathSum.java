class Solution {
    
    private int ret = Integer.MIN_VALUE;
    
    public int maxPathSum(TreeNode root) {
        /**
        ��������һ���ڵ�, �������·�������ýڵ�, ��ôֻ�������������:
        1. �����������������ɵĺ�·��ֵ�ϴ���Ǹ����ϸýڵ��ֵ���򸸽ڵ���ݹ������·��
        2. ���������������·����, ���ϸýڵ��ֵ���������յ����·��
        **/
        getMax(root);
        return ret;
    }
    
    private int getMax(TreeNode r) {
        if(r == null) return 0;
        int left = Math.max(0, getMax(r.left)); // �������·����Ϊ����Ӧ����0��ʾ���·������������
        int right = Math.max(0, getMax(r.right));
        ret = Math.max(ret, r.val + left + right); // �ж��ڸýڵ��������������·�����Ƿ���ڵ�ǰ���·����
        return Math.max(left, right) + r.val;
    }
}
