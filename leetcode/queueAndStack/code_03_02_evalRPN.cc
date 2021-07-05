//逆波兰表达式求值

//tokens题中给出的已经是一个后缀表达式了 所以可以直接计算
//如果不是后缀表达式有2中算法
//1.直接利用栈递归的算
//2.先将中坠表达式转换为后缀表达式 在计算
class Solution {
public:
	int evalRPN(vector<string>& tokens) {
		if (tokens.empty())
		{
			return 0;
		}
		stack<long long> nums;
		for (const string& token : tokens)
		{
			if (token != "+" && token != "-" && token != "*" && token != "/")
			{
				nums.push(::atoi(token.data()));
				continue;
			}
			vector<int> lr = GetOptNum(nums);
			assert(lr.size() == 2);
			if (token == "+")
			{
				nums.push(lr[0] + lr[1]);
			}
			else if (token == "-")
			{
				nums.push(lr[0] - lr[1]);
			}
			else if (token == "*")
			{
				nums.push(lr[0] * lr[1]);
			}
			else
			{
				nums.push(lr[0] / lr[1]);
			}
		}
		assert(nums.size() == 1);
		return nums.top();
	}

	vector<int> GetOptNum(stack<long long>& nums)
	{
		assert(nums.size() >= 2);
		int rhs = nums.top();
		nums.pop();
		int lhs = nums.top();
		nums.pop();
		return { lhs, rhs };
	}
};


//代码简化一点
class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        if (tokens.empty()) {
            return 0;
        }
        stack<int> nums;
        for (auto& token : tokens) {
            if (token == "-" || token == "+" || token == "*" || token == "/") {
                if (nums.size() < 2) {
                    return 0x7fffffff;
                }
                int r = nums.top();
                nums.pop();
                int l = nums.top();
                nums.pop();
                int n = token == "+" ? l + r : (token == "-" ? l - r : (token == "/" ? l / r : l * r));
                nums.emplace(n);
            } else {
                nums.emplace(::atoi(token.data()));
            }
        }
        return nums.empty() ? 0x7fffffff : nums.top();
    }
};
