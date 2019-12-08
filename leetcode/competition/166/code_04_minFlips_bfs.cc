1、1<=m,n<=3 ，数组范围比较小，矩阵的所有状态可以遍历出来。
2、防止重复遍历，需要保存每一步的矩阵。怎么保存矩阵呢？将矩阵转成数字，保存起来。因为需要保存每个矩阵状态下，需要的最少步数，所以使用map保存矩阵状态及其步数。
3、使用队列，依次遍历各状态。
代码如下所示：

作者：miaomiao-2
链接：https://leetcode-cn.com/problems/minimum-number-of-flips-to-convert-binary-matrix-to-zero-matrix/solution/java-bfsmapbao-cun-zhuang-tai-kuai-zhao-by-miaomia/
来源：力扣（LeetCode）
著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。

class Solution {
    public int minFlips(int[][] mat) {
        //存储所有变换过程中的数组，及其形成的步数
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

    //数组转换
    private int op(int[][] mat, int m, int n, int i, int j, int[][] dxy) {
        //转换
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

    //数字还原数组
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

    //枚举所有的情况, 数组转为数字保存
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