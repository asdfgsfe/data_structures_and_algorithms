��������
���� n �����������ŵĶ���������д��һ��������ʹ���ܹ��������п��ܵĲ�����Ч��������ϡ�

���磬���� n = 3�����ɽ��Ϊ��

[
  "((()))",
  "(()())",
  "(())()",
  "()(())",
  "()()()"
]

class Solution {
public:
    vector<string> res;
    int :qa;
    vector<string> generateParenthesis(int n) {
        if(n==0)
            return res;
        end = n;
        dnf(0, 0, "");
        return res;
    }
     void dnf(int r, int l, string has)
     {
         if(l > r || r > end)
         {
             return;
         }
         if(l == end && r == end)
         {
             res.push_back(has);
             return ;
         }
         dnf(r + 1, l, has + '(');
         dnf(r, l + 1, has + ')');
     }
};
