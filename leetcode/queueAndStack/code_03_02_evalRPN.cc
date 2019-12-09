//tokens���и������Ѿ���һ����׺���ʽ�� ���Կ���ֱ�Ӽ���
//������Ǻ�׺���ʽ��2���㷨
//1.ֱ������ջ�ݹ����
//2.�Ƚ���׹���ʽת��Ϊ��׺���ʽ �ڼ���
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