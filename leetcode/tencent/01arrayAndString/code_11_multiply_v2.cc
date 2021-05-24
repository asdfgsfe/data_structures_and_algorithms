class Solution {
public:    
    string multiply(const string& lhs, const string& rhs)
    {
	    if (lhs.empty() || rhs.empty())
	    {
		    return string();
	    }
	    string multi(lhs.size() + rhs.size() + 1, '0');
	    for (int j = rhs.size() - 1; j >= 0; --j)
	    {
		    string subM = MultiplyChar(lhs, lhs.size() - 1, rhs[j]);
		    subM += ZeroK(rhs.size() - 1 - j);
		    multi = Add(multi, subM);
	    }
	    return multi;
    }

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
        //return sum.substr(sum.find_first_not_of('0'));
        int zeroIdx = 0;
        while (zeroIdx < sum.size() && sum[zeroIdx] == '0')
        {
            ++zeroIdx;
        }
        if (zeroIdx == sum.size())
        {
            return "0";
        }
        return sum.substr(zeroIdx);
    }

    void AddChar(string& sum, int i, char c)
    {
	    for (int move = i; move >= 0; --move)
	    {
		    int cur = sum[move] - '0' + c - '0';
		    sum[move] = cur % 10 + '0';
			if (cur < 10)
			{
				break;
			}
			c = '1';
		}
    }
};
