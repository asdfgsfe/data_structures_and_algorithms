//��ʵ��һ������
 class Solution {
 public:
	int calculate(string s) {
		if (s.empty())
		{
			return 0;
		}
		deque<string> exp;
		int num = 0;
		for (int i = 0; i < s.size(); ++i)
		{
			if (s[i] == ' ')
			{
				continue;
			}
			if (s[i] >= '0' && s[i] <= '9')
			{
				num = num * 10 + (s[i] - '0');
				continue;
			}
			AddNum(exp, num);
			num = 0;
			exp.emplace_back(1, s[i]);
		}
		//����һ�����2������ �������һ������Ҫ�������
		AddNum(exp, num);
		return GetNum(exp);
	 }

	//�ڼ���Ӽ���ʱ�� ����ͬ������� Ҫ�������ҽ�ϵ����� �������ѡ�����
	int GetNum(deque<string>& exp)
	{
		int num = 0;
		bool add = true;
		while (!exp.empty())
		{
			string cur = exp.front();
			exp.pop_front();
			if (cur == "+")
			{
				add = true;
			}
			else if (cur == "-")
			{
				add = false;
			}
			else
			{
				int rhs = ::atoi(cur.data());
				num += add ? rhs : -rhs;
			}
		}
		return num;
	}

	void AddNum(deque<string>& exp, int num)
	{
		if (!exp.empty())
		{
			string symbol = exp.back();
			if (symbol == "*" || symbol == "/")
			{
				exp.pop_back();
				int lhs = ::atoi(exp.back().data());
				exp.pop_back();
				num = symbol == "*" ? (lhs * num) : (lhs / num);
			}
		}
		exp.emplace_back(std::to_string(num));
	 }
 };