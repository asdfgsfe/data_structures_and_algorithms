1310. 子数组异或查询
有一个正整数数组 arr，现给你一个对应的查询数组 queries，其中 queries[i] = [Li, Ri]。

对于每个查询 i，请你计算从 Li 到 Ri 的 XOR 值（即 arr[Li] xor arr[Li+1] xor ... xor arr[Ri]）作为本次查询的结果。

并返回一个包含给定查询 queries 所有结果的数组。

 

示例 1：

输入：arr = [1,3,4,8], queries = [[0,1],[1,2],[0,3],[3,3]]
输出：[2,7,14,8] 
解释：
数组中元素的二进制表示形式是：
1 = 0001 
3 = 0011 
4 = 0100 
8 = 1000 
查询的 XOR 值为：
[0,1] = 1 xor 3 = 2 
[1,2] = 3 xor 4 = 7 
[0,3] = 1 xor 3 xor 4 xor 8 = 14 
[3,3] = 8
示例 2：

输入：arr = [4,8,2,10], queries = [[2,3],[1,3],[0,0],[0,3]]
输出：[8,0,4,4]
 

提示：

1 <= arr.length <= 3 * 10^4
1 <= arr[i] <= 10^9
1 <= queries.length <= 3 * 10^4
queries[i].length == 2
0 <= queries[i][0] <= queries[i][1] < arr.length
通过次数31,466提交次数44,375

class Solution {
public:
    vector<int> xorQueries(vector<int>& arr, vector<vector<int>>& queries) {
        if (arr.empty() || queries.empty()) {
            return {};
        }
        int allXor = 0;
        vector<int> leftXor(arr.size());
        for (int i = 0; i < arr.size(); ++i) {
            allXor ^= arr[i];
            leftXor[i] = allXor;
        }
        vector<int> rightXor(arr.size());
        rightXor.back() = arr.back();
        for (int i = arr.size() - 2; i >= 0; --i) {
                rightXor[i] = rightXor[i + 1] ^ arr[i];
        }
        vector<int> queriesXor(queries.size());
        for (int i = 0; i < queries.size(); ++i) {
            if (queries[i].size() != 2) {
                return {};
            }
            queriesXor[i] = allXor ^ leftXor[queries[i][0]] ^ rightXor[queries[i][1]] ^ arr[queries[i][0]] ^ arr[queries[i][1]] ;
        }
        return queriesXor;
    }
};
