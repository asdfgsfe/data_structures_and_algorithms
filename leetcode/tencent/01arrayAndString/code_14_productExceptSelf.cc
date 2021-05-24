 ��������������ĳ˻�
��������Ϊ n ���������� nums������ n > 1������������� output ��
���� output[i] ���� nums �г� nums[i] ֮�������Ԫ�صĳ˻���

ʾ��:

����: [1,2,3,4]
���: [24,12,8,6]
˵��: �벻Ҫʹ�ó��������� O(n) ʱ�临�Ӷ�����ɴ��⡣

���ף�
������ڳ����ռ临�Ӷ�����������Ŀ�𣿣� ���ڶԿռ临�Ӷȷ�����Ŀ�ģ�������鲻����Ϊ����ռ䡣��

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        if (nums.empty())
        {
            return {};
        }
        vector<int> product(nums.size());
        product[0] = 1;
        for (int i = 1; i < nums.size(); ++i)
        {
            product[i] = product[i - 1] * nums[i - 1];
        }
        int d = 1;
        for (int i = nums.size() - 2; i >= 0; --i)
        {
            d *= nums[i + 1];
            product[i] *= d;
        }
        return product;
    }
};


class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        if (nums.empty()) {
            return {};
        }
        vector<int> product(nums.size());
        product[0] = 1;
        for (int i = 1; i < nums.size(); ++i) {
            product[i] = product[i - 1] * nums[i - 1];
        }
        int tmp = 1;
        for (int i = nums.size() - 1; i >= 0; --i) {
            //ֱ�Ӵ�0��ʼ �����ȳ�tmp ��tmp��������
            product[i] *= tmp;
            tmp *= nums[i];
        }
        return product;
    }
};
