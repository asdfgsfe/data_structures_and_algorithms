删列造序 II

方法 1：贪心
想法

针对该问题，我们考虑保留哪些列去获得最终的有序结果，而不是删除哪些列。

如果第一列不是字典序排列的，我们就必须删除它。

否则，我们需要讨论是否保留第一列。会出现以下两种情况：

如果我们不保留第一列，则最后答案的行需要保证有序；

如果我们保留了第一列，那么最终答案的行（除去第一列）只需要在第一个字母相同的情况下需要保证有序。

这个描述很难理解，看下面的例子：

假设我们有 A = ["axx", "ayy", "baa", "bbb", "bcc"]，当我们保留第一列之后，
最终行变成 R = ["xx", "yy", "aa", "bb", "cc"]，对于这些行，
并不要求所有有序（R[0] <= R[1] <= R[2] <= R[3] <= R[4]），
只需要达到一个较弱的要求：对于第一个字母相同的行保证有序（R[0] <= R[1] 和 R[2] <= R[3] <= R[4]）。

现在，我们只将结论应用到第一列，但实际上这个结论对每列都合适。
如果我们不能取用第一列，就删除它。否则，我们就取用第一列，因为无论如何都可以使要求更简单。

算法

首先没有任意列保留，对于每一列：如果保留后结果保持有序，就保留这一列；否则删除它。

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
复杂度分析

时间复杂度：O(NW^2)O(NW 
2
 )，其中 NN 是 A 的长度，WW 是 A[i] 的长度。
空间复杂度：O(NW)O(NW)。
方法 2：优化贪心
解释

方法 1 可以用更少的空间和时间。

核心思路是记录每一列的”割“信息。在第一个例子中，A = ["axx","ayy","baa","bbb","bcc"]（R 也是相同的定义），
第一列将条件 R[0] <= R[1] <= R[2] <= R[3] <= R[4] 切成了 R[0] <= R[1] 和 R[2] <= R[3] <= R[4]。
也就是说，"a" == column[1] != column[2] == "b" ”切割“了 R 中的一个条件。

从更高层面上说，我们的算法只需要考虑新加进的列是否保证有序。通过维护”割“的信息，只需要比较新列的字符。

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

复杂度分析

时间复杂度：O(NW)O(NW)，其中 NN 是 A 的长度，WW 是 A[i] 的长度。
空间复杂度：额外空间开销 O(N)O(N)（在 Python 中，zip(*A) 需要 O(NW)O(NW) 的空间）。

https://leetcode-cn.com/problems/delete-columns-to-make-sorted-ii/solution/shan-lie-zao-xu-ii-by-leetcode/

955题