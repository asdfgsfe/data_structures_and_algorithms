class Solution {
public:
	//������ �����е������������мӼ��˳����� �ڴ˻����ϼ������� Ȼ���ܲ��ܸ����24
    bool judgePoint24(vector<int>& nums) {
        double eps = 0.001;
        vector<char> ops{'+', '-', '*', '/'};
        vector<double> arr(nums.begin(), nums.end());
        return helper(arr, ops, eps);
    }
    bool helper(vector<double>& nums, vector<char>& ops, double eps) {
        if (nums.size() == 1) 
		{
			//return nums[0] == 24.0;
            return abs(nums[0] - 24) < eps;
		}
        for (int i = 0; i < nums.size(); ++i) 
		{
            for (int j = 0; j < nums.size(); ++j) 
			{
                if (i == j) continue;
                vector<double> t; //������һ������������������������� �Ӽ��˳�����Ľ��
                for (int k = 0; k < nums.size(); ++k) 
				{
					//������˳��� ǰ�������� ��β��ڼ���
                    if (k != i && k != j) t.push_back(nums[k]);
                }
                for (char op : ops) 
				{
                    if ((op == '+' || op == '*') && i > j) continue;
                    if (op == '/' && nums[j] < eps) continue; //���� ��Ϊnums�е������ǼӼ��˳������������
                    switch(op) 
					{
                        case '+': t.push_back(nums[i] + nums[j]); break;
                        case '-': t.push_back(nums[i] - nums[j]); break;
                        case '*': t.push_back(nums[i] * nums[j]); break;
                        case '/': t.push_back(nums[i] / nums[j]); break;
                    }
                    if (helper(t, ops, eps)) return true;
                    t.pop_back();
                }
            }
        }
        return false;
    }
};



//�ȼ�¼��� ������ ����ȥ
class Solution {
public:
	bool judgePoint24(vector<int>& nums) {
		if (nums.size() != 4)
		{
			return false;
		}
		vector<double> values;
		for (int i = 0; i < nums.size(); ++i)
		{
			double num = nums[i];
			values.emplace_back(num);
			for (int j = i + 1; j < nums.size(); ++j)
			{
				
				values.emplace_back(num * nums[j]);
				values.emplace_back(num / nums[j]);
				values.emplace_back(num + nums[j]);
				values.emplace_back(num - nums[j]);
			}
			for (int j = i - 1; j >= 0; --j)
			{
				values.emplace_back(num / nums[j]);
				values.emplace_back(num - nums[j]);
			}
		}
		return JudgeProcess(values, 0, 24.0);
	}

	bool JudgeProcess(const vector<double>& nums, int i, double point)
	{
		if (std::abs(point - 0.0) < 0.001) //�о�����������
		{
			return true;
		}
		if (i == nums.size())
		{
			return false;
		}
		printf("i=%d, point=%f\n", i, point);
		if (nums[i] != 0.0)
		{
			return JudgeProcess(nums, i + 1, point / nums[i])
				|| JudgeProcess(nums, i + 1, point * nums[i])
				|| JudgeProcess(nums, i + 1, point + nums[i])
				|| JudgeProcess(nums, i + 1, point - nums[i])
				|| JudgeProcess(nums, i + 1, point);
		}
		return JudgeProcess(nums, i + 1, point * nums[i])
			|| JudgeProcess(nums, i + 1, point + nums[i])
			|| JudgeProcess(nums, i + 1, point - nums[i])
			|| JudgeProcess(nums, i + 1, point);
	}
};
