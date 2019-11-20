//Approach 1: Dynamic Programming
//Intuition and Algorithm

//This is a tricky problem that is hard to build an intuition about.

//First, lets try to find the number of columns to keep, instead of the number to delete. 
//At the end, we can subtract to find the desired answer.

//Now, let's say we must keep the first column C. 
//The next column D we keep must have all rows lexicographically sorted (ie. C[i] <= D[i]), 
//and we can say that we have deleted all columns between C and D.

//Now, we can use dynamic programming to solve the problem in this manner. 
//Let dp[k] be the number of columns that are kept in answering the question for input [row[k:] for row in A].
//The above gives a simple recursion for dp[k].


//Complexity Analysis
//Time Complexity: O(N * W^2)O, where NN is the length of A, and WW is the length of each word in A.
//Space Complexity: O(W)O(W). 
//https://leetcode.com/articles/delete-columns-to-make-sorted-iii/

class Solution {
    public int minDeletionSize(String[] A) {
        int W = A[0].length();
        int[] dp = new int[W];
        Arrays.fill(dp, 1);
        for (int i = W-2; i >= 0; --i)
            search: for (int j = i+1; j < W; ++j) {
                for (String row: A)
                    if (row.charAt(i) > row.charAt(j))
                        continue search;

                dp[i] = Math.max(dp[i], 1 + dp[j]);
            }

        int kept = 0;
        for (int x: dp)
            kept = Math.max(kept, x);
        return W - kept;
    }
}