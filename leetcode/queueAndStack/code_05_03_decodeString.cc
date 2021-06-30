class Solution {
	struct ReturnData
	{
		int next;
		string code;
		ReturnData(int n, string s)
			: next(n), code(std::move(s)) {}
	};
public:
	string decodeString(string s) {
		if (s.empty())
		{
			return string();
		}
		return DecodeProcess(s, 0).code;
	}

	ReturnData DecodeProcess(const string& s, int i)
	{
		if (i == s.size())
		{
			return ReturnData(i, string());
		}
		int num = 0;
		//这里弄个队列有点麻烦了 直接定义和string就行见v2
		queue<string> codes;
		while (i < s.size() && s[i] != ']')
		{
			if (s[i] >= '0' && s[i] <= '9')
			{
				num = num * 10 + s[i++] - '0';
			}
			else if (s[i] == '[')
			{
				ReturnData data = DecodeProcess(s, i + 1);
				string code;
				for (int j = 0; j < num; ++j)
				{
					code += data.code;
				}
				codes.push(code);
				num = 0;
				i = data.next + 1;
			}
			else
			{
				codes.emplace(1, s[i++]);
			}
			std::cout << "i=" << i << std::endl;
		}
		string end;
		while (!codes.empty())
		{
			end += codes.front();
			codes.pop();
		}
		return ReturnData(i, end);
	}
};
