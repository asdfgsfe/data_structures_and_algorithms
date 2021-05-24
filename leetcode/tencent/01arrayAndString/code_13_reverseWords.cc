��ת�ַ����еĵ��� III
����һ���ַ���������Ҫ��ת�ַ�����ÿ�����ʵ��ַ�˳��ͬʱ�Ա����ո�͵��ʵĳ�ʼ˳��

ʾ�� 1:

����: "Let's take LeetCode contest"
���: "s'teL ekat edoCteeL tsetnoc" 
ע�⣺���ַ����У�ÿ�������ɵ����ո�ָ��������ַ����в������κζ���Ŀո�

class Solution {
public:
    string reverseWords(string s) {
        if (s.empty())
        {
            return string();
        }
        int pre = 0;
        int next = 0;
        while (next < s.size())
        {
            while (next < s.size() && s[next] != ' ')
            {
                ++next;
            }
            ReverseWord(s, pre, next - 1);
            pre = next + 1;
            ++next;
        }
        ReverseWord(s, pre, next - 1);
        return s;
    }
    
    void ReverseWord(string& str, int l, int r)
    {
        while (l < r)
        {
            std::swap(str[l++], str[r--]);
        }
    }
};


//��΢�Ż�һ��
class Solution {
public:
    string reverseWords(string s) {
        if (s.size() < 2) {
            return std::move(s);
        }
        int n = 0;
        int p = 0;
        while (p < s.size()) {
            while (p < s.size() && s[p] != ' ') {
                ++p;
            }
            reverseStr(s, n, p - 1);
            n = ++p;
        }
        return std::move(s);
    }

    void reverseStr(string& s, int l, int r) {
        while (l < r) {
            std::swap(s[l++], s[r--]);
        }
    }
};
