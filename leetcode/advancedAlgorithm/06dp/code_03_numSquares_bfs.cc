class Solution {
public:
    int numSquares(int n) {
        if (n < 0) {
            return 0;
        }
        int cnt = 0;
        queue<int> paths;
        paths.emplace(n);
        unordered_set<int> visited{n};
        while (!paths.empty()) {
            int size = paths.size();
            while (size-- > 0) {
                n = paths.front();
                paths.pop();
                if (n == 0) {
                    return cnt;
                }
                for (int i = sqrt(n); i > 0; --i) {
                    if (!visited.count(n - i * i)) {
                        paths.emplace(n - i * i);
                        visited.emplace(n - i * i);
                    }
                }
            }
            ++cnt;
        }
        return cnt;
    }
};
