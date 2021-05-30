class Solution {
public:
    string multiply(string num1, string num2) {
        if (num1.empty() || num2.empty()) {
            return "";
        }
        string m(num1.size() + num2.size() + 1, '0');
        int move = 0;
        for (int i = num1.size() - 1; i >= 0; --i) {
            string sub = MultiChar(num2, num1[i]);
            if (move > 0) {
                sub.append(move, '0');
            }
            ++move;
            m = AddStr(m, sub);
        }
        return m;
    }

    string MultiChar(const string& s, char c) {
        string base(s.size() + 1, '0');
        int move = 0;
        for (int i = s.size() - 1; i >= 0; --i) {
            string sub = std::to_string((c - '0') * (s[i] - '0'));
            if (move > 0) {
                sub.append(move, '0');
            }
            ++move;
            base = AddStr(base, sub);
        }
        return base;
    }

    string AddStr(const string& lhs, const string& rhs) {
        string base(std::max(lhs.size(), rhs.size()) + 1, '0');
        int p = base.size();
        for (int i = lhs.size() - 1; i >= 0; --i) {
            base[--p] = lhs[i];
        }
        p = base.size();
        for (int i = rhs.size() - 1; i >= 0; --i) {
            AddChar(base, --p, rhs[i]);
        }
        p = 0;
        while (p < base.size() && base[p] == '0') {
            ++p;
        }
        if (p == base.size()) {
            return "0";
        }
        return base.substr(p, base.size() - p + 1);
    }

    void AddChar(string& base, int i, char c) {
        while (i >= 0) {
            int n = (base[i] - '0') + (c - '0');
            base[i--] = n % 10 + '0';
            if (n < 10) {
                break;
            }
            c = '1';
        }
    }
};

//43. 字符串相乘
