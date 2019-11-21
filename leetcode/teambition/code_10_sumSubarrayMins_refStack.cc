class Solution {
public:
    int sumSubarrayMins(vector<int>& A) {
		if (A.empty())
		{
			return 0;
		}
        long long sum = 0;
        stack<int> nums;
		//������ÿ��λ��Ϊ��Сֵ������� ��������Сֵ���ۼӺ� ������λ�ü��������Ǵ�
        for (int i = 0; i < A.size(); ++i)
        {
            while (!nums.empty() && A[nums.top()] > A[i])
            {
                nums.pop();
            }
            int left = nums.empty() ? -1 : nums.top();
            nums.push(i);
            int j = i + 1;
            while (j < A.size() && A[j] >= A[i]) { ++j; }
            sum += (i - left) * (j - i) * A[i];
        }
        return sum % 1000000007;
    }
};