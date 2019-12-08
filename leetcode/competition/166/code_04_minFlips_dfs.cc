�����������Ϸ ��������

��Ŀ����������ռ�ǳ�С�������ñ����⣬ac

��һ��ÿ��λ�ö��е���߲��� ��������� ��ô��һ��һ����2^n�����
ֻҪ��һ�н��ȷ��������ÿ�еĽ����ȷ����
������֮��checkһ���ܲ���ȫ��ת����¼�������Ŀ����

���ߣ�charon____
���ӣ�https://leetcode-cn.com/problems/minimum-number-of-flips-to-convert-binary-matrix-to-zero-matrix/solution/c-bao-li-sou-suo-by-charon____/
��Դ�����ۣ�LeetCode��
����Ȩ���������С���ҵת������ϵ���߻����Ȩ������ҵת����ע��������

class Solution {
public:
    int minFlips(vector<vector<int>>& mat) {
        vector<int> head(mat[0].size(), 0);
        int res = -1;
        dfs(mat, head, 0, res);
        return res;
    }
    
    void dfs(vector<vector<int>>& mat, vector<int> head, int start, int& res) {
        if (start > head.size()) return;
        int t = count(mat, head);
        if (t > -1) res = res == -1 ? t : min(res, t);
        for (int i = start; i < head.size(); ++i) {
            head[i] = 1 - head[i];
            dfs(mat, head, i + 1, res);
            head[i] = 1 - head[i];
        }
    }
    
    int count(vector<vector<int>> mat, const vector<int>& head) {
        int res = 0;
        for (int i = 0; i < mat.size(); ++i) {
            for (int j = 0; j < mat[0].size(); ++j) {
                if ((i == 0 && head[j] == 1) || (i > 0 && mat[i - 1][j] == 1)) {
                    ++res;
                    mat[i][j] = 1 - mat[i][j];
                    if (i > 0) mat[i - 1][j] = 1 - mat[i - 1][j];
                    if (j > 0) mat[i][j - 1] = 1 - mat[i][j - 1];
                    if (j < head.size() - 1) mat[i][j + 1] = 1 - mat[i][j + 1];
                    if (i < mat.size() - 1) mat[i + 1][j] = 1 - mat[i + 1][j];
                }
            }
        }

        return check(mat) ? res : -1;
    }
    
    bool check(vector<vector<int>>& m) {
        for (auto& v : m) {
            for (auto& n : v) {
                if (n)
                    return false;
            }
        }
        return true;
    }
};