#include <iostream>
#include <string>
#include <algorithm>

using std::string;    

void AddChar(string& sum, int i, char c);
string ZeroK(int k);
string Add(const string& lhs, const string& rhs);
string MultiplyChar(const string& lhs, int idx, char c);


string Multiply(const string& lhs, const string& rhs)
{
	if (lhs.empty() || rhs.empty())
	{
		return string();
	}
	string multi(lhs.size() + rhs.size() + 1, '0');
	int i = lhs.size() - 1;
	int j = rhs.size() - 1;
	for (int j = rhs.size() - 1; j >= 0; --j)
	{
		//拆分为字符串和单个字符相乘
        string subM = MultiplyChar(lhs, lhs.size() - 1, rhs[j]);
        //左移
		subM += ZeroK(rhs.size() - 1 - j);
        //把所有的和加起来
		multi = Add(multi, subM);
	}
	return multi;
}

//看作是把单个字符的乘起来的值加起来
string MultiplyChar(const string& lhs, int idx, char c)
{
	string mul(lhs.size() + 1, '0');
	for (int k = idx; k >= 0; --k)
	{
		int cur = (lhs[k] - '0') * (c - '0');
		string curM = std::to_string(cur) + ZeroK(idx - k);
		mul = Add(mul, std::move(curM));
	}
	return mul;
}

string ZeroK(int k)
{
	string res;
	for (int i = 0; i < k; ++i)
	{
		res.append(1, '0');
	}
	return res;
}

string Add(const string& lhs, const string& rhs)
    {
  		std::cout << "lhs=" << lhs << " rhs=" << rhs << std::endl;  
	    string sum(std::max(lhs.size(), rhs.size()) + 1, '0');
			int sTail = sum.size() - 1;
			int lTail = lhs.size() - 1;
			while (lTail >= 0)
			{
				sum[sTail--] = lhs[lTail--];
			}
      sTail = sum.size() - 1;
      lTail = rhs.size() - 1;
			while (sTail >= 0 && lTail >= 0)
      {
    		AddChar(sum, sTail--, rhs[lTail--]);
			}
        return sum.substr(sum.find_first_not_of('0'));
    }

void AddChar(string& sum, int i, char c)
{
		for (int move = i; move >= 0; --move)
		{
			int cur = sum[move] - '0' + c - '0';
			sum[move] = cur % 10 + '0';
			//std::cout << "cur=" << cur << " sm=" << sum[move] << " move=" << move << " c=" << c << " sum=" << sum << std::endl;
			if (cur < 10)
			{
				break;
			}
			c = '1';
		}
}


int main(void)
{
	string n1 = "5678";
	string n2 = "2345";
	std::cout << n1 << std::endl;
	std::cout << n2 << std::endl;
	std::cout << Add(n1, n2) << std::endl;
	std::cout << (atoi(n1.c_str()) + atoi(n2.c_str())) << std::endl;
	
	string n3 = "5678";
	string n4 = "2345";
	std::cout << n1 << std::endl;
	std::cout << n2 << std::endl;
	std::cout << Multiply(n1, n2) << std::endl;
	std::cout << (atoi(n1.c_str()) * atoi(n2.c_str())) << std::endl;

	//string n3 = "0999";
	//AddChar(n3, n3.size() -  1, '8');
	//std::cout << n3 << std::endl;
	
	//string n3 = "0123";
	//std::cout << MultiplyChar(n3, n3.size() - 1, '8') << std::endl;
	//std::cout << n3 << std::endl;

	return 0;
}
