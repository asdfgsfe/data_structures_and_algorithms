//����Ͱ����ѡ�� �ͽ���sort����ѡ���ԭ��һ��
class Solution {
public:
    int arrayPairSum(vector<int>& nums) {
        uint16_t hash[20001] = {0};
        uint16_t small = 20001;
		uint16_t large = 0;
        for(auto &e: nums)
        {
            e += 10000;
            hash[e]++;
            small = min(small, uint16_t(e));
            large = max(large, uint16_t(e));
        }
        bool add = 1;
        int ans = 0;
        
        while(small < large+1)
		{
            //������ֵ�����˶�� ��ôֻҪһ����� ���Ծ���add = 1- add
			if(hash[small]-->0)
			{
                ans += add*(small - 10000);
                add = 1-add;
            }
            else
                small++;
        }
        return ans;
    }
};