 class Solution {
 public:
	 string fractionToDecimal(int numerator, int denominator) {
		 if (numerator == 0)
         {
             return string("0");
         }
         if (denominator == 0)
		 {
			 return string();
		 }
         bool minus = (numerator > 0) ^ (denominator > 0);
         long long num = std::labs(numerator); //注意绝对值的用法
         long long den = std::labs(denominator);
         string ans;
         if (minus)
         {
            ans.push_back('-');
         }
		 ans += std::to_string(num / den);
		 long long rest = num % den;
		 if (rest == 0)
		 {
			 return ans;
		 }
         ans.push_back('.');
		 int idx = ans.size();
		 unordered_map<long long, int> visited;
		 visited[rest] = idx - 1;
		 rest *= 10;
		 while (rest >= 10)
		 {
			 while (rest < den)
			 {
				 rest *= 10;
				 ans.push_back('0');
				 ++idx;
			 }
			 long long num = rest / den;
             ans.push_back(num + '0');
			 rest %= den;
             auto pos = visited.find(rest);
			 if (pos != visited.end())
			 {
                 string tmp(ans.substr(0, pos->second + 1));
				 tmp.push_back('(');
				 tmp += ans.substr(pos->second + 1, ans.size() - pos->second - 1);
				 tmp.push_back(')');
				 ans.swap(tmp);
				 break;
			 }
			 visited[rest] = idx++;
			 rest *= 10;
		 }
		 return ans;
	 }
 };