class Solution {
public:
    vector<int> grayCode(int n) {
        if (n < 1) {
            return {0};
        }
        vector<int> code(std::pow(2, n));
        unordered_set<int> visited;
        CodeProcess(code, 0, visited, n);
        return code;
    }

    void CodeProcess(vector<int>& code, int i, unordered_set<int>& visited, int n) {
        if (i == code.size()) {
            return;
        }
        for (int m = 0; m < n; ++m) {
            int cur = i == 0 ? 0 : code[i - 1] ^ (0x01 << m); //0->1 1->0
            if (!visited.count(cur)) {
                visited.emplace(cur);
                code[i] = cur;
                CodeProcess(code, i + 1, visited, n);
                break;
            }
        }
    }
};

//代码好看一点
