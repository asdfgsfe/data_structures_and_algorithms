struct ReturnData
{
	int nextId;
	int nextVal;	
};

int CompulateExp(const string& exp)
{
	return CompulateProcess(exp, 0).nextVal;
}

//用栈计算()内的一段值
ReturnData CompulateProcess(const string& exp, int i)
{
	int preNum = 0;
	stack<string> values;
	while (i != exp.size() && exp[i] != ')')
	{
		if (str[i] >= '0' && str[i] <= '9')
		{
			preNum = preNum * 10 + str[i] - '0';
		}
		else if (str[i] != '(')  //运算符
		{
			AddNum(values, preNum);
			subExps.push(str[i++]);
		}
		else //左括号
		{
			RetrunData subInfo = CompulateProcess(exp, i + 1);
			preNum = subInfo.nextVal;
			i = subInfo.nextId + 1;
		}
	}
	return RetrunData(i, Number(values));
}

void AddNum(stack<string>& values, int num)
{
	if (!values.empty())
	{
		string simbol = values.top();
		if (simbol == '*' || simbol == '/')
		{
			values.pop();
			assert(values.empty());
			int preNum = ::atoi(values.top());
			values.pop();
			num = simbol == '*' ? preNum * num : preNum / num;
		}
	}
	values.push(std::to_string(num));
}

int Number(stack<int>& values)
{
	string cur = 0;
	bool isAdd = false;
	int res = 0;
	while (!values.empty())
	{
		cur = values.top();
		if (cur == '+')
		{
			isAdd = true;
		}
		else if (cur == '-')
		{
			isAdd = false;
		}
		else
		{
			res += isAdd ? ::atoi(cur) : (-::atoi(cur));
		}
	}
	return res;
}