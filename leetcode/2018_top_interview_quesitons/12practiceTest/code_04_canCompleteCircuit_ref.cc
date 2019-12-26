class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        //将问题转化为找最大子串的起始位置。
        int result = 0;
        int sum = 0;
        int hasResult = 0;//用于判断是否有跑完全程所需的油
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
                result = i;//要得到起点 如果能循环走下去 必然不会更新result 如果能走sum必然大于0
            }
        }
        return hasResult>=0? result:-1;
    }
};

//https://leetcode-cn.com/problems/gas-station/solution/javashi-jian-chao-98qi-shi-zhe-dao-ti-he-qiu-zui-d/