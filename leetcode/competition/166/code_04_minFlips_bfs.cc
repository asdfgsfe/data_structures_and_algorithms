1��1<=m,n<=3 �����鷶Χ�Ƚ�С�����������״̬���Ա���������
2����ֹ�ظ���������Ҫ����ÿһ���ľ�����ô��������أ�������ת�����֣�������������Ϊ��Ҫ����ÿ������״̬�£���Ҫ�����ٲ���������ʹ��map�������״̬���䲽����
3��ʹ�ö��У����α�����״̬��
����������ʾ��

���ߣ�miaomiao-2
���ӣ�https://leetcode-cn.com/problems/minimum-number-of-flips-to-convert-binary-matrix-to-zero-matrix/solution/java-bfsmapbao-cun-zhuang-tai-kuai-zhao-by-miaomia/
��Դ�����ۣ�LeetCode��
����Ȩ���������С���ҵת������ϵ���߻����Ȩ������ҵת����ע��������

class Solution {
    public int minFlips(int[][] mat) {
        //�洢���б任�����е����飬�����γɵĲ���
        Map<Integer, Integer> map = new HashMap<>();
        int val = snap(mat);
        if(val == 0) {
            return 0;
        }
        map.put(val, 0);
        int m = mat.length;
        int n = mat[0].length;
        int[][] dxy = new int[][]{{-1,0}, {1,0}, {0,1}, {0, -1}};
        Queue<Integer> queue = new LinkedList<>();
        queue.add(val);
        while(!queue.isEmpty()) {
            int v = queue.remove();
            int cnt = map.get(v) + 1;
            for(int i=0; i<m; i++) {
                for(int j=0; j<n; j++) {
                    int[][] temp = spread(m, n, v);
                    int op = op(temp, m,n, i, j, dxy);
                    if(op == 0) {
                        return cnt;
                    }
                    if(map.get(op) == null) {
                        map.put(op, cnt);
                        queue.add(op);
                    }
                }
            }
        }
        return -1;
    }

    //����ת��
    private int op(int[][] mat, int m, int n, int i, int j, int[][] dxy) {
        //ת��
        mat[i][j] = 1-mat[i][j];
        for(int k=0; k<dxy.length; k++) {
            int x = i+dxy[k][0];
            int y = j+dxy[k][1];
            if(x>=0 && x<m && y>=0 && y<n) {
                mat[x][y] = 1-mat[x][y];
            }
        }
        return snap(mat);
    }

    //���ֻ�ԭ����
    private int[][] spread(int m, int n, int val) {
        int[][] mat = new int[m][n];
        String s = String.valueOf(val);
        int index = s.length()-1;
        for(int i=m-1; i>=0; i--) {
            for(int j=n-1; j>=0; j--) {
                if(index < 0) {
                    continue;
                }
                mat[i][j] = s.charAt(index) == '0' ? 0 : 1;
                index--;
            }
        }
        return mat;
    }

    //ö�����е����, ����תΪ���ֱ���
    private int snap(int[][] mat) {
        StringBuilder sb = new StringBuilder();
        for(int i=0; i<mat.length; i++) {
            for(int j=0; j<mat[0].length; j++) {
                if(mat[i][j] == 0 && sb.toString().equals("")) {
                    continue;
                }
                sb.append(mat[i][j]);
            }
        }
        String ss = sb.toString();
        return ss.equals("") ? 0 : Integer.valueOf(ss);
    }
}