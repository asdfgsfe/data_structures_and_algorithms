ɾ������ II

���� 1��̰��
�뷨

��Ը����⣬���ǿ��Ǳ�����Щ��ȥ������յ���������������ɾ����Щ�С�

�����һ�в����ֵ������еģ����Ǿͱ���ɾ������

����������Ҫ�����Ƿ�����һ�С�������������������

������ǲ�������һ�У������𰸵�����Ҫ��֤����

������Ǳ����˵�һ�У���ô���մ𰸵��У���ȥ��һ�У�ֻ��Ҫ�ڵ�һ����ĸ��ͬ���������Ҫ��֤����

�������������⣬����������ӣ�

���������� A = ["axx", "ayy", "baa", "bbb", "bcc"]�������Ǳ�����һ��֮��
�����б�� R = ["xx", "yy", "aa", "bb", "cc"]��������Щ�У�
����Ҫ����������R[0] <= R[1] <= R[2] <= R[3] <= R[4]����
ֻ��Ҫ�ﵽһ��������Ҫ�󣺶��ڵ�һ����ĸ��ͬ���б�֤����R[0] <= R[1] �� R[2] <= R[3] <= R[4]����

���ڣ�����ֻ������Ӧ�õ���һ�У���ʵ����������۶�ÿ�ж����ʡ�
������ǲ���ȡ�õ�һ�У���ɾ�������������Ǿ�ȡ�õ�һ�У���Ϊ������ζ�����ʹҪ����򵥡�

�㷨

����û�������б���������ÿһ�У�������������������򣬾ͱ�����һ�У�����ɾ������

class Solution {
    public int minDeletionSize(String[] A) {
        int N = A.length;
        int W = A[0].length();
        int ans = 0;

        // cur : all rows we have written
        // For example, with A = ["abc","def","ghi"] we might have
        // cur = ["ab", "de", "gh"].
        String[] cur = new String[N];
        for (int j = 0; j < W; ++j) {
            // cur2 : What we potentially can write, including the
            //        newest column col = [A[i][j] for i]
            // Eg. if cur = ["ab","de","gh"] and col = ("c","f","i"),
            // then cur2 = ["abc","def","ghi"].
            String[] cur2 = Arrays.copyOf(cur, N);
            for (int i = 0; i < N; ++i)
                cur2[i] += A[i].charAt(j);

            if (isSorted(cur2))
                cur = cur2;
            else
                ans++;
        }

        return ans;
    }

    public boolean isSorted(String[] A) {
        for (int i = 0; i < A.length - 1; ++i)
            if (A[i].compareTo(A[i+1]) > 0)
                return false;

        return true;
    }
}
���Ӷȷ���

ʱ�临�Ӷȣ�O(NW^2)O(NW 
2
 )������ NN �� A �ĳ��ȣ�WW �� A[i] �ĳ��ȡ�
�ռ临�Ӷȣ�O(NW)O(NW)��
���� 2���Ż�̰��
����

���� 1 �����ø��ٵĿռ��ʱ�䡣

����˼·�Ǽ�¼ÿһ�еġ����Ϣ���ڵ�һ�������У�A = ["axx","ayy","baa","bbb","bcc"]��R Ҳ����ͬ�Ķ��壩��
��һ�н����� R[0] <= R[1] <= R[2] <= R[3] <= R[4] �г��� R[0] <= R[1] �� R[2] <= R[3] <= R[4]��
Ҳ����˵��"a" == column[1] != column[2] == "b" ���и�� R �е�һ��������

�Ӹ��߲�����˵�����ǵ��㷨ֻ��Ҫ�����¼ӽ������Ƿ�֤����ͨ��ά���������Ϣ��ֻ��Ҫ�Ƚ����е��ַ���

class Solution {
    public int minDeletionSize(String[] A) {
        int N = A.length;
        int W = A[0].length();
        // cuts[j] is true : we don't need to check any new A[i][j] <= A[i][j+1]
        boolean[] cuts = new boolean[N-1];

        int ans = 0;
        search: for (int j = 0; j < W; ++j) {
            // Evaluate whether we can keep this column
            for (int i = 0; i < N-1; ++i)
                if (!cuts[i] && A[i].charAt(j) > A[i+1].charAt(j)) {
                    // Can't keep the column - delete and continue
                    ans++;
                    continue search;
                }

            // Update 'cuts' information
            for (int i = 0; i < N-1; ++i)
                if (A[i].charAt(j) < A[i+1].charAt(j))
                    cuts[i] = true;
        }

        return ans;
    }
}

���Ӷȷ���

ʱ�临�Ӷȣ�O(NW)O(NW)������ NN �� A �ĳ��ȣ�WW �� A[i] �ĳ��ȡ�
�ռ临�Ӷȣ�����ռ俪�� O(N)O(N)���� Python �У�zip(*A) ��Ҫ O(NW)O(NW) �Ŀռ䣩��

https://leetcode-cn.com/problems/delete-columns-to-make-sorted-ii/solution/shan-lie-zao-xu-ii-by-leetcode/

955��