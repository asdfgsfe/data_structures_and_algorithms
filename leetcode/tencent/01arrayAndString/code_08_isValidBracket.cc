��Ч������
����һ��ֻ���� '('��')'��'{'��'}'��'['��']' ���ַ������ж��ַ����Ƿ���Ч��

��Ч�ַ��������㣺

�����ű�������ͬ���͵������űպϡ�
�����ű�������ȷ��˳��պϡ�
ע����ַ����ɱ���Ϊ����Ч�ַ�����

ʾ�� 1:

����: "()"
���: true
ʾ�� 2:

����: "()[]{}"
���: true
ʾ�� 3:

����: "(]"
���: false
ʾ�� 4:

����: "([)]"
���: false
ʾ�� 5:

����: "{[]}"
���: true

class Solution {
public:
	bool isValid(string s) {
		stack<char> brackets;
		for (char ch : s)
		{
			if (ch == '(' || ch == '[' || ch == '{')
			{
				brackets.push(ch);
			}
			else if (ch == ')' || ch == ']' || ch == '}')
			{
				if (brackets.empty())
				{
					return false;
				}
				char match = brackets.top();
				brackets.pop();
				char best = ch == ')' ? '(' : (ch == ']' ? '[' : '{');
				if (match != best)
				{
					return false;
				}
			}
		}
		return brackets.empty();
	}
};