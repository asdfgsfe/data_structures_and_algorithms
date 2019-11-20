class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if (matrix.empty() || matrix[0].empty())
        {
            return false;
        }
        int r = 0;
        int c = matrix[0].size() - 1;
        while (r < matrix.size() && c >= 0)
        {
            if (matrix[r][c] > target)
            {
                --c;
            }
            else if (matrix[r][c] < target)
            {
                ++r;
            }
            else
            {
                return true;
            }
        }
        return false;
    }
};