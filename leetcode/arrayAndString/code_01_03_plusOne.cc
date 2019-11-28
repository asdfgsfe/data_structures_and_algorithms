class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
		if (digits.empty())
		{
			return {};
		}
		vector<int> num(digits.size() + 1);
		num[0] = 0;
		for (int i = 0; i < digits.size(); ++i)
		{
			num[i + 1] = digits[i];
		}
		for (int i = num.size() - 1; i >= 0; --i)
		{
			int sum = num[i] + 1;
			num[i] = sum % 10;
			if (sum < 10)
			{
				break;
			}
		}
		return num[0] == 0 ? vector<int>(num.begin() + 1, num.end()) : num;
    }
};