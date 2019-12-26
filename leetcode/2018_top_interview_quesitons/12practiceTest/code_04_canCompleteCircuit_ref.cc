class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        //������ת��Ϊ������Ӵ�����ʼλ�á�
        int result = 0;
        int sum = 0;
        int hasResult = 0;//�����ж��Ƿ�������ȫ���������
        for (int i = 0; i < gas.size(); i++) 
        {
            hasResult +=gas[i]-cost[i];
            if(sum > 0) 
            {
                sum += gas[i]-cost[i];
            } 
            else 
            {
                sum = gas[i]-cost[i];
                result = i;//Ҫ�õ���� �����ѭ������ȥ ��Ȼ�������result �������sum��Ȼ����0
            }
        }
        return hasResult>=0? result:-1;
    }
};

//https://leetcode-cn.com/problems/gas-station/solution/javashi-jian-chao-98qi-shi-zhe-dao-ti-he-qiu-zui-d/